/************************************************************************************************
Copyright (c) 2024, Raúl Emilio Romero <rraulemilioromero@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/

/*
 * API_dalay.c
 *
 *  Created on: 17 ago. 2023
 *      Author: rome
 */
#include "API_delay.h"

void delayInit(delay_t * delay, tick_t duration) {
    delay->duration = duration;
    delay->running = false;
}

bool_t delayRead(delay_t * delay) {
    bool_t ret = false;

    // if(delay==NULL)
    //   Error_Handler();

    if (delay->running == false) {
        delay->startTime = HAL_GetTick();
        delay->running = true;
    } else if (HAL_GetTick() - delay->startTime >= delay->duration) {
        delay->running = false;
        ret = true;
    }
    return ret;
}

void delayWrite(delay_t * delay, tick_t duration) {
    if (delay == NULL || duration <= 0)
        Error_Handler();
    delay->duration = duration;
}
