/*
 * oled_lv_drv.c
 *
 *  Created on: Nov 11, 2022
 *      Author: jeffr
 */


#include "oled_lv_drv.h"
#include <stdlib.h>
lv_disp_t *disp;

void lvgl_driver_init(void){
	static lv_disp_draw_buf_t disp_buf; // contains internal graphic buffer(s) called draw buffer(s)
	static lv_disp_drv_t disp_drv;      // contains callback functions
	//display driver init
	ssd1306_init();
	static lv_disp_draw_buf_t draw_buf;
	lv_color_t *buf1 = malloc(LCD_H_RES * 20 * sizeof(lv_color_t));
	//static lv_color_t buf1[128 * 64 / 8];
	// initialize LVGL draw buffers
	lv_disp_draw_buf_init(&disp_buf, buf1, NULL, LCD_H_RES * 20);

	lv_disp_drv_init(&disp_drv);
	disp_drv.hor_res = LCD_H_RES;
	disp_drv.ver_res = LCD_V_RES;
	disp_drv.flush_cb = ssd1306_flush;
	disp_drv.draw_buf = &disp_buf;
	disp_drv.rounder_cb = ssd1306_rounder;
	disp_drv.set_px_cb = ssd1306_set_px_cb;
	lv_disp_t *disp = lv_disp_drv_register(&disp_drv);

	return;
}
