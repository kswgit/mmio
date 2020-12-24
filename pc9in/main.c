#define USE_STDPERIPH_DRIVER
#include "stm32f407xx.h"

/*
GPIOx_MODER:GPIO port mode register
GPIOx_OTYPER:GPIO output type register
GPIOx_OSPEEDR:GPIO output speed register
GPIOx_PUPDR:GPIO port pull-up / pull-down register
GPIOx_IDR:GPIO port input data register
GPIOx_ODR:GPIO port output data register
GPIOx_BSRR:GPIIO port it set / reset register
GPIOx_LCKR:GPIO port configuration lock register
GPIOx_AFRL:GPIO alternate function low register
GPIOx_AFRH:GPIO alternate function high register
GPIOx_ASCR:GPIO port analog switch control register
*/

void _exit(int i) {
    while(1) {
        // Loop until reset
    }
}

void main(void)
{
  //RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
  //__asm("dsb");
  // 0000 0000 0101 0101 0101 0101 0101 0101 = 0x555555
  // 00: input
  // 01: output
  // 10: alternate
  // 11: reserved
  GPIOC->MODER = 0x555555;
  // 1010 1010 1010 1010 1010 1010 1010 1010 = 0xAAAAAAAA
  // 00: N/A
  // 01: PU
  // 10: PD
  // 11: Reserved
  GPIOC->PUPDR = 0xAAAAAAAA;
  for (;;) {
    // GPIC_15
    // 1000 0000 0000 0000
    int gpic15 = GPIOC->IDR >> 15;

    if (gpic15 == 1) {
      break;  
    }
  }
}
