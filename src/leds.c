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

/** @file
 ** @brief Definición de la función principal del programa
 **/
/* === Headers files inclusions =============================================================== */
#include "leds.h"
/* === Macros definitions ====================================================================== */
#define BIT_HIGH      1
#define LED_OFFSET    1    // corrimiento necesario para identidicar correctamente cada led
#define LED_STATE_OFF 0    // led apagado
#define ALL_LED_OFF   0x00 // todos los led apagados
#define ALL_LED_ON    0xFF // todos los led encendidos
/* === Private data type declarations ========================================================== */
static uint16_t * puntero;
/* === Private variable declarations =========================================================== */
/* === Private function declarations =========================================================== */
static uint16_t led_to_mask(int led) {
    return (BIT_HIGH << (led - LED_OFFSET));
}
/* === Public variable definitions ============================================================= */
/* === Private variable definitions ============================================================ */
/* === Private function implementation ========================================================= */
/* === Public function implementation ========================================================== */
void leds_init(uint16_t * puerto) {
    puntero = puerto;
    led_turn_all_off(puntero);
}
void led_turn_on(int led) {
    *puntero |= led_to_mask(led);
}
void led_turn_off(int led) {
    *puntero &= ~led_to_mask(led);
}
void led_turn_all_on(uint16_t * puerto) {
    puntero = puerto;
    *puntero = ALL_LED_ON;
}
void led_turn_all_off(uint16_t * puerto) {
    puntero = puerto;
    *puntero = ALL_LED_OFF;
}
int led_get_state(int led) {
    return (*puntero & (BIT_HIGH << (led - LED_OFFSET)));
}
/* === End of documentation ==================================================================== */
