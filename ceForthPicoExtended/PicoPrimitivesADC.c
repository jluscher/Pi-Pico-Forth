#include "Common.h"
#include "hardware/adc.h"
#include "PicoPrimitivesADC.h"
//
// ADC functions
//
extern MemoryImage *M;
//
#define ONE_PARAM (M->top); popS;
//
void    f_temp_on         (void){ adc_set_temp_sensor_enabled(true); }
void    f_temp_off        (void){ adc_set_temp_sensor_enabled(false); }
void    f_adc_init        (void){ adc_init(); }
void    f_adc_gpio_init   (void){ adc_gpio_init ONE_PARAM }
void    f_adc_select_input(void){ adc_select_input ONE_PARAM}
void    f_adc_read        (void){ pushS (uint32_t)adc_read(); }
