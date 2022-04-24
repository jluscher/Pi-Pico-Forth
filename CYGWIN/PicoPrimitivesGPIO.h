#include <stdint.h>
// GPIO Functions
int32_t f_gpio_get_dir(int32_t);
int32_t f_gpio_get_drive_strength(int32_t);
int32_t f_gpio_get_slew_rate(int32_t);
void    f_gpio_disable_pulls(int32_t);
void    f_gpio_pull_up(int32_t);
void    f_gpio_pull_down(int32_t);
int32_t f_gpio_is_pulled_up(int32_t);
int32_t f_gpio_is_pulled_down(int32_t);
int32_t f_gpio_is_input_hysteresis_enabled(int32_t);
int32_t f_gpio_get(int32_t); 
void    f_gpio_init(int32_t);
void    f_gpio_set_dir(int32_t, int32_t);
void    f_gpio_put(int32_t, int32_t);
void    f_gpio_set_drive_strength (int32_t, int32_t);
void    f_gpio_set_slew_rate(int32_t, int32_t);
void    f_gpio_set_input_hysteresis_enabled(int32_t, int32_t);
