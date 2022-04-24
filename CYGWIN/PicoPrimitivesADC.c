//#include "hardware/adc.h"
#include "PicoPrimitivesADC.h"
//
// ADC functions
//
void    f_adc_init(void){ adc_init(); }
void    f_adc_gpio_init(int32_t gpio){ adc_gpio_init(gpio); }
void    f_adc_select_input(int32_t adcport){ adcport &= 0x03; adc_select_input(adcport); }
int32_t f_adc_read (void){ return(adc_read()); }
