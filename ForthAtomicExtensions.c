#include "ForthAtomicExtensions.h"
#include <stdio.h>
#include "hardware/gpio.h"
#include "hardware/adc.h"
//
void putkey(char);
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
BUILTIN(73, "GPIO_GETSLEW", gpio_getslew, 0)
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
BUILTIN(79, "GPIO_PUTDIR", gpio_putdir, 0)
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
BUILTIN(82, "GPIO_SETSLEW", gpio_setslew, 0)
{
    cell slew   = pop();
    cell gpio   = pop();
    f_gpio_set_slew_rate(gpio, slew);
}
//
BUILTIN(83, "CLS",      cls,            0)
{ 
                    // (char)27 == ESC{ape}
  putkey((char)27); // clear screen
  putkey('['     );
  putkey('2'     );
  putkey('J'     );  
  putkey((char)27); // home cursor
  putkey('['     );
  putkey('f'     );   
  putkey('\n'    );   
}
//
BUILTIN(84, "GPIO_NOPULL", gpio_nopull, 0)
{
  cell gpio   = pop();
  f_gpio_disable_pulls(gpio);
}
//
BUILTIN(85, "GPIO_PULLUP", gpio_pullup, 0)
{
  cell gpio   = pop();
  f_gpio_pull_up(gpio);
}
//
BUILTIN(86, "GPIO_PULLDN", gpio_pulldn, 0)
{
  cell gpio   = pop();
  f_gpio_pull_down(gpio);
}
//
BUILTIN(87, "GPIO_PUTHYSTO", gpio_puthysto, 0)
{
  cell hysto  = pop();
  cell gpio   = pop();
  f_gpio_set_input_hysteresis_enabled(gpio, hysto);
}
//
BUILTIN(88, "ADC_DOINIT", adc_doinit, 0)
{
  f_adc_init();
}
//
BUILTIN(89, "ADC_GPIOINIT", adc_gpioinit, 0)
{
  cell gpio   = pop();
  f_adc_gpio_init(gpio);
}
//
BUILTIN(90, "ADC_PORT", adc_port, 0)
{
  cell port   = pop();
  f_adc_select_input(port);
}
//
BUILTIN(91, "ADC_GET", adc_get, 0)
{
  push(f_adc_read());
}
//
void MoreBuiltInAtomics(void){ // must increment MAX_BUILTIN_ID when adding to this. See top of Common.h
  ADD_BUILTIN(gpio_dir);
  ADD_BUILTIN(gpio_amp);
  ADD_BUILTIN(gpio_getslew);
  ADD_BUILTIN(gpio_puq);
  ADD_BUILTIN(gpio_pdq);
  ADD_BUILTIN(gpio_histq);  
  ADD_BUILTIN(gpio_valq);   
  ADD_BUILTIN(gpio_sio);   
  ADD_BUILTIN(gpio_putdir);
  ADD_BUILTIN(gpio_putbit);  
  ADD_BUILTIN(gpio_drive);  
  ADD_BUILTIN(gpio_setslew); 
  ADD_BUILTIN(cls); 
  ADD_BUILTIN(gpio_nopull);  
  ADD_BUILTIN(gpio_pullup);  
  ADD_BUILTIN(gpio_pulldn); 
  ADD_BUILTIN(gpio_puthysto);
  ADD_BUILTIN(adc_doinit);
  ADD_BUILTIN(adc_gpioinit);  
  ADD_BUILTIN(adc_port);
  ADD_BUILTIN(adc_get);  
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
