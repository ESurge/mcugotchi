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
#ifndef _STORAGE_H_
#define _STORAGE_H_

#include <stdint.h>

#define STORAGE_BASE_ADDRESS				0x800D000

#define STORAGE_SIZE					0x13000
#define STORAGE_PAGE_SIZE				512 // 2KB in words (sizeof(uint32_t))

#define STORAGE_ROM_OFFSET				0x0
#define STORAGE_ROM_SIZE				0xC00 // 12KB in words (sizeof(uint32_t))

#define STORAGE_FS_OFFSET				0xC00
#define STORAGE_FS_SIZE					0x4000 // 64KB in words (sizeof(uint32_t))


int8_t storage_read(uint32_t offset, uint32_t *data, uint32_t length);
int8_t storage_write(uint32_t offset, uint32_t *data, uint32_t length);
int8_t storage_erase(void);

#endif /* _STORAGE_H_ */
