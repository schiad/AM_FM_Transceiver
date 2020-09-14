/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usb_device.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "math.h"
#include "stdio.h"
#include "si5351.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
static const uint8_t ASCII[96][5] = { { 0x00, 0x00, 0x00, 0x00, 0x00 } // 20
		, { 0x00, 0x00, 0x5f, 0x00, 0x00 } // 21 !
		, { 0x00, 0x07, 0x00, 0x07, 0x00 } // 22 "
		, { 0x14, 0x7f, 0x14, 0x7f, 0x14 } // 23 #
		, { 0x24, 0x2a, 0x7f, 0x2a, 0x12 } // 24 $
		, { 0x23, 0x13, 0x08, 0x64, 0x62 } // 25 %
		, { 0x36, 0x49, 0x55, 0x22, 0x50 } // 26 &
		, { 0x00, 0x05, 0x03, 0x00, 0x00 } // 27 '
		, { 0x00, 0x1c, 0x22, 0x41, 0x00 } // 28 (
		, { 0x00, 0x41, 0x22, 0x1c, 0x00 } // 29 )
		, { 0x14, 0x08, 0x3e, 0x08, 0x14 } // 2a *
		, { 0x08, 0x08, 0x3e, 0x08, 0x08 } // 2b +
		, { 0x00, 0x50, 0x30, 0x00, 0x00 } // 2c ,
		, { 0x08, 0x08, 0x08, 0x08, 0x08 } // 2d -
		, { 0x00, 0x60, 0x60, 0x00, 0x00 } // 2e .
		, { 0x20, 0x10, 0x08, 0x04, 0x02 } // 2f /
		, { 0x3e, 0x51, 0x49, 0x45, 0x3e } // 30 0
		, { 0x00, 0x42, 0x7f, 0x40, 0x00 } // 31 1
		, { 0x42, 0x61, 0x51, 0x49, 0x46 } // 32 2
		, { 0x21, 0x41, 0x45, 0x4b, 0x31 } // 33 3
		, { 0x18, 0x14, 0x12, 0x7f, 0x10 } // 34 4
		, { 0x27, 0x45, 0x45, 0x45, 0x39 } // 35 5
		, { 0x3c, 0x4a, 0x49, 0x49, 0x30 } // 36 6
		, { 0x01, 0x71, 0x09, 0x05, 0x03 } // 37 7
		, { 0x36, 0x49, 0x49, 0x49, 0x36 } // 38 8
		, { 0x06, 0x49, 0x49, 0x29, 0x1e } // 39 9
		, { 0x00, 0x36, 0x36, 0x00, 0x00 } // 3a :
		, { 0x00, 0x56, 0x36, 0x00, 0x00 } // 3b ;
		, { 0x08, 0x14, 0x22, 0x41, 0x00 } // 3c <
		, { 0x14, 0x14, 0x14, 0x14, 0x14 } // 3d =
		, { 0x00, 0x41, 0x22, 0x14, 0x08 } // 3e >
		, { 0x02, 0x01, 0x51, 0x09, 0x06 } // 3f ?
		, { 0x32, 0x49, 0x79, 0x41, 0x3e } // 40 @
		, { 0x7e, 0x11, 0x11, 0x11, 0x7e } // 41 A
		, { 0x7f, 0x49, 0x49, 0x49, 0x36 } // 42 B
		, { 0x3e, 0x41, 0x41, 0x41, 0x22 } // 43 C
		, { 0x7f, 0x41, 0x41, 0x22, 0x1c } // 44 D
		, { 0x7f, 0x49, 0x49, 0x49, 0x41 } // 45 E
		, { 0x7f, 0x09, 0x09, 0x09, 0x01 } // 46 F
		, { 0x3e, 0x41, 0x49, 0x49, 0x7a } // 47 G
		, { 0x7f, 0x08, 0x08, 0x08, 0x7f } // 48 H
		, { 0x00, 0x41, 0x7f, 0x41, 0x00 } // 49 I
		, { 0x20, 0x40, 0x41, 0x3f, 0x01 } // 4a J
		, { 0x7f, 0x08, 0x14, 0x22, 0x41 } // 4b K
		, { 0x7f, 0x40, 0x40, 0x40, 0x40 } // 4c L
		, { 0x7f, 0x02, 0x0c, 0x02, 0x7f } // 4d M
		, { 0x7f, 0x04, 0x08, 0x10, 0x7f } // 4e N
		, { 0x3e, 0x41, 0x41, 0x41, 0x3e } // 4f O
		, { 0x7f, 0x09, 0x09, 0x09, 0x06 } // 50 P
		, { 0x3e, 0x41, 0x51, 0x21, 0x5e } // 51 Q
		, { 0x7f, 0x09, 0x19, 0x29, 0x46 } // 52 R
		, { 0x46, 0x49, 0x49, 0x49, 0x31 } // 53 S
		, { 0x01, 0x01, 0x7f, 0x01, 0x01 } // 54 T
		, { 0x3f, 0x40, 0x40, 0x40, 0x3f } // 55 U
		, { 0x1f, 0x20, 0x40, 0x20, 0x1f } // 56 V
		, { 0x3f, 0x40, 0x38, 0x40, 0x3f } // 57 W
		, { 0x63, 0x14, 0x08, 0x14, 0x63 } // 58 X
		, { 0x07, 0x08, 0x70, 0x08, 0x07 } // 59 Y
		, { 0x61, 0x51, 0x49, 0x45, 0x43 } // 5a Z
		, { 0x00, 0x7f, 0x41, 0x41, 0x00 } // 5b [
		, { 0x02, 0x04, 0x08, 0x10, 0x20 } // 5c ¥
		, { 0x00, 0x41, 0x41, 0x7f, 0x00 } // 5d ]
		, { 0x04, 0x02, 0x01, 0x02, 0x04 } // 5e ^
		, { 0x40, 0x40, 0x40, 0x40, 0x40 } // 5f _
		, { 0x00, 0x01, 0x02, 0x04, 0x00 } // 60 `
		, { 0x20, 0x54, 0x54, 0x54, 0x78 } // 61 a
		, { 0x7f, 0x48, 0x44, 0x44, 0x38 } // 62 b
		, { 0x38, 0x44, 0x44, 0x44, 0x20 } // 63 c
		, { 0x38, 0x44, 0x44, 0x48, 0x7f } // 64 d
		, { 0x38, 0x54, 0x54, 0x54, 0x18 } // 65 e
		, { 0x08, 0x7e, 0x09, 0x01, 0x02 } // 66 f
		, { 0x0c, 0x52, 0x52, 0x52, 0x3e } // 67 g
		, { 0x7f, 0x08, 0x04, 0x04, 0x78 } // 68 h
		, { 0x00, 0x44, 0x7d, 0x40, 0x00 } // 69 i
		, { 0x20, 0x40, 0x44, 0x3d, 0x00 } // 6a j
		, { 0x7f, 0x10, 0x28, 0x44, 0x00 } // 6b k
		, { 0x00, 0x41, 0x7f, 0x40, 0x00 } // 6c l
		, { 0x7c, 0x04, 0x18, 0x04, 0x78 } // 6d m
		, { 0x7c, 0x08, 0x04, 0x04, 0x78 } // 6e n
		, { 0x38, 0x44, 0x44, 0x44, 0x38 } // 6f o
		, { 0x7c, 0x14, 0x14, 0x14, 0x08 } // 70 p
		, { 0x08, 0x14, 0x14, 0x18, 0x7c } // 71 q
		, { 0x7c, 0x08, 0x04, 0x04, 0x08 } // 72 r
		, { 0x48, 0x54, 0x54, 0x54, 0x20 } // 73 s
		, { 0x04, 0x3f, 0x44, 0x40, 0x20 } // 74 t
		, { 0x3c, 0x40, 0x40, 0x20, 0x7c } // 75 u
		, { 0x1c, 0x20, 0x40, 0x20, 0x1c } // 76 v
		, { 0x3c, 0x40, 0x30, 0x40, 0x3c } // 77 w
		, { 0x44, 0x28, 0x10, 0x28, 0x44 } // 78 x
		, { 0x0c, 0x50, 0x50, 0x50, 0x3c } // 79 y
		, { 0x44, 0x64, 0x54, 0x4c, 0x44 } // 7a z
		, { 0x00, 0x08, 0x36, 0x41, 0x00 } // 7b {
		, { 0x00, 0x00, 0x7f, 0x00, 0x00 } // 7c |
		, { 0x00, 0x41, 0x36, 0x08, 0x00 } // 7d }
		, { 0x10, 0x08, 0x08, 0x10, 0x08 } // 7e �?
		, { 0x78, 0x46, 0x41, 0x46, 0x78 } // 7f →
};

