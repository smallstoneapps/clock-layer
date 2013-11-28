/***
 * Clock Layer
 * Copyright © 2013 Matthew Tole
 ***/

#include <pebble.h>
#include "clock-layer.h"

struct ClockLayer {
  TextLayer* text_layer;
  char* format;
};

ClockLayer* clock_layer_create(GRect frame) {
  ClockLayer* clock_layer = malloc(sizeof(ClockLayer));
  clock_layer->text_layer = text_layer_create(frame);
  text_layer_set_text_alignment(clock_layer->text_layer, GTextAlignmentCenter);
  text_layer_set_text_color(clock_layer->text_layer, GColorBlack);
  text_layer_set_background_color(clock_layer->text_layer, GColorClear);
  clock_layer->format = "%H:%M";
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
  static char time_str[32];

  strftime(time_str, sizeof(time_str), clock_layer->format, current_time);
  text_layer_set_text(clock_layer->text_layer, time_str);
}