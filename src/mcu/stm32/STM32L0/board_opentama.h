/*
 * MCUGotchi - A Tamagotchi P1 emulator for microcontrollers
 *
 * Copyright (C) 2021 Jean-Christophe Rona <jc@rona.fr>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
#ifndef _BOARD_DEF_H_
#define _BOARD_DEF_H_

#define BOARD_SCREEN_SPI			SPI1
#define BOARD_SCREEN_SPI_CLK_ENABLE		__HAL_RCC_SPI1_CLK_ENABLE

#define BOARD_SCREEN_SCLK_PIN			GPIO_PIN_5
#define BOARD_SCREEN_SCLK_PORT			GPIOA

#define BOARD_SCREEN_MOSI_PIN			GPIO_PIN_7
#define BOARD_SCREEN_MOSI_PORT			GPIOA

#define BOARD_SCREEN_DC_PIN			GPIO_PIN_8
#define BOARD_SCREEN_DC_PORT			GPIOA

#define BOARD_SCREEN_NSS_PIN			GPIO_PIN_4
#define BOARD_SCREEN_NSS_PORT			GPIOA

#define BOARD_SCREEN_RST_PIN			GPIO_PIN_6
#define BOARD_SCREEN_RST_PORT			GPIOA

#define BOARD_SCREEN_BL_PIN			GPIO_PIN_1
#define BOARD_SCREEN_BL_PORT			GPIOB

#define BOARD_LEFT_BTN_PIN			GPIO_PIN_3
#define BOARD_LEFT_BTN_PORT			GPIOB
#define BOARD_LEFT_BTN_EXTI_LINE		EXTI_LINE_3
#define BOARD_LEFT_BTN_EXTI_PORT		EXTI_GPIOB

#define BOARD_MIDDLE_BTN_PIN			GPIO_PIN_0
#define BOARD_MIDDLE_BTN_PORT			GPIOA
#define BOARD_MIDDLE_BTN_EXTI_LINE		EXTI_LINE_0
#define BOARD_MIDDLE_BTN_EXTI_PORT		EXTI_GPIOA

#define BOARD_RIGHT_BTN_PIN			GPIO_PIN_2
#define BOARD_RIGHT_BTN_PORT			GPIOB
#define BOARD_RIGHT_BTN_EXTI_LINE		EXTI_LINE_2
#define BOARD_RIGHT_BTN_EXTI_PORT		EXTI_GPIOB

#define BOARD_LED_RGB_PWM_TIMER			TIM2
#define BOARD_LED_RGB_CLK_ENABLE		__HAL_RCC_TIM2_CLK_ENABLE
#define BOARD_LED_RGB_FORCE_RESET		__HAL_RCC_TIM2_FORCE_RESET
#define BOARD_LED_RGB_RELEASE_RESET		__HAL_RCC_TIM2_RELEASE_RESET

#define BOARD_LED_RED_PIN			GPIO_PIN_1
#define BOARD_LED_RED_PORT			GPIOA
#define BOARD_LED_RED_PWM_CHANNEL		TIM_CHANNEL_2
#define BOARD_LED_RED_CALIBRATION		0x400

#define BOARD_LED_GREEN_PIN			GPIO_PIN_3
#define BOARD_LED_GREEN_PORT			GPIOA
#define BOARD_LED_GREEN_PWM_CHANNEL		TIM_CHANNEL_4
#define BOARD_LED_GREEN_CALIBRATION		0x100

#define BOARD_LED_BLUE_PIN			GPIO_PIN_2
#define BOARD_LED_BLUE_PORT			GPIOA
#define BOARD_LED_BLUE_PWM_CHANNEL		TIM_CHANNEL_3
#define BOARD_LED_BLUE_CALIBRATION		0x100

#define BOARD_NCHARGE_PIN			GPIO_PIN_5
#define BOARD_NCHARGE_PORT			GPIOB

#define BOARD_SPEAKER_PIN			GPIO_PIN_4
#define BOARD_SPEAKER_PORT			GPIOB
#define BOARD_SPEAKER_PWM_CHANNEL		TIM_CHANNEL_1
#define BOARD_SPEAKER_PWM_TIMER			TIM3
#define BOARD_SPEAKER_CLK_ENABLE		__HAL_RCC_TIM3_CLK_ENABLE
#define BOARD_SPEAKER_FORCE_RESET		__HAL_RCC_TIM3_FORCE_RESET
#define BOARD_SPEAKER_RELEASE_RESET		__HAL_RCC_TIM3_RELEASE_RESET

#define BOARD_VBATT_MEAS_PIN			GPIO_PIN_9
#define BOARD_VBATT_MEAS_PORT			GPIOB

#define BOARD_VBATT_ANA_PIN			GPIO_PIN_0
#define BOARD_VBATT_ANA_PORT			GPIOB

#define BOARD_VBUS_SENSE_PIN			GPIO_PIN_8
#define BOARD_VBUS_SENSE_PORT			GPIOB

#define BOARD_USB_DP_PIN			GPIO_PIN_12
#define BOARD_USB_DP_PORT			GPIOA

#define BOARD_USB_DM_PIN			GPIO_PIN_11
#define BOARD_USB_DM_PORT			GPIOA

#endif /* _BOARD_DEF_H_ */