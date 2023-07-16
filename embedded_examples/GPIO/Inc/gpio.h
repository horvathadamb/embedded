/*
 * gpio.h
 *
 *  Created on: 2023. júl. 1.
 *      Author: Adam
 */


//*********************************************************
// Includes
//*********************************************************

#ifndef EXAMPLES_GPIO_INC_GPIO_H_
#define EXAMPLES_GPIO_INC_GPIO_H_
#include "stm32f4xx_hal.h"
#include "stdint.h"
#include "stdio.h"
//*********************************************************
// Global Defines
//*********************************************************
#define USER_GPIO_LED_PIN	GPIO_PIN_5
#define USER_GPIO_LED_PORT	GPIOA

#define USER_GPIO_TEST_PIN	GPIO_PIN_8
#define USER_GPIO_TEST_PORT	GPIOC

#define USER_GPIO_BUTTON_PIN GPIO_PIN_13
#define USER_GPIO_BUTTON_PORT GPIOC
//*********************************************************
// Type definitions
//*********************************************************
typedef enum {
	GPIO_ERROR_TEST = 5,
}gpio_error_e;
//*********************************************************
// Function prototypes
//*********************************************************
void GPIO_LED_Init(void);
void GPIO_Toggle_LED(void);
void GPIO_TEST_PIN_Init(void);
void GPIO_Toggle_TEST_PIN(void);
void GPIO_BUTTON_Init(void);
void GPIO_Button_It_Init(void);

void EXTI15_10_IRQHandler(void);
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);

void GPIO_Error_Handler(gpio_error_e GPIO_Error);
//*********************************************************
#endif /* EXAMPLES_GPIO_INC_GPIO_H_ */
