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
#ifndef _SYSTEM_H_
#define _SYSTEM_H_

/* Low-power states in enter+exit latency order */
typedef enum {
	STATE_RUN,
	STATE_SLEEP_S1,
	STATE_SLEEP_S2,
	STATE_SLEEP_S3,
} exec_state_t;

#define ENTER_SLEEP_S1_LATENCY		256
#define EXIT_SLEEP_S1_LATENCY		256

#define ENTER_SLEEP_S2_LATENCY		256
#define EXIT_SLEEP_S2_LATENCY		256

#define ENTER_SLEEP_S3_LATENCY		256
#define EXIT_SLEEP_S3_LATENCY		256

#define SLEEP_S1_THRESHOLD		(ENTER_SLEEP_S1_LATENCY + EXIT_SLEEP_S1_LATENCY)
#define SLEEP_S2_THRESHOLD		(ENTER_SLEEP_S2_LATENCY + EXIT_SLEEP_S2_LATENCY)
#define SLEEP_S3_THRESHOLD		(ENTER_SLEEP_S3_LATENCY + EXIT_SLEEP_S3_LATENCY)


void system_disable_irq(void);
void system_enable_irq(void);

void system_enter_state(exec_state_t state);

#endif /* _SYSTEM_H_ */
