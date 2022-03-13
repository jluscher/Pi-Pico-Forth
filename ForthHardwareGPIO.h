#include "Common.h"
cell f_gpio_get_dir(cell);
cell f_gpio_get_drive_strength(cell);
cell f_gpio_get_slew_rate(cell);
void f_gpio_disable_pulls(cell);
void f_gpio_pull_up(cell);
void f_gpio_pull_down(cell);
cell f_gpio_is_pulled_up(cell);
cell f_gpio_is_pulled_down(cell);
cell f_gpio_is_input_hysteresis_enabled(cell);
cell f_gpio_get(cell); 
void f_gpio_init(cell);
void f_gpio_set_dir(cell, cell);
void f_gpio_put(cell, cell);
void f_gpio_set_drive_strength (cell, cell);
void f_gpio_set_slew_rate(cell, cell);
void f_gpio_set_input_hysteresis_enabled(cell, cell);