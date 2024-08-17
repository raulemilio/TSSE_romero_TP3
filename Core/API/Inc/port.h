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
 * port.h
 *
 *  Created on: Aug 13, 2023
 *      Author: rome
 */

#ifndef INC_PORT_H_
#define INC_PORT_H_

#include "stm32f4xx_hal.h"
#include "main.h"

// adaptador I2C para LCD
#define I2C_ADDR    0x27 // I2C address PCF8574
#define I2C_SIZE    1
#define I2C_TIMEOUT 100
#define EN_BIT      2 // Enable bit

// ISP
#define SPI_ENABLE_PIN GPIO_PIN_14

// Funciones Públicas

void setSPI_Port_Name(SPI_HandleTypeDef hspiX);
void setI2C_Port_Name(I2C_HandleTypeDef hi2cX);
void setUART_Port_Name(UART_HandleTypeDef huartX);

void MX_GPIO_Init(void);
void MX_SPI_Init(void);
void MX_I2C_Init(void);
void MX_USART_UART_Init(void);

void LCDHD44780_I2C_PCF8574T_TransmitReceive(uint8_t data, uint8_t size, uint8_t timeOut);
void BMP280_SPI_TransmitReceive(uint8_t buffer[2], uint8_t size, uint8_t timeOut);

void UART_Send_Temperature(float temperature);
void UART_TemperatureAlarm(void);
void UART_SensorTemperatureError(void);
void UART_SensorConnectError(void);

#endif /* INC_PORT_H_ */
