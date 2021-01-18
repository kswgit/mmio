#define USE_STDPERIPH_DRIVER
#include "stm32f407xx.h"
#include "blake3.h"

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
	blake3_hasher hasher;
  blake3_hasher_init(&hasher);

  blake3_hasher_update(&hasher, "aaa", 4);

  // Finalize the hash. BLAKE3_OUT_LEN is the default output length, 32 bytes.
  uint8_t output[BLAKE3_OUT_LEN];
  blake3_hasher_finalize(&hasher, output, BLAKE3_OUT_LEN);

  RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
  __asm("dsb");
  GPIOD->MODER = 85 << 24;
   // Print the hash as hexadecimal.
  for (size_t i = 0; i < BLAKE3_OUT_LEN; i++) {
		if (output[i] < 10) {
    	GPIOD->ODR ^= (15 << 12);
		}	
    ms_delay(1000);
  }
	for (;;) {}
}
