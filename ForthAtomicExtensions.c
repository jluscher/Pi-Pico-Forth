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
BUILTIN(74, "GPIO_PUQ", gpio_puq, 0)
{
    cell gpio = pop();
    cell pull = f_gpio_is_pulled_up(gpio);
    push(pull);
}
//
BUILTIN(75, "GPIO_PDQ", gpio_pdq, 0)
{
    cell gpio = pop();
    cell pull = f_gpio_is_pulled_down(gpio);
    push(pull);
}
//
BUILTIN(76, "GPIO_HISTQ", gpio_histq, 0)
{
    cell gpio = pop();
    cell hist = f_gpio_is_input_hysteresis_enabled(gpio);
    push(hist);
}
//
BUILTIN(77, "GPIO_VALQ", gpio_valq, 0)
{
    cell gpio = pop();
    cell value = f_gpio_get(gpio);
    push(value);
}
//
BUILTIN(78, "GPIO_SIO", gpio_sio, 0)
{
    cell gpio = pop();
    f_gpio_init(gpio);
}
//
BUILTIN(79, "GPIO_SETDIR", gpio_setdir, 0)
{
    cell dir  = pop();
    cell gpio = pop();
    f_gpio_set_dir(gpio, dir);
}
//
BUILTIN(80, "GPIO_PUTBIT", gpio_putbit, 0)
{
    cell state  = pop();
    cell gpio   = pop();
    f_gpio_put(gpio, state);
}
//
BUILTIN(81, "GPIO_DRIVE", gpio_drive, 0)
{
    cell drive  = pop();
    cell gpio   = pop();
    f_gpio_set_drive_strength(gpio, drive);
}
//
void MoreBuiltInAtomics(void){ // must increment MAX_BUILTIN_ID when adding to this. See top of Common.h
  ADD_BUILTIN(gpio_dir);
  ADD_BUILTIN(gpio_amp);
  ADD_BUILTIN(gpio_slew);
  ADD_BUILTIN(gpio_puq);
  ADD_BUILTIN(gpio_pdq);
  ADD_BUILTIN(gpio_histq);  
  ADD_BUILTIN(gpio_valq);   
  ADD_BUILTIN(gpio_sio);   
  ADD_BUILTIN(gpio_setdir);
  ADD_BUILTIN(gpio_putbit);  
  ADD_BUILTIN(gpio_drive);  
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
