/*
 * ConsoleTask.c
 *
 *  Created on: Jan 14, 2023
 *      Author: kaizen
 */
#include "ConsoleTask.h"
#include "ConsoleUart.h"

osThreadId_t ConsoleTaskHandle;

const osThreadAttr_t ConsoleTask_attributes = {
  .name = "ConsoleTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};


void CreateConsoleTask(void)
{
	ConsoleTaskHandle = osThreadNew(StartConsoleTask, NULL, &ConsoleTask_attributes);
}


void StartConsoleTask(void *argument)
{
	uint8_t ch;

	ConsoleUartInit();


	/* Infinite loop */
	for(;;)
	{
		osDelay(10);

		if (ConsoleUartRxDataExist() == false)
		{
			continue;
		}

		ch = ConsoleUartGetCh();
		switch (ch)
		{
			case '1':
				TRACE_DEBUG("SWIT Entry Sequence");
				break;
			default:
				break;
		}
	}
  /* USER CODE END StartIdleTask */
}
