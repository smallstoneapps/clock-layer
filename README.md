# ClockLayer

Pebble library for easily adding a clock (time and/or date) layer to your app.

## Usage

````c
//  This is not a complete example, but should demonstrate the basic usage of a ClockLayer.

static ClockLayer* clock;

static void window_load(Window* window) {
  clock = clock_layer_create(GRect(0, 0, 144, 32));
  clock_layer_set_time_format(clock, "%H:%M");
  clock_layer_add_to_window(clock, window);
  clock_layer_update(clock);
}

static void tick_handler(struct tm* tick_time, TimeUnits units_changed) {
  clock_layer_set_time(tick_time);
}
````

## Function Documentation

### Basic Functions

Create a new ClockLayer.

    ClockLayer* clock_layer_create(GRect rect);

Destroys a ClockLayer.

    void clock_layer_destroy(ClockLayer* clock_layer);

Set the time format for the ClockLayer. Uses the same format arguments as strftime.

    void clock_layer_set_time_format(ClockLayer* clock_layer, char* format);

Get the TextLayer for the ClockLayer. 

    TextLayer* clock_layer_get_text_layer(ClockLayer* clock_layer);

Update the ClockLayer to display the current time.

    void clock_layer_update(ClockLayer* clock_layer);

Update the ClockLayer to a given time.
    
    void clock_layer_set_time(ClockLayer* clock_layer, struct tm* time);
    
### Utility Functions

Add the ClockLayer to a window.

    void clock_layer_add_to_window(ClockLayer* layer, Window* window);

Set the text colour for the ClockLayer.

    void clock_layer_set_text_color(ClockLayer* layer, GColor color);

Set the background colour for the ClockLayer.

    void clock_layer_set_background_color(ClockLayer* layer, GColor color);

Set the font for the ClockLayer.

    void clock_layer_set_font(ClockLayer* layer, GFont* font);

Set the text alignment for the ClockLayer.

    void clock_layer_set_text_alignment(ClockLayer* layer, GTextAlignment alignment);

Get the Layer for the ClockLayer.

    Layer* clock_layer_get_layer(ClockLayer* layer);

Set the font for the ClockLayer to a system font.

    void clock_layer_set_system_font(ClockLayer* layer, const char* font_key);

