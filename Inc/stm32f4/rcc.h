#ifndef _STM32F4_RCC_H
#define _STM32F4_RCC_H

#include <stdint.h>

#include "stm32f4/general.h"

//#define CR RCC_BASEADDR
//#define PLLCFGR (RCC_BASEADDR + 0x04)
//#define CFGR (RCC_BASEADDR + 0x08)
//#define CIR (RCC_BASEADDR + 0x0C)
#define AHB1RSTR (RCC_BASEADDR + 0x10)
//#define AHB2RSTR (RCC_BASEADDR + 0x14)
//#define AHB3RSTR (RCC_BASEADDR + 0x18)
//
//#define APB1RSTR (RCC_BASEADDR + 0x20)
//#define APB2RSTR (RCC_BASEADDR + 0x24)

#define AHB1ENR (RCC_BASEADDR + 0x30)
//#define AHB2ENR (RCC_BASEADDR + 0x34)
//#define AHB3ENR (RCC_BASEADDR + 0x38)
//
//#define APB1ENR (RCC_BASEADDR + 0x40)
//#define APB2ENR (RCC_BASEADDR + 0x44)
//
//#define AHB1LPENR (RCC_BASEADDR + 0x50)
//#define AHB2LPENR (RCC_BASEADDR + 0x54)
//#define AHB3LPENR (RCC_BASEADDR + 0x58)
//
//#define APB1LPENR (RCC_BASEADDR + 0x60)
//#define APB2LPENR (RCC_BASEADDR + 0x64)
//
//#define BDCR (RCC_BASEADDR + 0x70)
//#define CSR (RCC_BASEADDR + 0x74)
//
//#define SSCGR (RCC_BASEADDR + 0x80)
//#define PLLI2SCFGR (RCC_BASEADDR + 0x84)
//#define PLLSAICFGR (RCC_BASEADDR + 0x88)
//#define DCKCFGR (RCC_BASEADDR + 0x8C)

#endif /* _STM32F4_RCC_H */
