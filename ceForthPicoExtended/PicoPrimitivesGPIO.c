#include "Common.h"
#include "hardware/gpio.h"
#include "PICOprimitivesGPIO.h"
//
extern MemoryImage *M;
//
#define ONE_PARAM (M->top); popS;
#define TWO_PARAM (M->top, M->S); popS; popS;
//
void f_gpio_get_dir(void)                     { pushS (uint32_t) gpio_get_dir ONE_PARAM }
void f_gpio_get_drive_strength(void)          { pushS (uint32_t) gpio_get_drive_strength ONE_PARAM }
void f_gpio_get_slew_rate(void)               { pushS (uint32_t) gpio_get_slew_rate ONE_PARAM }
void f_gpio_is_pulled_up (void)               { pushS (uint32_t) gpio_is_pulled_up ONE_PARAM }
void f_gpio_is_pulled_down(void)              { pushS (uint32_t) gpio_is_pulled_down ONE_PARAM }
void f_gpio_is_input_hysteresis_enabled(void) { pushS (uint32_t) gpio_is_input_hysteresis_enabled ONE_PARAM }
void f_gpio_get(void)                         { pushS (uint32_t) gpio_get ONE_PARAM }
void f_gpio_init(void)                        { gpio_init ONE_PARAM }
void f_gpio_set_dir(void)                     { gpio_set_dir TWO_PARAM }
void f_gpio_put(void)                         { gpio_put TWO_PARAM }
void f_gpio_set_drive_strength (void)         { gpio_set_drive_strength TWO_PARAM }
void f_gpio_set_slew_rate(void)               { gpio_set_slew_rate TWO_PARAM }
void f_gpio_disable_pulls(void)               { gpio_disable_pulls ONE_PARAM }
void f_gpio_pull_up(void)                     { gpio_pull_up ONE_PARAM }
void f_gpio_pull_down(void)                   { gpio_pull_down ONE_PARAM }
void f_gpio_set_input_hysteresis_enabled(void){ gpio_set_input_hysteresis_enabled TWO_PARAM }
