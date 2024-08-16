#ifndef MOCK_STM32F4XX_HAL_H
#define MOCK_STM32F4XX_HAL_H

#include "stm32f4xx_hal.h"

/* Mocks for HAL functions */
MOCK_FUNCTION(, HAL_StatusTypeDef, HAL_Init);
MOCK_FUNCTION(, HAL_StatusTypeDef, HAL_DeInit);
MOCK_FUNCTION(, void, HAL_MspInit);
MOCK_FUNCTION(, void, HAL_MspDeInit);
MOCK_FUNCTION(, HAL_StatusTypeDef, HAL_InitTick, uint32_t, TickPriority);
MOCK_FUNCTION(, void, HAL_IncTick);
MOCK_FUNCTION(, void, HAL_Delay, uint32_t, Delay);
MOCK_FUNCTION(, uint32_t, HAL_GetTick);
MOCK_FUNCTION(, uint32_t, HAL_GetTickPrio);
MOCK_FUNCTION(, HAL_StatusTypeDef, HAL_SetTickFreq, HAL_TickFreqTypeDef, Freq);
MOCK_FUNCTION(, HAL_TickFreqTypeDef, HAL_GetTickFreq);
MOCK_FUNCTION(, void, HAL_SuspendTick);
MOCK_FUNCTION(, void, HAL_ResumeTick);
MOCK_FUNCTION(, uint32_t, HAL_GetHalVersion);
MOCK_FUNCTION(, uint32_t, HAL_GetREVID);
MOCK_FUNCTION(, uint32_t, HAL_GetDEVID);
MOCK_FUNCTION(, void, HAL_DBGMCU_EnableDBGSleepMode);
MOCK_FUNCTION(, void, HAL_DBGMCU_DisableDBGSleepMode);
MOCK_FUNCTION(, void, HAL_DBGMCU_EnableDBGStopMode);
MOCK_FUNCTION(, void, HAL_DBGMCU_DisableDBGStopMode);
MOCK_FUNCTION(, void, HAL_DBGMCU_EnableDBGStandbyMode);
MOCK_FUNCTION(, void, HAL_DBGMCU_DisableDBGStandbyMode);
MOCK_FUNCTION(, void, HAL_EnableCompensationCell);
MOCK_FUNCTION(, void, HAL_DisableCompensationCell);
MOCK_FUNCTION(, uint32_t, HAL_GetUIDw0);
MOCK_FUNCTION(, uint32_t, HAL_GetUIDw1);
MOCK_FUNCTION(, uint32_t, HAL_GetUIDw2);

#if defined(STM32F427xx) || defined(STM32F437xx) || defined(STM32F429xx) || \
    defined(STM32F439xx) || defined(STM32F469xx) || defined(STM32F479xx)
MOCK_FUNCTION(, void, HAL_EnableMemorySwappingBank);
MOCK_FUNCTION(, void, HAL_DisableMemorySwappingBank);
#endif /* STM32F427xx || STM32F437xx || STM32F429xx || STM32F439xx || STM32F469xx || STM32F479xx */

#endif /* MOCK_STM32F4XX_HAL_H */