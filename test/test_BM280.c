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
#include "stm32f4xx_hal.h"
//#include "mock_delay.h"
//#include "mock_i2c.h"
