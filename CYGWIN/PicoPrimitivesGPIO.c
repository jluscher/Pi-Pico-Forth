//#include "hardware/gpio.h"
#include "PICOprimitivesGPIO.h"
int32_t f_gpio_get_dir(int32_t gpio){ return( gpio_get_dir(gpio) ); }
int32_t f_gpio_get_drive_strength(int32_t gpio){ return( gpio_get_drive_strength(gpio) ); }
int32_t f_gpio_get_slew_rate(int32_t gpio){ return( gpio_get_slew_rate(gpio) ); }
int32_t f_gpio_is_pulled_up (int32_t gpio){ return( gpio_is_pulled_up(gpio) ); };
int32_t f_gpio_is_pulled_down(int32_t gpio){ return( gpio_is_pulled_down(gpio) ); };
int32_t f_gpio_is_input_hysteresis_enabled(int32_t gpio){ return( gpio_is_input_hysteresis_enabled(gpio) ); }
int32_t f_gpio_get(int32_t gpio){ return( gpio_get( gpio) ); }
void f_gpio_init(int32_t gpio){ gpio_init(gpio); }
void f_gpio_set_dir(int32_t gpio, int32_t dir){ gpio_set_dir(gpio, dir); }
void f_gpio_put(int32_t gpio, int32_t state){ gpio_put(gpio, state); }
void f_gpio_set_drive_strength (int32_t gpio, int32_t drive){ drive &= 0x03; gpio_set_drive_strength(gpio, drive); }
void f_gpio_set_slew_rate(int32_t gpio, int32_t slew){ slew &= 0x01; gpio_set_slew_rate(gpio, slew); }
void f_gpio_disable_pulls(int32_t gpio){ gpio_disable_pulls(gpio); }
void f_gpio_pull_up(int32_t gpio){ gpio_pull_up(gpio); }
void f_gpio_pull_down(int32_t gpio){ gpio_pull_down(gpio); }
void f_gpio_set_input_hysteresis_enabled(int32_t gpio, int32_t hyst){ gpio_set_input_hysteresis_enabled(gpio, hyst); }