uint8_t Nokia_map[6][84];
uint16_t ADC_BUFF = 4200;
uint16_t BUFF_ADC1[4200];
uint16_t BUFF_ADC3[4200];
uint16_t trig = 2048;
uint32_t ad_freq = 1000;
uint64_t si_freq = 3500000;
uint8_t sw_ad_si_pcm = 0;

struct NEC NEC1;

uint8_t x, y; // for nokia display position

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;

I2C_HandleTypeDef hi2c1;
I2C_HandleTypeDef hi2c3;

I2S_HandleTypeDef hi2s2;
I2S_HandleTypeDef hi2s3;

RTC_HandleTypeDef hrtc;

SPI_HandleTypeDef hspi1;
SPI_HandleTypeDef hspi5;
DMA_HandleTypeDef hdma_spi5_tx;

TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim2;

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_ADC1_Init(void);
static void MX_I2C1_Init(void);
static void MX_I2C3_Init(void);
static void MX_I2S2_Init(void);
static void MX_I2S3_Init(void);
static void MX_SPI1_Init(void);
static void MX_SPI5_Init(void);
static void MX_TIM1_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_TIM2_Init(void);
static void MX_RTC_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

int si5351_freq(uint8_t out_pin, uint64_t freq) {
	uint8_t ok = 0;
	if (freq < 500000) {
		return 1;
	} else if (freq > 16000000000) {
		return 2;
	}

//	uint8_t r = 0;
	uint64_t synth = 0;
	uint64_t pllfreq = 0;
	uint64_t plldiv = 0.0;
	uint8_t R = 0;

	R = 0;
	while (!ok && (R < 8)) {
		synth = 8;
		while (!ok && (synth < 1000)) {
			pllfreq = freq * (1 << R) * synth;
			if (pllfreq < 113000000000 && pllfreq > 37500000000) {
				ok = 1;
			}
			if (!ok)
				synth++;
		}
		if (!ok)
			R++;
	}

	if (ok) {
		plldiv = pllfreq / 2500;
	} else {
		return 3;
	}

	si5351_Init();
	if (!out_pin) {
		si5351_setupPLL(SI5351_PLL_B, plldiv / 1000000, plldiv % 1000000,
				1000000);
		si5351_setupMultisynth(2, SI5351_PLL_B, synth, 0, 4);
		si5351_setupRdiv(2, R);
	} else {

		si5351_setupPLL(SI5351_PLL_A, plldiv / 1000000, plldiv % 1000000,
				1000000);
		si5351_setupMultisynth(0, SI5351_PLL_A, synth, 0, 4);
		si5351_setupRdiv(0, R);
	}
	si5351_enableOutputs(0xFF);
	return 0;
}

