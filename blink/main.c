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

void __attribute__ ((noinline)) ms_delay(int ms){
    while (ms-- > 0) {
        volatile int x=5971;
        while (x-- > 0) ("nop");
    }
    asm(""); //avoid inline optimization
}
 
int main(void)
{
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
  __asm("dsb");
  GPIOD->MODER = 85 << 24;
  for (;;) {
    GPIOD->ODR ^= (15 << 12);
    ms_delay(1000);
  }
}
