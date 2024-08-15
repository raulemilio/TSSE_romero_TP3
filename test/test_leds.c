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
Con todos los leds apagados prender el led 3 y verificar que efectivamente el bit 2 se pone en 1 y
el resto de bit permanece en 0. Apagar un led prendido y ver que efectivamente se apaga y que el
resto no cambia. Con todos los leds apagados prender un led y verificar que al consultar el estado
del mismo me informa que esta prendido. Prender todos los leds que estan apagados antes de la
operación Apagar todos los leds que ya estan prendidos Prender leds que ya esten prendidos de antes
Apagar leds que ya esten apagados
Comprobar valores prohibidos
Comprobar los valores de limite
*/

#include "unity.h"
#include "leds.h"

/* === Macros definitions ====================================================================== */

#define LED_STATE_OFF 0
#define ALL_LED_OFF   0x00
#define ALL_LED_ON    0xFF

//! Variables de prueba
static uint16_t leds_virtuales;
static const int LED = 3;

/**
 * @brief Función setUp se ejecuta en cada prueba
 */
void setUp(void) {
    leds_init(&leds_virtuales);
}

/**
 * @brief Al iniciar el controlador los leds deben quedar
 *        todos los bits en 0 sin importar el estado anterior.
 */
void test_todos_los_leds_inician_apagado(void) {
    // Todos los leds a 1
    uint16_t leds_virtuales = ALL_LED_ON;
    // Todos los leds a 0
    leds_init(&leds_virtuales);
    // Verificamos que todos los leds están a 0
    TEST_ASSERT_EQUAL_UINT16(ALL_LED_OFF, leds_virtuales);
}

/**
 * @brief Con todos los leds apagados prender el led 3
 *        y verificar que efectivamente el bit 2 se pone en 1 y el resto de bit permanece en 0.
 */
void test_prender_un_led(void) {
    // Bit 2 en alto
    led_turn_on(LED);
    TEST_ASSERT_BIT_HIGH(LED - 1, leds_virtuales);
    // Todos los otros bits estan en bajo
    TEST_ASSERT_BIT_LOW(~(1 << (LED - 1)), leds_virtuales);
}

/**
 * @brief Apagar un led prendido y ver que efectivamente
 *        el resto no cambia
 */
void test_apagar_un_led(void) {
    led_turn_on(LED);
    led_turn_off(LED);
    TEST_ASSERT_EQUAL_UINT16(0x00, leds_virtuales);
}

/**
 * @brief Apagar todos los leds que ya estan prendidos
 */
void test_prender_y_apagar_varios_led(void) {
    led_turn_on(5);
    led_turn_on(7);
    led_turn_on(5);
    led_turn_off(5);
    led_turn_off(9);
    TEST_ASSERT_EQUAL_UINT16(1 << (7 - 1), leds_virtuales);
}

/**
 * @brief Prender todos los leds en una sola operación
 */
void test_prender_todos_los_leds(void) {
    led_turn_all_on(&leds_virtuales);
    TEST_ASSERT_EQUAL_UINT16(ALL_LED_ON, leds_virtuales);
}

/**
 * @brief Apagar todos los leds en una solo operación
 */
void test_apagar_todos_los_leds(void) {
    led_turn_all_off(&leds_virtuales);
    TEST_ASSERT_EQUAL_UINT16(ALL_LED_OFF, leds_virtuales);
}

/**
 * @brief Ver estado del led a partir de led OFF
 */
void test_estado_led_off(void) {
    TEST_ASSERT_EQUAL_UINT16(LED_STATE_OFF, led_get_state(LED));
}

/**
 * @brief Ver estado del led a partir de led ON
 */
void test_led_is_turned_on(void) {
    led_turn_on(LED);
    TEST_ASSERT_EQUAL_UINT16(LED + 1, led_get_state(LED));
}
