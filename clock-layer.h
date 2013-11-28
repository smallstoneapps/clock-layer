/***
 * Clock Layer
 * Copyright © 2013 Matthew Tole
 ***/

#pragma once

#include <pebble.h>

struct ClockLayer;
typedef struct ClockLayer ClockLayer;

ClockLayer* clock_layer_create(GRect rect);
void clock_layer_destroy(ClockLayer* clock_layer);
void clock_layer_destroy_safe(ClockLayer* clock_layer);
void clock_layer_set_time_format(ClockLayer* clock_layer, char* format);
void clock_layer_set_text_color(ClockLayer* clock_layer, GColor color);
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