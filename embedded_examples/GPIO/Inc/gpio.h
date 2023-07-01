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
// Type definitions
//*********************************************************

//*********************************************************
// Function prototypes
//*********************************************************
void GPIO_LED_Init(void);
void GPIO_Toggle_LED(void);
void GPIO_TEST_PIN_Init(void);
void GPIO_Toggle_TEST_PIN(void);
//*********************************************************
#endif /* EXAMPLES_GPIO_INC_GPIO_H_ */
