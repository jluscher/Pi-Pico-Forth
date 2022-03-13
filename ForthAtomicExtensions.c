#include <stdio.h>
#include "ForthHardwareGPIO.h"
#include "ForthHardwareADC.h"
#include "BlocksViaRamSPI.h"
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
BUILTIN(92, "SPI_ID_GET", spi_id_get, 0)
{
  unsigned int buf[4];
  dcell adr = (dcell)buf;
  f_flash_get_unique_id(adr);
  push((dcell)&buf[0]);
  push((dcell)&buf[1]);
  push((dcell)&buf[2]);
  push((dcell)&buf[3]);
}
//
BUILTIN(93, "SECTOR_ERASE", sector_erase, 0)
{
  cell sector = pop();
  f_flash_sector_erase(sector);
}
//
BUILTIN(94, "FLASH_STORE", flash_store, 0)
{
  dcell data        = dpop();
  cell PageNumber   = pop();
  cell SectorNumber = pop();
  f_flash_store(SectorNumber, PageNumber, data);//enter <sector page dataptr flash_page_list - >
}
//
BUILTIN(95, "FLASH_PAGE_LIST", flash_page_list, 0)
{
  cell Page   = pop(); // page is on top of stack
  cell Sector = pop(); // enter <sector page flash_page_list - >
  f_flash_page_list(Sector, Page);
}
//
BUILTIN(96, "FLASH_PAGE_PATTERN", flash_page_pattern, 0)
{
  cell Page    = pop(); //(a,b,C -)
  cell Sector  = pop(); //(a,B,c -)
  cell type    = pop(); //(A,b,c -) // enter <type sector page flash_page_pattern>
  dcell data  = (dcell)f_page_pattern(type);
  f_flash_store(Sector, Page, data);
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
  ADD_BUILTIN(spi_id_get); 
  ADD_BUILTIN(sector_erase); 
  ADD_BUILTIN(flash_store); 
  ADD_BUILTIN(flash_page_list); 
  ADD_BUILTIN(flash_page_pattern); 
}