void nokia_senddata(SPI_HandleTypeDef *hspi, uint8_t *data, uint16_t len) {
	uint16_t i = 0;
	uint8_t dt;
	HAL_GPIO_WritePin(Nokia_DC_GPIO_Port, Nokia_DC_Pin, 1);
	HAL_GPIO_WritePin(Nokia_CE_GPIO_Port, Nokia_CE_Pin, 0);
	while (i < len) {
		dt = data[i] & 0b11111111;
		HAL_SPI_Transmit(hspi, &dt, 1, HAL_MAX_DELAY);
		i++;
	}
	HAL_GPIO_WritePin(Nokia_CE_GPIO_Port, Nokia_CE_Pin, 1);
}

void nokia_sendcmd(SPI_HandleTypeDef *hspi, uint8_t *data, uint16_t len) {
	uint16_t i = 0;
	uint8_t dt;
	HAL_GPIO_WritePin(Nokia_DC_GPIO_Port, Nokia_DC_Pin, 0);
	//HAL_Delay(1);
	HAL_GPIO_WritePin(Nokia_CE_GPIO_Port, Nokia_CE_Pin, 0);
	while (i < len) {
		dt = data[i];
		HAL_SPI_Transmit(hspi, &dt, 1, 100);
		i++;
	}
	HAL_GPIO_WritePin(Nokia_CE_GPIO_Port, Nokia_CE_Pin, 1);
}

void nokia_char(uint8_t str, uint8_t *x, uint8_t *y) {
	uint8_t i = 0;
	uint8_t lx = x[0];
	uint8_t ly = y[0];
	while (i < 5) {
		Nokia_map[ly][lx] = ASCII[(str - 0x20)][i];
		lx++;
		i++;
		if (lx >= 84) {
			ly++;
			lx = 0;
			if (ly > 5) {
				ly = 0;
			}
		}
	}
	Nokia_map[ly][lx] = 0x00;
	lx++;
	if (lx >= 84) {
		ly++;
		lx = 0;
		if (ly > 5) {
			ly = 0;
		}
	}
	x[0] = lx;
	y[0] = ly;
}

void nokia_str(uint8_t *str, uint8_t *x, uint8_t *y) {
	uint8_t stri = 0;
//	uint8_t data[2];
	while (str[stri]) {
		nokia_char(str[stri], x, y);
		stri++;
	}
}

void nokia_xy(SPI_HandleTypeDef *hspi, uint8_t x, uint8_t y) {
	uint8_t data[2];
	data[0] = 0b01000000 | y;
	data[1] = 0b10000000 | x;
	nokia_sendcmd(hspi, data, 2);
}

