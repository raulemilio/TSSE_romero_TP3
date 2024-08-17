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
 * termometroConfig.h
 *
 *  Created on: 14 ago. 2023
 *      Author: rome
 */

#ifndef INC_TERMOMETROCONFIG_H_
#define INC_TERMOMETROCONFIG_H_

/**********************************
 * Parámetros generales de configuración
 */
#define TEMPERATURE_MIN         10  // Temperatura mínima posible del ambiente a medir
#define TEMPERATURE_MAX         35  // Temperatura máxima posible del ambiente a medir
#define TEMPERATURE_ALARM       28  // Temperatura de alarma para generar un alerta
#define TEMPERATURE_TIME_UPDATE 500 // Tiempo de actualización en ms
/**********************************
 * Periféricos a utilizar en STM32F429ZI
 */
static SPI_HandleTypeDef hspi1;
static I2C_HandleTypeDef hi2c2;
static UART_HandleTypeDef huart3;
/***********************************/

#endif /* INC_TERMOMETROCONFIG_H_ */
