#include <stdint.h>
#include <stdlib.h>

#include "stm32f4/gpio.h"
#include "stm32f4/rcc.h"
#include "bit_operations.h"

uint32_t const GPIOA_BASEADDR = AHB1PERIPH_BASEADDR + GPIOA_ADDR_OFFSET;
uint32_t const GPIOB_BASEADDR = AHB1PERIPH_BASEADDR + GPIOB_ADDR_OFFSET;
uint32_t const GPIOC_BASEADDR = AHB1PERIPH_BASEADDR + GPIOC_ADDR_OFFSET;
uint32_t const GPIOD_BASEADDR = AHB1PERIPH_BASEADDR + GPIOD_ADDR_OFFSET;
uint32_t const GPIOE_BASEADDR = AHB1PERIPH_BASEADDR + GPIOE_ADDR_OFFSET;
uint32_t const GPIOF_BASEADDR = AHB1PERIPH_BASEADDR + GPIOF_ADDR_OFFSET;
uint32_t const GPIOG_BASEADDR = AHB1PERIPH_BASEADDR + GPIOG_ADDR_OFFSET;
uint32_t const GPIOH_BASEADDR = AHB1PERIPH_BASEADDR + GPIOH_ADDR_OFFSET;
uint32_t const GPIOI_BASEADDR = AHB1PERIPH_BASEADDR + GPIOI_ADDR_OFFSET;

uint8_t const GPIO_INPUT_MODE = 0x0;
uint8_t const GPIO_OUTPUT_MODE = 0x1;
uint8_t const GPIO_ALTERNATE_FUNCTION_MODE = 0x2;
uint8_t const GPIO_ANALOG_MODE = 0x3;

uint8_t const GPIO_NO_PULL_UP_DOWN = 0x0;
uint8_t const GPIO_PULL_UP = 0x1;
uint8_t const GPIO_PULL_DOWN = 0x2;
//uint8_t const RESERVED = 0x3;


GPIOx GPIOA = (GPIOx)GPIOA_BASEADDR;
GPIOx GPIOB = (GPIOx)GPIOB_BASEADDR;
GPIOx GPIOC = (GPIOx)GPIOC_BASEADDR;
GPIOx GPIOD = (GPIOx)GPIOD_BASEADDR;
GPIOx GPIOE = (GPIOx)GPIOE_BASEADDR;
GPIOx GPIOF = (GPIOx)GPIOF_BASEADDR;
GPIOx GPIOG = (GPIOx)GPIOG_BASEADDR;
GPIOx GPIOH = (GPIOx)GPIOH_BASEADDR;
GPIOx GPIOI = (GPIOx)GPIOI_BASEADDR;

static uint8_t get_GPIOx_offset_in_RCC_AHB1_register(GPIOx port)
{
    uint8_t offset;
    if (port == GPIOA)
        offset = 0;
    else if (port == GPIOB)
        offset = 1;
    else if (port == GPIOC)
        offset = 2;
    else if (port == GPIOD)
        offset = 3;
    else if (port == GPIOE)
        offset = 4;
    else if (port == GPIOF)
        offset = 5;
    else if (port == GPIOG)
        offset = 6;
    else if (port == GPIOH)
        offset = 7;
    else if (port == GPIOI)
        offset = 8;
    else
        exit(EXIT_FAILURE);  /* No such GPIO port */

    return offset;
}

void enable_GPIOx_clock(GPIOx port)
{
    uint32_t offset = get_GPIOx_offset_in_RCC_AHB1_register(port);
    uint32_t *pAHB1ENR = (uint32_t *)AHB1ENR;
    SET_BIT(*pAHB1ENR, offset);
}

void reset_GPIOx(GPIOx port)
{
    uint32_t offset = get_GPIOx_offset_in_RCC_AHB1_register(port);
    uint32_t *pAHB1RSTR = (uint32_t *)AHB1RSTR;
    CLEAR_BIT(*pAHB1RSTR, offset);
}

void set_GPIOx_pin_mode(uint8_t mode, uint8_t pin, GPIOx port)
{
    port->mode &= ~(0x3 << (pin * 2));
    port->mode |= mode << (pin * 2);
}

void set_GPIOx_port_mode(uint8_t mode, GPIOx port)
{
    // 0x55555555 means combination `01` 16 times that fits 32bits register
    // if we multiply this num by `mode`, we will get the same mode value for every pin
    port->mode &= ~((uint32_t)0x55555555 * 0x3);
    port->mode |= 0x55555555 * mode;
}

void set_GPIOx_pin_pull_up_down_mode(uint8_t mode, uint8_t pin, GPIOx port)
{
    port->pull_up_down &= ~(0x3 << (pin * 2));
    port->pull_up_down |= mode << (pin * 2);
}

void set_GPIOx_port_pull_up_down_mode(uint8_t mode, uint16_t pin, GPIOx port)
{
    // 0x55555555 means combination `01` 16 times that fits 32bits register
    // if we multiply this num by `mode`, we will get the same mode value for every pin
    port->pull_up_down &= ~((uint32_t)0x55555555 * 0x3);
    port->pull_up_down |= 0x55555555 * mode;
}

void write_into_GPIOx_pin(uint8_t data, uint8_t pin, GPIOx port)
{
    if (GET_BIT(data, 0))
        SET_BIT(port->output_data, pin);
    else
        CLEAR_BIT(port->output_data, pin);
}

void write_into_GPIOx_port(uint16_t data, GPIOx port)
{
    port->output_data &= ~(0xf);
    port->output_data |= data;
}

uint8_t read_from_GPIOx_pin(uint8_t pin, GPIOx port)
{
    return (uint8_t)GET_BIT(port->input_data, pin);
}

uint16_t read_from_GPIOx_port(GPIOx port)
{
    return port->input_data;
}