void nokia_init(SPI_HandleTypeDef *hspi) {
	uint16_t i = 0;
	HAL_GPIO_WritePin(Nokia_RST_GPIO_Port, Nokia_RST_Pin, 1);
	HAL_GPIO_WritePin(Nokia_DC_GPIO_Port, Nokia_DC_Pin, 1);
	HAL_GPIO_WritePin(Nokia_CE_GPIO_Port, Nokia_CE_Pin, 1);
	HAL_Delay(1);
	HAL_GPIO_WritePin(Nokia_RST_GPIO_Port, Nokia_RST_Pin, 0);
	HAL_Delay(1);
	HAL_GPIO_WritePin(Nokia_RST_GPIO_Port, Nokia_RST_Pin, 1);
	Nokia_map[0][0] = 0x21;		// 0b0010 0001
	Nokia_map[0][1] = 0xb4;		// 0b1011 0101 original 0xb5
	Nokia_map[0][2] = 0x04;		// 0b0000 0100
	Nokia_map[0][3] = 0x14;		// 0b0001 0100
	Nokia_map[0][4] = 0x20;		// 0b0010 0000
	Nokia_map[0][5] = 0x0c;		// 0b0000 1100
	nokia_sendcmd(hspi, Nokia_map[0], 6);
	i = 0;
	while (i < 504) {
		Nokia_map[0][i] = 0x00;
		i++;
	}
	nokia_senddata(hspi, Nokia_map[0], 504);
}

void nokia_refresh_map(SPI_HandleTypeDef *hspi) {
	nokia_xy(hspi, 0, 0);
	HAL_GPIO_WritePin(Nokia_DC_GPIO_Port, Nokia_DC_Pin, 1);
	HAL_GPIO_WritePin(Nokia_CE_GPIO_Port, Nokia_CE_Pin, 0);
	HAL_SPI_Transmit_DMA(hspi, Nokia_map[0], 504);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (htim->Instance == TIM1) {
		nokia_refresh_map(&hspi5);
	}
	if (htim->Instance == TIM2) {
		NEC1.addr = 0;
		NEC1.addr_inv = 0;
		NEC1.cmd = 0;
		NEC1.cmd_inv = 0;
		NEC1.complet = 0;
		NEC1.gpio = 0;
		NEC1.i = 0;
		NEC1.init_seq = 0;
		NEC1.repeat = 0;
	}
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	if (GPIO_Pin == IR_IN_Pin) {
		NEC1.count = __HAL_TIM_GET_COUNTER(&htim2);

		__HAL_TIM_SET_COUNTER(&htim2, 0);
		NEC1.gpio = HAL_GPIO_ReadPin(IR_IN_GPIO_Port, IR_IN_Pin);
//		HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
#ifdef DEBUG
		len = sprintf(str, "DEBUG :\t%u\t%u\t%u\n\r\0", NEC1.i, NEC1.gpio, NEC1.count);
		CDC_Transmit_FS(str, len);
#endif

		if (NEC1.gpio && NEC1.count > 850 && NEC1.count < 1000) {// about 9ms detect start high
			NEC1.init_seq = 1;
			//NEC1.complet = 0;
		}

		if (!NEC1.gpio && NEC1.count > 420 && NEC1.count < 480// about 4.5ms detect start low
		&& NEC1.init_seq) {
			NEC1.i = -1;
			NEC1.repeat = 0;
			NEC1.init_seq = 0;
		}

		if (!NEC1.gpio && NEC1.count > 200 && NEC1.count < 260// about 2.25ms detect repeat
		&& NEC1.init_seq) {
			NEC1.i = -1;
			NEC1.init_seq = 0;
			NEC1.repeat++;
			NEC1.complet = 1;
		}

		if (NEC1.gpio && NEC1.count > 40 && NEC1.count < 70) {	// about 0.5ms
			NEC1.i++;
		}

		if (!NEC1.gpio && NEC1.count > 40 && NEC1.count < 180) {// decode signal
			switch (NEC1.i / 8) {
			case 0:
				if (NEC1.count > 100) {
					NEC1.addr |= (1 << (NEC1.i % 8));
				} else {
					NEC1.addr &= ~(1 << (NEC1.i % 8));
				}
				break;
			case 1:
				if (NEC1.count > 100) {
					NEC1.addr_inv |= (1 << (NEC1.i % 8));
				} else {
					NEC1.addr_inv &= ~(1 << (NEC1.i % 8));
				}
				break;
			case 2:
				if (NEC1.count > 100) {
					NEC1.cmd |= (1 << (NEC1.i % 8));
				} else {
					NEC1.cmd &= ~(1 << (NEC1.i % 8));
				}
				break;
			case 3:
				if (NEC1.count > 100) {
					NEC1.cmd_inv |= (1 << (NEC1.i % 8));
				} else {
					NEC1.cmd_inv &= ~(1 << (NEC1.i % 8));
				}
				break;
			default:
				break;
			}
		}

		if (NEC1.i == 32) {
			NEC1.complet = 1;
		}
	}
}

