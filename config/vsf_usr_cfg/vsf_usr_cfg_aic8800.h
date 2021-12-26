/*****************************************************************************
 *   Copyright(C)2009-2019 by VSF Team                                       *
 *                                                                           *
 *  Licensed under the Apache License, Version 2.0 (the "License");          *
 *  you may not use this file except in compliance with the License.         *
 *  You may obtain a copy of the License at                                  *
 *                                                                           *
 *     http://www.apache.org/licenses/LICENSE-2.0                            *
 *                                                                           *
 *  Unless required by applicable law or agreed to in writing, software      *
 *  distributed under the License is distributed on an "AS IS" BASIS,        *
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. *
 *  See the License for the specific language governing permissions and      *
 *  limitations under the License.                                           *
 *                                                                           *
 ****************************************************************************/


//! \note User Level Application Configuration

#ifndef __VSF_USR_CFG_AIC8800_H__
#define __VSF_USR_CFG_AIC8800_H__

/*============================ INCLUDES ======================================*/

#define __VSF_HEADER_ONLY_SHOW_COMPILER_INFO__
#include "utilities/compiler/compiler.h"

// for uint32_t of SystemCoreClock
#include <stdint.h>

/*============================ MACROS ========================================*/

//extern uint32_t SystemCoreClock;
// DO NOT use SystemCoreClock for VSF_SYSTIMER_FREQ, because systimer is initialized
//  in vsf_arch_init, which is eariler than initialization of SystemCoreClock in
//  vsf_driver_init.
#define VSF_SYSTIMER_FREQ                               (240UL * 1000 * 1000)
// lwip APIs are protected by a mutex, so priority boost SHOULD be supported
//#define VSF_OS_CFG_ADD_EVTQ_TO_IDLE                     ENABLED
// configure pool and heap to avoid heap allocating in interrupt
#define VSF_OS_CFG_EVTQ_POOL_SIZE                       128
#define VSF_OS_CFG_DEFAULT_TASK_FRAME_POOL_SIZE         32
#define VSF_POOL_CFG_FEED_ON_HEAP                       DISABLED
// enable VSF_EDA_QUEUE_CFG_REGION and VSF_EDA_QUEUE_CFG_SUPPORT_ISR
#define VSF_EDA_QUEUE_CFG_REGION                        ENABLED
#define VSF_EDA_QUEUE_CFG_SUPPORT_ISR                   ENABLED

// Use unused interrupt as SWI
#define VSF_DEV_SWI_NUM                                 4
#define VSF_DEV_SWI_LIST                                WDT3_IRQn, WDT2_IRQn, WDT1_IRQn, I2CS_IRQn
#define SWI0_IRQHandler                                 WDT3_IRQHandler
#define SWI1_IRQHandler                                 WDT2_IRQHandler
#define SWI2_IRQHandler                                 WDT1_IRQHandler
#define SWI3_IRQHandler                                 I2CS_IRQHandler

#define VSF_HAL_USE_RNG                                 ENABLED
#define VSF_HAL_USE_GPIO                                ENABLED

// Application configure

// demo for AIC8800
#define VSF_USE_WIFI                                    ENABLED
#define VSF_USE_MBEDTLS                                 ENABLED
#define AIC8800_APP_USE_WIFI_DEMO                       ENABLED
#define AIC8800_APP_USE_BT_DEMO                         ENABLED

// app configurations to vsf configurations

// component configure
#define VSF_USE_HEAP                                    ENABLED
#   define VSF_HEAP_CFG_MCB_MAGIC_EN                    ENABLED
#   define VSF_HEAP_CFG_MCB_ALIGN_BIT                   4
#   define VSF_HEAP_ADDR                                0x00100000
#   define VSF_HEAP_SIZE                                0x50000

#define VSF_HAL_USE_DEBUG_STREAM                        ENABLED
#define VSF_ASSERT(...)                                 if (!(__VA_ARGS__)) {while(1);}

#define VSF_LINUX_CFG_STACKSIZE                         (8 * 1024)
#define VSF_TRACE_CFG_COLOR_EN                          ENABLED
#define VSH_HAS_COLOR                                   1

/*============================ TYPES =========================================*/
/*============================ GLOBAL VARIABLES ==============================*/
/*============================ LOCAL VARIABLES ===============================*/
/*============================ PROTOTYPES ====================================*/


#endif      // __VSF_USR_CFG_AIC8800_H__
/* EOF */
