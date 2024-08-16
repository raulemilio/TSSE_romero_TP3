/*
 * BMP280.h
 *
 *  Created on: 14 ago. 2023
 *      Author: rome
 */

#ifndef BMPXX80_H_
#define BMPXX80_H_

#include "main.h"

// Device ID
#define BMP280_DEVICE_ID  0x58

#define COUNT_MAX_CONNECT 10 // Cantidad de intentos de conexión con el sensor
#define TIME_MAX_CONVERTION_FINISH                                                                 \
    100                            // Tiempo de espera en ms para la conversión de ADC del BMP280
#define CONVERTION_MAX_FINISH true // Tiempo máximo de espera para la conversión

// Tamaño del registro a leer/escribir
#define BMP280_SIZE_8  2
#define BMP280_SIZE_16 3
#define BMP280_SIZE_24 3
#define BMP280_TIMEOUT 10

// Resolución del conversor
#define BMP280_TEMPERATURE_16BIT 1 // 0,005 °C de resolución
#define BMP280_TEMPERATURE_17BIT 2
#define BMP280_TEMPERATURE_18BIT 3
#define BMP280_TEMPERATURE_19BIT 4
#define BMP280_TEMPERATURE_20BIT 5

// Mode
#define BMP280_SLEEPMODE  0
#define BMP280_FORCEDMODE 1
#define BMP280_NORMALMODE 3

//	Coeffs registers
#define BMP280_DIG_T1 0x88
#define BMP280_DIG_T2 0x8A
#define BMP280_DIG_T3 0x8C

// Registros
#define BMP280_CHIPID       0xD0
#define BMP280_VERSION      0xD1
#define BMP280_SOFTRESET    0xE0
#define BMP280_CAL26        0xE1
#define BMP280_STATUS       0xF3
#define BMP280_CONTROL      0xF4
#define BMP280_CONFIG       0xF5
#define BMP280_PRESSUREDATA 0xF7
#define BMP280_TEMPDATA     0xFA

//	Control bits
#define BMP280_MEASURING      (1 << 3) // Conversion in progress

#define BMP280_MODE_BIT_RW    7 //  bit de lectura/ escritura
#define BMP280_BIT_RESOLUTION 5

// Funciones Públicas
uint8_t BMP280_Init(SPI_HandleTypeDef * spi_handler, uint8_t temperature_resolution, uint8_t mode);
float BMP280_ReadTemperature(void);

#endif /* BMPXX80_H_ */