void NEC_command() {
	static si_change = 0;
	uint8_t str[200];
	uint16_t len;
	x = 0;
	y = 4;
	si_change = 0;

	sprintf(str, "%02x %02x %02x %02x\r\n", NEC1.addr, NEC1.addr_inv, NEC1.cmd,
			NEC1.cmd_inv);
	nokia_str(str, &x, &y);
	//CDC_Transmit_FS(str, strlen(str));

	if (NEC1.addr == 0x01) {
		switch (NEC1.cmd) {
		case 0x10:
			// power
			si_freq = 87000000;
			si_change = 1;
			break;
		case 0x03:
			//source
			si_freq += 100000000;
			si_change = 1;
//			if (!NEC1.repeat) {
//				sw_ad_si_pcm++;
//				sw_ad_si_pcm = sw_ad_si_pcm % 3;
//			}
			break;
		case 0x01:
			//ratio
			si_freq += 10000000;
			si_change = 1;
			break;
		case 0x06:
			//mute
			si_freq += 1000000;
			si_change = 1;
			break;
		case 0x09:
			//power_s
			si_freq = 3500000;
			si_change = 1;
			break;
		case 0x1D:
			//up
			si_freq -= 100000000;
			si_change = 1;
			break;
		case 0x1F:
			//auto
			si_freq -= 10000000;
			si_change = 1;
			break;
		case 0x0D:
			//info
			si_freq -= 1000000;
			si_change = 1;
			break;
		case 0x19:
			//left
			si_freq += 100000;
			si_change = 1;
			break;
		case 0x1B:
			//menu
			si_freq += 10000;
			si_change = 1;
			break;
		case 0x11:
			//right
			si_freq += 1000;
			si_change = 1;
			break;
		case 0x15:
			//freeze
			si_freq += 100;
			si_change = 1;
			break;
		case 0x17:
			//exit
			si_freq -= 100000;
			si_change = 1;
			break;
		case 0x12:
			//down
			si_freq -= 10000;
			si_change = 1;
			break;
		case 0x16:
			//sensor
			si_freq -= 1000;
			si_change = 1;
			break;
		case 0x4D:
			//lock
			si_freq -= 100;
			si_change = 1;
			break;
		case 0x40:
			//1
			ad_freq = 1000;
			break;
		case 0x4C:
			//2
			ad_freq += 1000000;
			break;
		case 0x04:
			//3
			ad_freq += 100000;
			break;
		case 0x00:
			//VGA
			ad_freq += 10000;
			break;
		case 0x0A:
			//4
			ad_freq = 100000;
			break;
		case 0x1E:
			//5
			ad_freq -= 1000000;
			break;
		case 0x0E:
			//6
			ad_freq -= 100000;
			break;
		case 0x1A:
			//hdmi
			ad_freq -= 10000;
			break;
		case 0x1C:
			//7
			ad_freq += 1000;
			break;
		case 0x14:
			//8
			ad_freq += 100;
			break;
		case 0x0F:
			//9
			ad_freq += 10;
			break;
		case 0x0C:
			//AV
			ad_freq += 1;
			break;
		case 0x02:
			//swap
			ad_freq -= 1000;
			break;
		case 0x48:
			//0
			ad_freq -= 100;
			break;
		case 0x54:
			//pip
			ad_freq -= 10;
			break;
		case 0x05:
			//pop
			ad_freq -= 1;
			break;

		default:
			break;
		}
	}

	NEC1.complet = 0;
	AD9833_set(&hspi1, ad_freq, 0, 0);
	if (si_change == 1) {
		si5351_freq(2, si_freq * 100);
		si5351_freq(0, si_freq * 100);
	}
}

void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi) {
	if (hspi->Instance == SPI5) {
		HAL_GPIO_WritePin(Nokia_CE_GPIO_Port, Nokia_CE_Pin, 1);
	}

}

void AD9833_tx(SPI_HandleTypeDef *hspi, uint16_t dt) {
	static uint16_t data[1] = { 0 };
	data[0] = dt;
	HAL_GPIO_WritePin(AD9833_CS_GPIO_Port, AD9833_CS_Pin, 0);
	HAL_SPI_Transmit(hspi, &data[0], 1, HAL_MAX_DELAY);
	HAL_GPIO_WritePin(AD9833_CS_GPIO_Port, AD9833_CS_Pin, 1);
}

void AD9833_Init(SPI_HandleTypeDef *hspi) {
	uint16_t data;
	data = 0x21 << 8;
	AD9833_tx(hspi, data);
}

uint64_t AD9833_freq_calc(uint64_t freq, uint64_t clk) {
	static uint64_t ret;
	static uint64_t retf;

	retf = (freq * (2 << 27)) / clk;
	ret = retf;
	return ret;
}

