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

#include <pebble.h>
#include "clock-layer.h"

struct ClockLayer {
  TextLayer* text_layer;
  char* format;
  char str[20];
};

ClockLayer* clock_layer_create(GRect frame) {
  ClockLayer* clock_layer = malloc(sizeof(ClockLayer));
  clock_layer->text_layer = text_layer_create(frame);
  text_layer_set_text_alignment(clock_layer->text_layer, GTextAlignmentCenter);
  text_layer_set_text_color(clock_layer->text_layer, GColorBlack);
  text_layer_set_background_color(clock_layer->text_layer, GColorClear);
  clock_layer->format = NULL;
  clock_layer_set_time_format(clock_layer, "%H:%M");
  return clock_layer;
}

void clock_layer_destroy(ClockLayer* clock_layer) {
  if (clock_layer == NULL) {
    return;
  }
  if (clock_layer->text_layer != NULL) {
    text_layer_destroy(clock_layer->text_layer);
  }
  free(clock_layer);
}

void clock_layer_set_time_format(ClockLayer* clock_layer, char* format) {
  free(clock_layer->format);
  clock_layer->format = malloc(strlen(format));
  strncpy(clock_layer->format, format, strlen(format));
}

TextLayer* clock_layer_get_text_layer(ClockLayer* clock_layer) {
  return clock_layer->text_layer;
}

void clock_layer_update(ClockLayer* clock_layer) {
  time_t tmp = time(NULL);
  struct tm* now = localtime(&tmp);
  clock_layer_set_time(clock_layer, now);
}

void clock_layer_set_time(ClockLayer* clock_layer, struct tm* current_time) {
  strftime(clock_layer->str, sizeof(clock_layer->str), clock_layer->format, current_time);
  text_layer_set_text(clock_layer->text_layer, clock_layer->str);
}