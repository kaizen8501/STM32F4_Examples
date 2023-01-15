/*
 * TwRingBuffer.h
 *
 *  Created on: Jan 13, 2023
 *      Author: kaizen
 */

#ifndef APP_COMMONUTILS_TWRINGBUFFER_H_
#define APP_COMMONUTILS_TWRINGBUFFER_H_

#include "common.h"

typedef struct
{
    uint8_t *BUFF;
    uint16_t HEAD;
    uint16_t TAIL;
    uint16_t SIZE;
} TW_RING_BUFFER_t;

bool TwRingBufferInit       (TW_RING_BUFFER_t *ringBuffer, uint8_t *buffer, uint32_t size);
bool TwRingBufferDeinit     (TW_RING_BUFFER_t *ringBuffer);

uint32_t TwRingBufferWrite      (TW_RING_BUFFER_t *ringBuffer, const uint8_t *data, uint32_t dataLength);
uint16_t TwRingBufferGetData    (TW_RING_BUFFER_t *ringBuffer, uint8_t **data, uint16_t dataSize);
uint32_t TwRingBufferFreeSpace  (TW_RING_BUFFER_t *ringBuffer);
uint32_t TwRingBufferUsedSpace  (TW_RING_BUFFER_t *ringBuffer);

#endif /* APP_COMMONUTILS_TWRINGBUFFER_H_ */
