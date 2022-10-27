#ifndef _STM32F4_GPIO_H
#define _STM32F4_GPIO_H

#include <stdint.h>

#include "stm32f4/general.h"
#include "stm32f4/rcc.h"


#define GPIOx_PIN_COUNT 16

typedef struct {
    volatile uint32_t mode;
    volatile uint32_t output_type;
    volatile uint32_t output_speed;
    volatile uint32_t pull_up_down;
    volatile uint32_t input_data;
    volatile uint32_t output_data;
    volatile uint32_t bit_set_reset;
    volatile uint32_t config_lock;
    volatile uint32_t alternate_function_low;
    volatile uint32_t alternate_function_high;
} GPIOx_regs;

typedef volatile GPIOx_regs *const GPIOx;

extern GPIOx GPIOA;
extern GPIOx GPIOB;
extern GPIOx GPIOC;
extern GPIOx GPIOD;
extern GPIOx GPIOE;
extern GPIOx GPIOF;
extern GPIOx GPIOG;
extern GPIOx GPIOH;
extern GPIOx GPIOI;

extern uint8_t const GPIO_INPUT_MODE;
extern uint8_t const GPIO_OUTPUT_MODE;
extern uint8_t const GPIO_ALTERNATE_FUNCTION_MODE;
extern uint8_t const GPIO_ANALOG_MODE;

extern uint8_t const GPIO_NO_PULL_UP_DOWN;
extern uint8_t const GPIO_PULL_UP;
extern uint8_t const GPIO_PULL_DOWN;

void enable_GPIOx_clock(GPIOx port);
void reset_GPIOx(GPIOx port);
void set_GPIOx_pin_mode(uint8_t mode, uint8_t pin, GPIOx port);
void set_GPIOx_port_mode(uint8_t mode, GPIOx port);
//void set_GPIOx_pin_pull_up_down_mode(uint8_t mode, uint8_t pin, GPIOx port);
//void set_GPIOx_port_pull_up_down_mode(uint8_t mode, uint16_t pin, GPIOx port);
void write_into_GPIOx_pin(uint8_t data, uint8_t pin, GPIOx port);
void write_into_GPIOx_port(uint16_t data, GPIOx port);
uint8_t read_from_GPIOx_pin(uint8_t pin, GPIOx port);
uint16_t read_from_GPIOx_port(GPIOx port);

#endif /* _STM32F4_GPIO_H */
