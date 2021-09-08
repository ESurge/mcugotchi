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
#include "stm32f0xx_hal.h"

#include "ssd1306.h"
#include "gfx.h"
#include "menu.h"

#define MENU_OFFSET_X				0
#define MENU_OFFSET_Y				0
#define MENU_ITEM_STRIDE_Y			16
#define MENU_ITEM_SIZE				1
#define ITEMS_ON_SCREEN				((64 - MENU_OFFSET_Y)/MENU_ITEM_STRIDE_Y)

static uint8_t is_visible = 0;
static menu_t *menu = NULL;
static menu_t *current_menu = NULL;
static uint8_t current_item = 0;


static void draw_menu(void)
{
	uint8_t i;
	uint8_t top_item = 0;
	uint8_t y = MENU_OFFSET_Y, x;

	if (current_item >= ITEMS_ON_SCREEN) {
		top_item = current_item - ITEMS_ON_SCREEN + 1;
	}

	ClrBuf();

	for (i = 0; i < ITEMS_ON_SCREEN; i++) {
		if (current_menu->items[top_item + i].name == NULL) {
			break;
		}

		x = PStr(current_menu->items[top_item + i].name, MENU_OFFSET_X, y, MENU_ITEM_SIZE, (top_item + i == current_item) ? PixInv : PixNorm);

		if (current_menu->items[top_item + i].arg_cb != NULL) {
			PStr(current_menu->items[top_item + i].arg_cb(), x, y, MENU_ITEM_SIZE, (top_item + i == current_item) ? PixInv : PixNorm);
		}

		y += MENU_ITEM_STRIDE_Y;
	}

	PScrn();
}

void menu_register(menu_t *items)
{
	menu = items;
}

void menu_open(void)
{
	if (menu == NULL) {
		return;
	}

	is_visible = 1;

	current_menu = menu;
	current_item = 0;
	draw_menu();
}

void menu_close(void)
{
	ClrBuf();
	PScrn();

	is_visible = 0;
}

uint8_t menu_is_visible(void)
{
	return is_visible;
}

void menu_next(void)
{
	current_item++;

	if (current_menu->items[current_item].name == NULL) {
		current_item = 0;
	}

	draw_menu();
}

void menu_enter(void)
{
	if (current_menu->items[current_item].cb != NULL) {
		/* Regular item */
		current_menu->items[current_item].cb();
	} else if (current_menu->items[current_item].sub_menu != NULL) {
		/* Sub menu */
		current_menu = current_menu->items[current_item].sub_menu;
		current_item = 0;
	}

	draw_menu();
}

void menu_back(void)
{
	if (current_menu->parent != NULL) {
		current_menu = current_menu->parent;
		current_item = 0;

		draw_menu();
	} else {
		menu_close();
	}
}