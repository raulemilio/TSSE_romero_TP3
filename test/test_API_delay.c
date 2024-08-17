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

#include "unity.h"
#include "API_delay.h"
#include "mock_stm32f4xx_hal.h" // Mocks para HAL_GetTick
#include "mock_error_handler.h" // Mocks para Error_Handler

/* === Macros definitions ====================================================================== */


// Declaración de variables de prueba
static delay_t test_delay;

/**
 * @brief Función setUp se ejecuta en cada prueba
 */
void setUp(void) {
    // Inicializa las variables de prueba antes de cada prueba
    delayInit(&test_delay, 0);
}

/**
 * @brief Función para cargar el estado inicial del delay
 */
void test_delayInit_Should_Initialize_Delay(void) {
    // Arrange
    tick_t duration = 1000;

    // Act
    delayInit(&test_delay, duration);

    // Se verifica que el valor de duración cargado se cargó correctamente
    TEST_ASSERT_EQUAL(duration, test_delay.duration);
    // Se verifica que el estado inicial de la variable running sea "false"
    TEST_ASSERT_FALSE(test_delay.running);
}

/**
 * @brief Función para probar que cumplido el tiempo de delay la salida running
 * paso de "true" a "false" 
 */
void test_delayRead_Should_Return_True_When_Duration_Elapsed(void) {
    // Arrange
    tick_t duration = 1000;
    test_delay.duration = duration;
    test_delay.startTime = 0;
    test_delay.running = true;

    // Mock de HAL_GetTick para simular que ha pasado el tiempo
    HAL_GetTick_ExpectAndReturn(duration + 1000);

    // Act
    bool_t result = delayRead(&test_delay);

    // Assert
    TEST_ASSERT_TRUE(result);
    TEST_ASSERT_FALSE(test_delay.running);
}

/**
 * @brief Función para comprabar que durante running la salida es "true"
 */
void test_delayRead_Should_Return_False_When_Duration_Not_Elapsed(void) {
    // Arrange
    tick_t duration = 1000;
    test_delay.duration = duration;
    test_delay.startTime = 0;
    test_delay.running = true;

    // Mock de HAL_GetTick para simular que no ha pasado el tiempo
    HAL_GetTick_ExpectAndReturn(500);

    // Act
    bool_t result = delayRead(&test_delay);

    // Assert
    TEST_ASSERT_FALSE(result);
    TEST_ASSERT_TRUE(test_delay.running);
}

/**
 * @brief Función para probar que al cargar una nueva duración la variable delay.duración
 * se actualiza
 */
void test_delayWrite_Should_Update_Duration(void) {
    // Arrange
    tick_t new_duration = 2000;
    test_delay.duration = 1000;

    // Act
    delayWrite(&test_delay, new_duration);

    // Assert
    TEST_ASSERT_EQUAL(new_duration, test_delay.duration);
}
/**
 * @brief Función llamar a una función callback de manejo de error si duración 
 * es menor o igual que 0
 */
void test_delayWrite_Should_CallErrorHandler_When_NonPositiveDuration(void) {
    delay_t delay;
    tick_t duration = 0;
    
    // llamada callback por fuera de rango
    Error_Handler_Expect();
    delayWrite(&delay, duration);
}