void AD9833_set(SPI_HandleTypeDef *hspi, uint32_t freq, uint16_t phase,
		uint8_t reset) {

	static uint16_t fq1maskand = 0b0011111111111111;
	static uint16_t fq1maskor = 0b0100000000000000;
	static uint16_t ph1maskand = 0b1101111111111111;
	static uint16_t ph1markor = 0b1100000000000000;
	static uint16_t ftmask = 0b0011111111111111;
	static uint16_t twmask = 0b0000111111111111;

	static uint16_t fqlsb;
	static uint16_t fqmsb;

	static uint64_t FreqReg;
	static uint16_t PhReg;
	const uint64_t fmclk = 25000000;

	if (reset)
		AD9833_Init(hspi);

	//FreqReg = (freq << 28) / fmclk;
	FreqReg = AD9833_freq_calc(freq, fmclk);
	fqlsb = FreqReg & ftmask;
	fqmsb = (FreqReg >> 14) & ftmask;

	fqlsb = fq1maskand & fqlsb;
	fqlsb = fq1maskor | fqlsb;
	fqmsb = fq1maskand & fqmsb;
	fqmsb = fq1maskor | fqmsb;

	PhReg = (phase * 2 * M_PI) / 4096;
	PhReg &= twmask;

	PhReg &= ph1maskand;
	PhReg |= ph1markor;

	AD9833_tx(hspi, fqlsb);
	AD9833_tx(hspi, fqmsb);
	AD9833_tx(hspi, PhReg);
	if (reset)
		AD9833_tx(hspi, 0x2000);
}

void MCP_4651_write(uint8_t addr, uint8_t *data, int16_t size) {
	uint8_t MCP_4651_addr = 0b01010000;
	HAL_I2C_Mem_Write(&hi2c1, MCP_4651_addr, addr, I2C_MEMADD_SIZE_8BIT, data,
			size, HAL_MAX_DELAY);
}

void MCP_4651_init() {
	MCP_4651_write(0x04, 0b01111111, 1);
}

void MCP_4651_set(uint8_t ch, uint8_t val) {
	int8_t channel_addr = ch << 4;
	MCP_4651_write(channel_addr, val, 1);
}

/*
 void AD9833_set_DMA(SPI_HandleTypeDef *hspi, uint32_t freq, uint16_t phase,
 uint8_t reset) {

 static uint16_t fq1maskand = 0b0011111111111111;
 static uint16_t fq1maskor = 0b0100000000000000;
 static uint16_t ph1maskand = 0b1101111111111111;
 static uint16_t ph1markor = 0b1100000000000000;
 static uint16_t ftmask = 0b0011111111111111;
 static uint16_t twmask = 0b0000111111111111;

 static uint16_t fqlsb;
 static uint16_t fqmsb;

 static uint64_t FreqReg;
 static uint16_t PhReg;
 const uint64_t fmclk = 25000000;
 static uint16_t Tx_Buff[5] = { 0, 0, 0, 0, 0 };

 static uint8_t i;

 i = 0;

 if (reset) {
 Tx_Buff[i] = 0x2100;
 i++;
 }

 //FreqReg = (freq << 28) / fmclk;
 FreqReg = AD9833_freq_calc(freq, fmclk);
 fqlsb = FreqReg & ftmask;
 fqmsb = (FreqReg >> 14) & ftmask;

 fqlsb = fq1maskand & fqlsb;
 fqlsb = fq1maskor | fqlsb;
 fqmsb = fq1maskand & fqmsb;
 fqmsb = fq1maskor | fqmsb;

 PhReg = (phase * 2 * M_PI) / 4096;
 PhReg &= twmask;

 PhReg &= ph1maskand;
 PhReg |= ph1markor;

 //AD9833_tx(hspi, fqlsb);
 //AD9833_tx(hspi, fqmsb);
 //AD9833_tx(hspi, PhReg);

 Tx_Buff[i] = fqlsb;
 i++;
 Tx_Buff[i] = fqmsb;
 i++;
 Tx_Buff[i] = PhReg;
 i++;
 //Tx_Buff[i] = 0xC000;
 //i++;

 if (reset) {
 Tx_Buff[i] = 0x2000;
 i++;
 }
 HAL_SPI_Transmit_DMA(hspi, Tx_Buff, i);
 }

 void AD9833_set_DMA_reg(uint32_t freq, uint16_t *Tx_Buff) {

 static uint16_t fq1maskand = 0b0011111111111111;
 static uint16_t fq1maskor = 0b0100000000000000;
 static uint16_t ftmask = 0b0011111111111111;

 static uint16_t fqlsb;
 static uint16_t fqmsb;
 static uint64_t FreqReg;

 const uint64_t fmclk = 25000000;

 FreqReg = AD9833_freq_calc(freq, fmclk);
 fqlsb = FreqReg & ftmask;
 fqmsb = (FreqReg >> 14) & ftmask;

 fqlsb = fq1maskand & fqlsb;
 fqlsb = fq1maskor | fqlsb;
 fqmsb = fq1maskand & fqmsb;
 fqmsb = fq1maskor | fqmsb;

 //Tx_Buff[0] = 0b1000000000000000;
 //Tx_Buff[1] = 0b1000000000000000;

 Tx_Buff[0] = fqlsb;
 Tx_Buff[1] = fqmsb;
 }
 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	uint16_t i = 0;
	uint8_t p0 = 0;
	int8_t str[30];
	RTC_TimeTypeDef Time;

	ptr_hi2c1 = &hi2c1;
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_ADC1_Init();
  MX_I2C1_Init();
  MX_I2C3_Init();
  MX_I2S2_Init();
  MX_I2S3_Init();
  MX_SPI1_Init();
  MX_SPI5_Init();
  MX_TIM1_Init();
  MX_USART1_UART_Init();
  MX_USART2_UART_Init();
  MX_USB_DEVICE_Init();
  MX_TIM2_Init();
  MX_RTC_Init();
  /* USER CODE BEGIN 2 */
