/*
 * TwRingBuffer.c
 *
 *  Created on: Jan 13, 2023
 *      Author: kaizen
 */
#include "TwRingBuffer.h"

bool TwRingBufferInit (TW_RING_BUFFER_t *ringBuffer, uint8_t *buffer, uint32_t size)
{
    ringBuffer->BUFF = (uint8_t*) buffer;
    ringBuffer->SIZE = size;
    ringBuffer->HEAD = 0;
    ringBuffer->TAIL = 0;

    return true;
}

bool TwRingBufferDeinit (TW_RING_BUFFER_t *ringBuffer)
{
    return true;
}

uint32_t TwRingBufferWrite (TW_RING_BUFFER_t *ringBuffer, const uint8_t *data,
                   uint32_t dataLength)
{
    uint32_t tailToEnd = ringBuffer->SIZE - ringBuffer->TAIL;
    uint32_t amountToCopy = MIN(
            dataLength, (tailToEnd + ringBuffer->HEAD - 1) % ringBuffer->SIZE);

    memcpy (&ringBuffer->BUFF[ringBuffer->TAIL], data,
            MIN(amountToCopy, tailToEnd));

    if (tailToEnd < amountToCopy)
        {
            memcpy (&ringBuffer->BUFF[0], data + tailToEnd,
                    amountToCopy - tailToEnd);
        }

    ringBuffer->TAIL = (ringBuffer->TAIL + amountToCopy) % ringBuffer->SIZE;

    return amountToCopy;
}

uint16_t TwRingBufferGetData (TW_RING_BUFFER_t *ringBuffer, uint8_t **data,
                     uint16_t dataSize)
{
    uint16_t contigousBytes;
    uint16_t recvedLength;
    uint32_t headToEnd = ringBuffer->SIZE - ringBuffer->HEAD;

    *data = &ringBuffer->BUFF[ringBuffer->HEAD];

    contigousBytes = MIN(headToEnd, (headToEnd + ringBuffer->TAIL) % ringBuffer->SIZE);

    if (dataSize < contigousBytes)
    {
        ringBuffer->HEAD = (ringBuffer->HEAD + dataSize) % ringBuffer->SIZE;
        recvedLength = dataSize;
    }
    else
    {
        ringBuffer->HEAD = (ringBuffer->HEAD + contigousBytes) % ringBuffer->SIZE;
        recvedLength = contigousBytes;
    }

    return recvedLength;
}

uint32_t TwRingBufferFreeSpace (TW_RING_BUFFER_t *ringBuffer)
{
    uint32_t tailToEnd = ringBuffer->SIZE - ringBuffer->TAIL - 1;
    return (tailToEnd + ringBuffer->HEAD) % ringBuffer->SIZE;
}

uint32_t TwRingBufferUsedSpace (TW_RING_BUFFER_t *ringBuffer)
{
    uint32_t headToEnd = ringBuffer->SIZE - ringBuffer->HEAD;
    return (headToEnd + ringBuffer->TAIL) % ringBuffer->SIZE;
}
