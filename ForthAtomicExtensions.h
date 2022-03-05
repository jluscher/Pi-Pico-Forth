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
