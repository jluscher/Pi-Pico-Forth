#include <stdint.h>
// ADC functions
void    f_adc_init(void);
void    f_adc_gpio_init(int32_t);
void    f_adc_select_input(int32_t);
int32_t f_adc_read(void);
