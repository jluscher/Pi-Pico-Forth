#include "ForthAtomicExtensions.h"
#include <stdio.h>
//
BUILTIN(71, "GPIO_DIR", gpio_dir, 0)
{
    cell gpio = pop();
    cell dir = f_gpio_get_dir(gpio);
    push(dir);
}
//
BUILTIN(72, "GPIO_AMP", gpio_amp, 0)
{
    cell gpio = pop();
    cell amps = f_gpio_get_drive_strength(gpio);
    push(amps);
}
//
BUILTIN(73, "GPIO_SLEW", gpio_slew, 0)
{
    cell gpio = pop();
    cell slew = f_gpio_get_slew_rate(gpio);
    push(slew);
}
//
void MoreBuiltInAtomics(void){ // must increment MAX_BUILTIN_ID when adding to this. See top of Common.h
  ADD_BUILTIN(gpio_dir);
  ADD_BUILTIN(gpio_amp);
  ADD_BUILTIN(gpio_slew);  
}
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
