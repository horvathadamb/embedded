/*
 * gpio.c
 *
 *  Created on: 2023. júl. 1.
 *      Author: Adam
 */


//*********************************************************
// Includes
//*********************************************************
#include "gpio.h"
//*********************************************************
// Local Defines
//*********************************************************

//*********************************************************
// Type definitions
//*********************************************************

//*********************************************************
// Function definitions
//*********************************************************


void GPIO_LED_Init(void){
	__HAL_RCC_GPIOA_CLK_ENABLE();

	GPIO_InitTypeDef GPIO_InitStruct =  {0};
	GPIO_InitStruct.Pin = USER_GPIO_LED_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(USER_GPIO_LED_PORT, &GPIO_InitStruct);
}

void GPIO_TEST_PIN_Init(void){
	__HAL_RCC_GPIOC_CLK_ENABLE();

	GPIO_InitTypeDef GPIO_InitStruct =  {0};
	GPIO_InitStruct.Pin = USER_GPIO_TEST_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(USER_GPIO_TEST_PORT, &GPIO_InitStruct);
}

void GPIO_BUTTON_Init(void){
	__HAL_RCC_GPIOC_CLK_ENABLE();

	GPIO_InitTypeDef GPIO_Initstruct = {0};
	GPIO_Initstruct.Pin = USER_GPIO_BUTTON_PIN;
	GPIO_Initstruct.Mode = GPIO_MODE_INPUT;
	GPIO_Initstruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(USER_GPIO_BUTTON_PORT, &GPIO_Initstruct);
}

void GPIO_Button_It_Init(void){
	__disable_irq();
	__HAL_RCC_GPIOC_CLK_ENABLE();

	GPIO_InitTypeDef GPIO_Initstruct = {0};
	GPIO_Initstruct.Mode = GPIO_MODE_IT_FALLING;
	GPIO_Initstruct.Pin = USER_GPIO_BUTTON_PIN;
	GPIO_Initstruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(USER_GPIO_BUTTON_PORT, &GPIO_Initstruct);

	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

	__enable_irq();
}

void GPIO_Toggle_LED(void){
	HAL_GPIO_TogglePin(USER_GPIO_LED_PORT, USER_GPIO_LED_PIN);
}

void GPIO_Toggle_TEST_PIN(void){
	HAL_GPIO_TogglePin(USER_GPIO_TEST_PORT, USER_GPIO_TEST_PIN);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	if(GPIO_Pin == USER_GPIO_BUTTON_PIN){
		GPIO_Toggle_LED();
	}
	else{
		__NOP();
	}
}

void EXTI15_10_IRQHandler(void){
	// Name in: @file      startup_stm32f411xe.s
	HAL_GPIO_EXTI_IRQHandler(USER_GPIO_BUTTON_PIN);
}

void GPIO_Error_Handler(gpio_error_e GPIO_Error){
	uint8_t Error;
	while(1){
		// Error loop
		Error = GPIO_Error;
	}
}
