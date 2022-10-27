#include <stdint.h>
#include <stdio.h>

#include "stm32f4/gpio.h"
#include "bit_operations.h"
#include "misc.h"


#if !defined(__SOFT_FP__) && defined(__ARM_FP)
    #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

void dot(uint32_t pin)
{
	write_into_GPIOx_pin(1, pin, GPIOD);
	sleep_dot(1);
	write_into_GPIOx_pin(0, pin, GPIOD);
}

void dash(uint32_t pin)
{
	write_into_GPIOx_pin(1, pin, GPIOD);
	sleep_dot(3);
	write_into_GPIOx_pin(0, pin, GPIOD);
}

int main(void)
{
    enable_GPIOx_clock(GPIOD);

    set_GPIOx_pin_mode(GPIO_OUTPUT_MODE, 12, GPIOD); //зелений
    set_GPIOx_pin_mode(GPIO_OUTPUT_MODE, 13, GPIOD); //оранжевий
    set_GPIOx_pin_mode(GPIO_OUTPUT_MODE, 14, GPIOD); //червоний
    set_GPIOx_pin_mode(GPIO_OUTPUT_MODE, 15, GPIOD); //синій
    while(1)
    {
    	write_into_GPIOx_pin(1, 12, GPIOD);
    	sleep_s(1);
    	write_into_GPIOx_pin(1, 13, GPIOD);
    	sleep_s(1);
    	write_into_GPIOx_pin(1, 14, GPIOD);
    	sleep_s(1);
    	write_into_GPIOx_pin(1, 15, GPIOD);
    	sleep_s(1);
    	write_into_GPIOx_pin(0, 15, GPIOD);
    	sleep_s(1);
    	write_into_GPIOx_pin(0, 14, GPIOD);
    	sleep_s(1);
    	write_into_GPIOx_pin(0, 13, GPIOD);
    	sleep_s(1);
    	write_into_GPIOx_pin(0, 12, GPIOD);
    	sleep_s(1);




//    	//c
//    	dash(12);
//    	sleep_dot(1);
//    	dot(12);
//    	sleep_dot(1);
//    	dash(12);
//    	sleep_dot(1);
//    	dot(12);
//
//    	sleep_dot(3);
//    	//o
//    	dash(13);
//		sleep_dot(1);
//		dash(13);
//		sleep_dot(1);
//		dash(13);
//
//		sleep_dot(3);
//    	//t
//		dash(14);
//
//		sleep_dot(3);
//    	//t
//		dash(15);
//
//		sleep_dot(3);
//    	//o
//		dash(12);
//		sleep_dot(1);
//		dash(12);
//		sleep_dot(1);
//		dash(12);
//
//		sleep_dot(3);
//    	//n
//		dash(13);
//		sleep_dot(1);
//		dot(13);
//
//		sleep_dot(7);
//		//7
//		dash(14);
//		sleep_dot(1);
//		dash(14);
//		sleep_dot(1);
//		dot(14);
//		sleep_dot(1);
//		dot(14);
//		sleep_dot(1);
//		dot(14);
//		sleep_dot(1);
//
//		sleep_dot(3);
//		//3
//		dot(15);
//		sleep_dot(1);
//		dot(15);
//		sleep_dot(1);
//		dot(15);
//		sleep_dot(1);
//		dash(15);
//		sleep_dot(1);
//		dash(15);


    }


}
