/*

Clock Layer v1.1
A Pebble library for displaying a formatted time / date
http://smallstoneapps.github.io/clock-layer/

----------------------

The MIT License (MIT)

Copyright © 2013 - 2014 Matthew Tole

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

--------------------

clock-layer.c

*/

#pragma once

#include <pebble.h>

struct ClockLayer;
typedef struct ClockLayer ClockLayer;

ClockLayer* clock_layer_create(GRect rect);
void clock_layer_destroy(ClockLayer* clock_layer);
void clock_layer_set_time_format(ClockLayer* clock_layer, char* format);
TextLayer* clock_layer_get_text_layer(ClockLayer* clock_layer);
void clock_layer_update(ClockLayer* clock_layer);
void clock_layer_set_time(ClockLayer* clock_layer, struct tm* time);

#define clock_layer_add_to_window(layer, window) layer_add_child(window_get_root_layer(window), clock_layer_get_layer(layer))
#define clock_layer_set_text_color(layer, color) text_layer_set_text_color(clock_layer_get_text_layer(layer), color)
#define clock_layer_set_background_color(layer, color) text_layer_set_background_color(clock_layer_get_text_layer(layer), color)
#define clock_layer_set_font(layer, font) text_layer_set_font(clock_layer_get_text_layer(layer), font)
#define clock_layer_set_text_alignment(layer, alignment) text_layer_set_text_alignment(clock_layer_get_text_layer(layer), alignment)
#define clock_layer_get_layer(layer) text_layer_get_layer(clock_layer_get_text_layer(layer))
#define clock_layer_set_system_font(layer, font) clock_layer_set_font(layer, fonts_get_system_font(font))