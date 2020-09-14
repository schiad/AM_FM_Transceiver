/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
struct NEC {
	uint8_t addr;
	uint8_t addr_inv;
	uint8_t cmd;
	uint8_t cmd_inv;
	uint8_t i;
	uint8_t init_seq;
	uint8_t gpio;
	uint16_t count;
	uint8_t repeat;
	uint8_t complet;
};
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

I2C_HandleTypeDef *ptr_hi2c1;

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED1_Pin GPIO_PIN_13
#define LED1_GPIO_Port GPIOC
#define LED2_Pin GPIO_PIN_0
#define LED2_GPIO_Port GPIOA
#define FBBFin_Pin GPIO_PIN_1
#define FBBFin_GPIO_Port GPIOA
#define AD9833_CS_Pin GPIO_PIN_4
#define AD9833_CS_GPIO_Port GPIOA
#define FBBFout_Pin GPIO_PIN_6
#define FBBFout_GPIO_Port GPIOA
#define Nokia_CE_Pin GPIO_PIN_1
#define Nokia_CE_GPIO_Port GPIOB
#define IR_IN_Pin GPIO_PIN_2
#define IR_IN_GPIO_Port GPIOB
#define IR_IN_EXTI_IRQn EXTI2_IRQn
#define Nokia_DC_Pin GPIO_PIN_13
#define Nokia_DC_GPIO_Port GPIOB
#define Nokia_RST_Pin GPIO_PIN_14
#define Nokia_RST_GPIO_Port GPIOB
#define Nokia_Light_Pin GPIO_PIN_9
#define Nokia_Light_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
