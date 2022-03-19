#include "hardware/adc.h"
#include "ForthHardwareADC.h"
//
// ADC functions
//
void f_adc_init(void){
  adc_init();
}
//
void f_adc_gpio_init(cell gpio){
  adc_gpio_init(gpio);
}
//
void f_adc_select_input(cell adcport){
  adcport &= 0x03;
  adc_select_input(adcport);
}
//
cell f_adc_read (void){
  return(adc_read());
}
