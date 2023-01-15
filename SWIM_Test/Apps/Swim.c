/*
 * Swim.c
 *
 *  Created on: Jan 15, 2023
 *      Author: kaizen
 */
#include "Swim.h"

uint32_t SWIM_Init(void)
{
    // Do Entry Sequence

}




void SWIM_OutPinSet(void)
{
    HAL_GPIO_WritePin(SWIM_OUT_GPIO_Port, SWIM_OUT_Pin, GPIO_PIN_SET);
}

void SWIM_OutPinReset(void)
{
    HAL_GPIO_WritePin(SWIM_OUT_GPIO_Port, SWIM_OUT_Pin, GPIO_PIN_RESET);
}

// Active Low
void SWIM_ResetAssert(void)
{
    HAL_GPIO_WritePin(SWIM_RESET_GPIO_Port, SWIM_RESET_Pin, GPIO_PIN_RESET);
}

void SWIM_ResetDeassert(void)
{
    HAL_GPIO_WritePin(SWIM_RESET_GPIO_Port, SWIM_RESET_Pin, GPIO_PIN_SET);
}

uint32_t swim_entry_sequence(void)
{
    return 0;
}






