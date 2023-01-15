/*
 * ConsoleUart.c
 *
 *  Created on: Jan 14, 2023
 *      Author: kaizen
 */

#include "ConsoleUart.h"
#include "TwRingBuffer.h"
#include "usart.h"

extern UART_HandleTypeDef huart2;
extern DMA_HandleTypeDef hdma_usart2_rx;

#define CONSOLE_RX_RING_BUFF_SIZE	DMA_RX_BUFF_SIZE * 2

uint8_t CONSOLE_RX_RING_BUFF[CONSOLE_RX_RING_BUFF_SIZE];

TW_RING_BUFFER_t CONSOLE_RX_RING_BUFF_OBJ;

#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
//#define GETCHAR_PROTOTYPE int __io_getchar(void)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
//#define GETCHAR_PROTOTYPE int fgetc(FILE *f)
#endif

PUTCHAR_PROTOTYPE
{
    HAL_UART_Transmit (&huart2, (uint8_t*) &ch, 1, 0xFFFF);
    return ch;
}

void ConsoleUartInit (void)
{
    TwRingBufferInit (&CONSOLE_RX_RING_BUFF_OBJ, CONSOLE_RX_RING_BUFF, sizeof(CONSOLE_RX_RING_BUFF));
}

bool ConsoleUartRxDataExist (void)
{
    if (TwRingBufferUsedSpace (&CONSOLE_RX_RING_BUFF_OBJ) > 0)
    {
        return true;
    }

    return false;
}

uint8_t ConsoleUartGetCh (void)
{
    uint8_t *data;

    if (ConsoleUartRxDataExist () == true)
    {
        TwRingBufferGetData (&CONSOLE_RX_RING_BUFF_OBJ, &data, 1);
    }

    return data[0];
}

void ConsoleUartRxEventCallBack (uint8_t *data, uint16_t size)
{
    if (TwRingBufferFreeSpace (&CONSOLE_RX_RING_BUFF_OBJ) < size)
    {
        TRACE_WARN("Buffer Overflow. Need Flow Control");
    }
    else
    {
        TwRingBufferWrite (&CONSOLE_RX_RING_BUFF_OBJ, data, size);
    }
}

