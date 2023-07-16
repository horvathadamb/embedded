/*
 * tim.c
 *
 *  Created on: Jul 16, 2023
 *      Author: Adam
 */


//*********************************************************
// Includes
//*********************************************************
#include "tim.h"

//*********************************************************
// Local Defines
//*********************************************************

//*********************************************************
// Defines
//*********************************************************

//*********************************************************
// Type definitions
//*********************************************************

//*********************************************************
// Function definitions
//*********************************************************

void TIM_Error_Handler(tim_error_e TIM_Error){
	uint8_t Error;
	while(1){
		// Error loop
		Error = TIM_Error;
	}
}

void TIM11_UPCOUNT_Init(void){
	__HAL_RCC_TIM11_CLK_ENABLE();

	TIM11_HandleStruct.Instance = TIM11;
	TIM11_HandleStruct.Init.Prescaler = 0;
	TIM11_HandleStruct.Init.CounterMode = TIM_COUNTERMODE_UP;
	TIM11_HandleStruct.Init.Period = 65535;
	TIM11_HandleStruct.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	TIM11_HandleStruct.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if(HAL_TIM_Base_Init(&TIM11_HandleStruct) != HAL_OK){
		TIM_Error_Handler(TIM_ERROR_INIT);
	};

}

void TIM11_Start(void){
	if(HAL_TIM_Base_Start(&TIM11_HandleStruct) != HAL_OK){
		TIM_Error_Handler(TIM_ERROR_START);
	};
}

