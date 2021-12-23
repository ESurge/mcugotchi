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
#include <stdint.h>

#include "stm32_hal.h"

#include "mcu_types.h"
#include "gpio.h"


void gpio_set(gpio_port_t port, gpio_pin_t pin)
{
	HAL_GPIO_WritePin(port, pin, GPIO_PIN_SET);
}

void gpio_clear(gpio_port_t port, gpio_pin_t pin)
{
	HAL_GPIO_WritePin(port, pin, GPIO_PIN_RESET);
}

uint8_t gpio_get(gpio_port_t port, gpio_pin_t pin)
{
	return (HAL_GPIO_ReadPin(port, pin) == GPIO_PIN_SET);
}
