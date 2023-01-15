/*
 * ConsoleUart.h
 *
 *  Created on: Jan 14, 2023
 *      Author: kaizen
 */

#ifndef CONSOLEUART_H_
#define CONSOLEUART_H_

#include "common.h"

void 	ConsoleUartInit				(void);
bool 	ConsoleUartRxDataExist		(void);
uint8_t ConsoleUartGetCh			(void);
void 	ConsoleUartRxEventCallBack	(uint8_t *data, uint16_t size);


#endif /* CONSOLEUART_H_ */
