#include "led.h"
#include <stdio.h>
#include "stm32f4xx.h"  // Include your specific microcontroller header file
volatile uint32_t msTicks = 0; // Variable to store millisecond ticks
// Function prototypes
void SysTick_Init(void);
void SysTick_Handler(void);
void SysTick_Init(void) {
    // Configure SysTick to interrupt every 1 ms
    if (SysTick_Config(SystemCoreClock / 1000)) {
        // Handle error
        while (1);
    }
}

void SysTick_Handler(void) {
    msTicks++; // Increment millisecond tick count
}
Led_Type led1;
Led_Type led2;

int main(void){
	 SysTick_Init();
  USART2_Init();
	Led_ctor(&led1,GREEN,OFF);
	Led_ctor(&led2,BLUE,ON);
	
//	Led_getState(&led1);
//	Led_getState(&led2);
//	
	Led_setState(&led1,ON);
//	
	
	
	
	while(1){
		if(msTicks>1000){
			msTicks = 0;
			Led_toggleState(&led1);
		}
		
	}
}