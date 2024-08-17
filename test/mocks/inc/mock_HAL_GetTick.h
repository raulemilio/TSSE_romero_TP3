#ifndef MOCK_HAL_GETTICK_H
#define MOCK_HAL_GETTICK_H

#include "unity.h"
#include <stdint.h>

// Prototipo de la función
uint32_t HAL_GetTick(void);

// Macros para manejar expectativas y verificaciones en las pruebas
#define HAL_GetTick_ExpectAndReturn(value)                                                         \
    do {                                                                                           \
        HAL_GetTick_CMockExpectAndReturn(__LINE__, value);                                         \
    } while (0)

// Prototipos para las funciones mock generadas automáticamente por CMock
void HAL_GetTick_CMockExpectAndReturn(int line, uint32_t retval);

#endif // MOCK_HAL_GETTICK_H
