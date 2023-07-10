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

//*********************************************************
// Function prototypes
//*********************************************************
void GPIO_LED_Init(void);
void GPIO_Toggle_LED(void);
void GPIO_TEST_PIN_Init(void);
void GPIO_Toggle_TEST_PIN(void);
void GPIO_BUTTON_Init(void);
//*********************************************************
#endif /* EXAMPLES_GPIO_INC_GPIO_H_ */
