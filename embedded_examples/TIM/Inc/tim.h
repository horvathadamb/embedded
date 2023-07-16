/*
 * tim.h
 *
 *  Created on: Jul 16, 2023
 *      Author: Adam
 */

#ifndef INC_TIM_H_
#define INC_TIM_H_
//*********************************************************
// Includes
//*********************************************************
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_tim.h"
#include "stdint.h"
//*********************************************************
// Global Defines
//*********************************************************
//remove comment from Core/Inc/stm32f4xx_hal_conf.h #define HAL_TIM_MODULE_ENABLED
TIM_HandleTypeDef TIM11_HandleStruct;
/* to fix linker error: https://stackoverflow.com/questions/71409313/stm-cubeide-1-9-0-has-linker-issues
 * In Project > Properties > C/C++ build > Settings >
 * gcc compiler > miscellaneous > Other flags,
 * try adding -fcommon
 */
//*********************************************************
// Type definitions
//*********************************************************
typedef enum{
	TIM_ERROR_TEST = 6,
	TIM_ERROR_INIT = 1,
	TIM_ERROR_START = 2,
}tim_error_e;
//*********************************************************
// Function prototypes
//*********************************************************
void TIM_Error_Handler(tim_error_e TIM_Error);

void TIM11_UPCOUNT_Init(void);
void TIM11_Start(void);
//*********************************************************
#endif /* INC_TIM_H_*/
