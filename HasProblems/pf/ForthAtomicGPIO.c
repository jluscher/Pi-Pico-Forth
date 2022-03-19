#include "hardware/gpio.h"
#include "ForthHardwareGPIO.h"
//
cell f_gpio_get_dir(cell gpio){
  return( gpio_get_dir(gpio) );
}
//
cell f_gpio_get_drive_strength(cell gpio){
  return( gpio_get_drive_strength(gpio) );
}
//
cell f_gpio_get_slew_rate(cell gpio){
  return( gpio_get_slew_rate(gpio) );  
}
//
cell f_gpio_is_pulled_up (cell gpio){
  return( gpio_is_pulled_up(gpio) );  
};
//
cell f_gpio_is_pulled_down(cell gpio){
  return( gpio_is_pulled_down(gpio) );  
};
//
cell f_gpio_is_input_hysteresis_enabled(cell gpio){
  return( gpio_is_input_hysteresis_enabled(gpio) );  
}
//
cell f_gpio_get(cell gpio){
  return( gpio_get( gpio) );
}
//
void f_gpio_init(cell gpio){ // sets pin for SIO bit banging
  gpio_init(gpio);
}
//
void f_gpio_set_dir(cell gpio, cell dir){ // -1 == Out, 0 == In
  gpio_set_dir(gpio, dir);
}
//
void f_gpio_put(cell gpio, cell state){
  gpio_put(gpio, state);
}
//
void f_gpio_set_drive_strength (cell gpio, cell drive){
  drive &= 0x03;
  gpio_set_drive_strength(gpio, drive);
}
//
void f_gpio_set_slew_rate(cell gpio, cell slew){
  slew &= 0x01;
  gpio_set_slew_rate(gpio, slew);
}
//
void f_gpio_disable_pulls(cell gpio){
  gpio_disable_pulls(gpio);
}
//
void f_gpio_pull_up(cell gpio){
  gpio_pull_up(gpio);
}
//
void f_gpio_pull_down(cell gpio){
  gpio_pull_down(gpio);
}
//
void f_gpio_set_input_hysteresis_enabled(cell gpio, cell hyst){
  gpio_set_input_hysteresis_enabled(gpio, hyst);
}