//	MX_RTC_Init();
//	HAL_RTC_Init(&hrtc);
	HAL_GPIO_WritePin(AD9833_CS_GPIO_Port, AD9833_CS_Pin, 1);
	nokia_init(&hspi5);
	x = 0;
	y = 0;
	nokia_str("AM_FM_Tx F4IFB", &x, &y);
	HAL_TIM_Base_Start_IT(&htim1);
	HAL_TIM_Base_Start_IT(&htim2);
	HAL_TIM_PWM_Start_IT(&htim1, TIM_CHANNEL_2);
	AD9833_set(&hspi1, ad_freq, 0, 1);
	si5351_Init();
	si5351_freq(2, 350000000);
	si5351_freq(0, 350000000);
	MCP_4651_init();
	MCP_4651_set(0, 127);
	MCP_4651_set(1, 100);

	si5351_enableOutputs(0xFF);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	while (1) {
		p0++;
		MCP_4651_set(0, p0);
		HAL_Delay(1000);
		if (NEC1.complet) {
			NEC_command();
//			NEC1.complet = 0;
		}
		x = 0;
		y = 1;
		sprintf(str, "%lu      \0", ad_freq);
		nokia_str(str, &x, &y);
		x = 0;
		y = 5;
		HAL_RTC_GetTime(&hrtc, &Time, RTC_FORMAT_BIN);
//		Time.Hours;
//		Time.Minutes;
//		Time.Seconds;
		sprintf(str, "%hu:%hu:%hu\0", Time.Hours, Time.Minutes, Time.Seconds);
		nokia_str(str, &x, &y);
		i++;
		//HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
		x = 0;
		y = 3;
		sprintf(str, "%lu      \0", si_freq);
		nokia_str(str, &x, &y);

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	}
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

  /** Configure the main internal regulator output voltage 
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE|RCC_OSCILLATORTYPE_LSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 192;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_I2S|RCC_PERIPHCLK_RTC;
  PeriphClkInitStruct.PLLI2S.PLLI2SN = 192;
  PeriphClkInitStruct.PLLI2S.PLLI2SM = 16;
  PeriphClkInitStruct.PLLI2S.PLLI2SR = 2;
  PeriphClkInitStruct.RTCClockSelection = RCC_RTCCLKSOURCE_LSE;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */
  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion) 
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.ScanConvMode = DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time. 
  */
  sConfig.Channel = ADC_CHANNEL_1;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief I2C3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C3_Init(void)
{

  /* USER CODE BEGIN I2C3_Init 0 */

  /* USER CODE END I2C3_Init 0 */

  /* USER CODE BEGIN I2C3_Init 1 */

  /* USER CODE END I2C3_Init 1 */
  hi2c3.Instance = I2C3;
  hi2c3.Init.ClockSpeed = 100000;
  hi2c3.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c3.Init.OwnAddress1 = 0;
  hi2c3.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c3.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c3.Init.OwnAddress2 = 0;
  hi2c3.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c3.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C3_Init 2 */

  /* USER CODE END I2C3_Init 2 */

}

