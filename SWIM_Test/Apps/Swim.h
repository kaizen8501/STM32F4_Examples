/*
 * Swim.h
 *
 *  Created on: Jan 15, 2023
 *      Author: kaizen
 */

#ifndef SWIM_H_
#define SWIM_H_

#include "common.h"

#ifndef SWIM_IN_Pin
#define SWIM_IN_Pin	GPIO_PIN_8
#endif

#ifndef SWIM_IN_GPIO_Port
#define SWIM_IN_GPIO_Port GPIOA
#endif

#ifndef SWIM_OUT_Pin
#define SWIM_OUT_Pin GPIO_PIN_14
#endif

#ifndef SWIM_OUT_GPIO_Port
#define SWIM_OUT_GPIO_Port GPIOB
#endif

#ifndef SWIM_RESET_Pin
#define SWIM_RESET_Pin GPIO_PIN_15
#endif

#ifndef SWIM_RESET_GPIO_Port
#define SWIM_RESET_GPIO_Port GPIOB
#endif

#define SWIM_NACK_MAX     100	//maximum number of NACKS in ROTF and WOTF
#define SWIM_DELAY_MAX    (1000*24)	//1ms
#define SWIM_BUF_SIZE     32	//input capture DMA buffer
#define SWIM_LONG_DELAY() {__NOP(); __NOP(); __NOP(); __NOP();}	//used for long bit delay

/* swim_data
 * structure that holds data used globally in this file
 * primary use is interfacing interrupt routine and main program
 */
struct {
    uint32_t result;	//received bits
    uint32_t to_listen;	//expected bits, has to be less than SWIM_BUF_SIZE
    uint32_t done;	//true when job is done by interrupt routine
    uint16_t low[SWIM_BUF_SIZE];	//DMA target buffer
    uint32_t bit_sync;//limit length of short pulse and 1, used when determining bit value
} swim_data;

#define SWIM_ERR_OK           0
#define SWIM_ERR_SYNC         1
#define SWIM_ERR_FIRST_WRITE  2
#define SWIM_ERR_HEADER       3
#define SWIM_ERR_HEADER_NACK  4
#define SWIM_ERR_BWRITE       5
#define SWIM_ERR_BWRITE_NACK  6
#define SWIM_ERR_WRITE        9
#define SWIM_ERR_READ         10
#define SWIM_ERR_DELAY        11

#define SWIM_SRST        0x00
#define SWIM_ROTF        0x03
#define SWIM_WOTF        0x05

#define SWIM_CSR               0x7F80
#define SWIM_FLASH             0x00505a
#define SWIM_PROGRAM           0x008000
#define SWIM_FLASH_CR1         (SWIM_FLASH + 0x00)
#define SWIM_FLASH_CR2         (SWIM_FLASH + 0x01)
#define SWIM_FLASH_NCR2        (SWIM_FLASH + 0x02)
#define SWIM_FLASH_FPR         (SWIM_FLASH + 0x03)
#define SWIM_FLASH_NFPR        (SWIM_FLASH + 0x04)
#define SWIM_FLASH_IAPSR       (SWIM_FLASH + 0x05)
#define SWIM_FLASH_PUKR        (SWIM_FLASH + 0x08)
#define SWIM_FLASH_DUKR        (SWIM_FLASH + 0x0a)
#define SWIM_FLASH_PUKR_KEY1   0x56
#define SWIM_FLASH_PUKR_KEY2   0xae
#define SWIM_FLASH_DUKR_KEY1   0xae
#define SWIM_FLASH_DUKR_KEY2   0x56

uint32_t SWIM_Init(void);





uint32_t SWIM_SystemReset(void);
uint32_t SWIM_WriteOnTheFly(uint8_t n, uint32_t address, uint8_t *pData);
uint32_t SWIM_ReadOnTheFly(uint8_t n, uint32_t address, uint8_t *pData);

void        SWIM_ListenTo(uint32_t number);
uint32_t    SWIM_SendHeader(uint8_t header);
uint32_t    SWIM_SendByte(uint8_t byte);

#endif /* SWIM_H_ */
