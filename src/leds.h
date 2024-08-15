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
#include <stdint.h>

/**
 * @brief Función para iniciar el array de led apagados
 *
 * @param puerto Puerto del array de leds
 */
void leds_init(uint16_t * puerto);

/**
 * @brief Función para encender un led en particular
 *
 * @param puerto dirección del led particular
 */
void led_turn_on(int led); // código optimo int y no uint16_t

/**
 * @brief Función para apagar un led en particular
 *
 * @param puerto dirección del led particular
 */
void led_turn_off(int led);

/**
 * @brief Función para encender todos los leds
 *
 * @param puerto puerto del array de leds
 */
void led_turn_all_on(uint16_t * puerto);

/**
 * @brief Función para apagar todos los leds
 *
 * @param puerto puerto del array de leds
 */
void led_turn_all_off(uint16_t * puerto);

/**
 * @brief Función para ver el estado de un led
 *
 * @param puerto puerto del array de leds
 */
int led_get_state(int led);