/**
  * @brief I2S2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2S2_Init(void)
{

  /* USER CODE BEGIN I2S2_Init 0 */

  /* USER CODE END I2S2_Init 0 */

  /* USER CODE BEGIN I2S2_Init 1 */

  /* USER CODE END I2S2_Init 1 */
  hi2s2.Instance = SPI2;
  hi2s2.Init.Mode = I2S_MODE_MASTER_TX;
  hi2s2.Init.Standard = I2S_STANDARD_PHILIPS;
  hi2s2.Init.DataFormat = I2S_DATAFORMAT_16B;
  hi2s2.Init.MCLKOutput = I2S_MCLKOUTPUT_DISABLE;
  hi2s2.Init.AudioFreq = I2S_AUDIOFREQ_192K;
  hi2s2.Init.CPOL = I2S_CPOL_LOW;
  hi2s2.Init.ClockSource = I2S_CLOCK_PLL;
  hi2s2.Init.FullDuplexMode = I2S_FULLDUPLEXMODE_DISABLE;
  if (HAL_I2S_Init(&hi2s2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2S2_Init 2 */

  /* USER CODE END I2S2_Init 2 */

}

/**
  * @brief I2S3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2S3_Init(void)
{

  /* USER CODE BEGIN I2S3_Init 0 */

  /* USER CODE END I2S3_Init 0 */

  /* USER CODE BEGIN I2S3_Init 1 */

  /* USER CODE END I2S3_Init 1 */
  hi2s3.Instance = SPI3;
  hi2s3.Init.Mode = I2S_MODE_MASTER_TX;
  hi2s3.Init.Standard = I2S_STANDARD_PHILIPS;
  hi2s3.Init.DataFormat = I2S_DATAFORMAT_16B;
  hi2s3.Init.MCLKOutput = I2S_MCLKOUTPUT_DISABLE;
  hi2s3.Init.AudioFreq = I2S_AUDIOFREQ_192K;
  hi2s3.Init.CPOL = I2S_CPOL_LOW;
  hi2s3.Init.ClockSource = I2S_CLOCK_PLL;
  hi2s3.Init.FullDuplexMode = I2S_FULLDUPLEXMODE_DISABLE;
  if (HAL_I2S_Init(&hi2s3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2S3_Init 2 */

  /* USER CODE END I2S3_Init 2 */

}

/**
  * @brief RTC Initialization Function
  * @param None
  * @retval None
  */
static void MX_RTC_Init(void)
{

  /* USER CODE BEGIN RTC_Init 0 */

  /* USER CODE END RTC_Init 0 */

  /* USER CODE BEGIN RTC_Init 1 */

  /* USER CODE END RTC_Init 1 */
  /** Initialize RTC Only 
  */
  hrtc.Instance = RTC;
  hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
  hrtc.Init.AsynchPrediv = 127;
  hrtc.Init.SynchPrediv = 255;
  hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
  hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
  hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
  if (HAL_RTC_Init(&hrtc) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN RTC_Init 2 */

  /* USER CODE END RTC_Init 2 */

}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_16BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_HIGH;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_16;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief SPI5 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI5_Init(void)
{

  /* USER CODE BEGIN SPI5_Init 0 */

  /* USER CODE END SPI5_Init 0 */

  /* USER CODE BEGIN SPI5_Init 1 */

  /* USER CODE END SPI5_Init 1 */
  /* SPI5 parameter configuration*/
  hspi5.Instance = SPI5;
  hspi5.Init.Mode = SPI_MODE_MASTER;
  hspi5.Init.Direction = SPI_DIRECTION_2LINES;
  hspi5.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi5.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi5.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi5.Init.NSS = SPI_NSS_SOFT;
  hspi5.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_16;
  hspi5.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi5.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi5.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi5.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi5) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI5_Init 2 */

  /* USER CODE END SPI5_Init 2 */

}

/**
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};
  TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 959;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 999;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 499;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_ENABLE;
  sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
  if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
  sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
  sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
  sBreakDeadTimeConfig.DeadTime = 0;
  sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
  sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
  sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
  if (HAL_TIMEx_ConfigBreakDeadTime(&htim1, &sBreakDeadTimeConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */
  HAL_TIM_MspPostInit(&htim1);

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 959;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 65535;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/** 
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void) 
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA2_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA2_Stream4_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA2_Stream4_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA2_Stream4_IRQn);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED2_Pin|AD9833_CS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, Nokia_CE_Pin|Nokia_DC_Pin|Nokia_RST_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : LED1_Pin */
  GPIO_InitStruct.Pin = LED1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LED2_Pin AD9833_CS_Pin */
  GPIO_InitStruct.Pin = LED2_Pin|AD9833_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : Nokia_CE_Pin Nokia_DC_Pin Nokia_RST_Pin */
  GPIO_InitStruct.Pin = Nokia_CE_Pin|Nokia_DC_Pin|Nokia_RST_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : IR_IN_Pin */
  GPIO_InitStruct.Pin = IR_IN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(IR_IN_GPIO_Port, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI2_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI2_IRQn);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
	/* User can add his own implementation to report the file name and line number,
	 tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
