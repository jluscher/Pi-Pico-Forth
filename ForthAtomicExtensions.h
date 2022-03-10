//
/*
enum gpio_function { GPIO_FUNC_XIP  = 0, GPIO_FUNC_SPI  = 1,
                     GPIO_FUNC_UART = 2, GPIO_FUNC_I2C  = 3, 
                     GPIO_FUNC_PWM  = 4, GPIO_FUNC_SIO  = 5, 
                     GPIO_FUNC_PIO0 = 6, GPIO_FUNC_PIO1 = 7, 
                     GPIO_FUNC_GPCK = 8, GPIO_FUNC_USB  = 9, 
                     GPIO_FUNC_NULL =  0x1f };

enum gpio_irq_level { GPIO_IRQ_LEVEL_LOW = 0x1u, GPIO_IRQ_LEVEL_HIGH = 0x2u, 
                      GPIO_IRQ_EDGE_FALL = 0x4u, GPIO_IRQ_EDGE_RISE = 0x8u };                     

enum gpio_drive_strength { GPIO_DRIVE_STRENGTH_2MA = 0, GPIO_DRIVE_STRENGTH_4MA  = 1, 
                           GPIO_DRIVE_STRENGTH_8MA = 2, GPIO_DRIVE_STRENGTH_12MA = 3 };

enum gpio_slew_rate { GPIO_SLEW_RATE_SLOW = 0, GPIO_SLEW_RATE_FAST = 1 };
*/
#include "Common.h"
void MoreBuiltInAtomics(void);
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
//
// ADC functions
//
void f_adc_init(void);
void f_adc_gpio_init(cell);
void f_adc_select_input(cell);
cell f_adc_read(void);
