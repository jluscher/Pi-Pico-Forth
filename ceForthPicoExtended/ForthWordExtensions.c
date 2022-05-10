#include "Common.h"
#include "ForthWordExtensions.h"
//
// 01234567890123456789012345678901234567890123456789012345678901234567901234567890
//
const char * gpio_word_extensions[] = { // replaced 30 0 do with 30 for, and loop with next. but I is missing also!
  ": piggy 8 for .\"  oink \" cr next ; ",
  ": poopy 8 for .\"  smelly \" cr next ; ",  
  "END",
  ": gpio_lbls 30 for I dup . 9 < if 2 spaces else space then next .\"  Bit# \" cr ; ",
  ": gpio_io dup 0= if drop .\" I \" else 1 = if .\" O \" then then ; ",
  ": gpio_dirs 30 for I GET_IO_DIR gpio_io 2 spaces next .\" [Out/In](Dir) \" cr ; ",
  ": gpio_ma dup  0= if drop .\" 2 \" 2 else dup 1 = if drop .\" 4 \"  2 else "
            "dup 2 = if drop .\" 8 \" 2 else 3 = if .\" 12 \" 1 then then then then ; ",
  ": gpio_amps  30 for I GET_IO_AMP gpio_ma spaces next .\" [I](ma) \" cr ; ",
  ": gpio_speed dup  0= if drop .\" S \" else 1 = if .\" F \" then then ; ",
	": gpio_slews 30 for I GET_IO_SLEW gpio_speed 2 spaces next .\" [Fast/Slow](Slew) \" cr ; ",
	": gpio_up? CHK_IO_PULL_UP? if -1 else 0 then ; ",
	": gpio_dn? CHK_IO_PULL_DN? if -1 else 0 then ; ",
	": gpio_pulls? dup gpio_up? if .\" U \" drop exit then gpio_dn? if .\" D \" else .\" N \" then ; ",
	": gpio_pulls 30 for I gpio_pulls? 2 spaces next .\" [Up/None/Down](Pulls) \" cr ; ",
	": gpio_hists? CHK_IO_HIST_ON? if .\" Y \" exit then .\" N \" ; ",
	": gpio_hists 30 for I gpio_hists? 2 spaces next .\" [Yes/No](Histo) \" cr ; ",
	": gpio_vals? GET_IO_BIT if .\" H \" exit then .\" L \" ; ",
	": gpio_vals 30 for I gpio_vals? 2 spaces next .\" [High/Low](Level) \" cr ; ",
	": gpio gpio_lbls gpio_vals gpio_dirs gpio_amps gpio_slews gpio_pulls gpio_hists ; ",
	": gpio_sio_init 30 for I SET_IO_BIT_SIO next ; ",
	": gpio_dirs_out 30 for I -1 SET_IO_BIT_DIR next ; ",
	": gpio_dirs_in  30 for I  0 SET_IO_BIT_DIR next ; ",
	": gpio_set_bits 30 for I -1 PUT_IO_BIT next ; ",
	": gpio_clr_bits 30 for I  0 PUT_IO_BIT next ; ",
  "END" 
};
//
const char * adc_word_extensions[] = {
  ": doggy 8 for .\"  woof \" cr next ; ",
  ": kity  8 for .\"  meow \" cr next ; ",  
  "END"
};
//
const char * spi_word_extensions[] = {
  ": birdy 8 for .\"  tweet \" cr next ; ",
  ": cow   8 for .\"  moo \" cr next ; ",  
  "END"
};
/*
: raw_temp adc_doinit 3 adc_gpioinit 3 adc_port adc_get ;"
*/
bool CompileWaiting = true;
bool CompileExtensions(void){ return(CompileWaiting); }
//
int32_t i=0, j=0;
enum { Start, Gpio, Adc, Spi, Done } States;
int32_t State = Start;
//
void NextState(void){
  switch (State){
    case Start: State = Gpio; return;    
    case Gpio:  State = Adc;  return;
    case Adc:   State = Spi;  return;
    case Spi:   State = Done; return;
    case Done:  return;
  }
}
//
char CompileThis(const char *these[]){
  do{
    if(strcmp(these[i], "END") == 0){ NextState(); i=0; j=0; return('\n'); } //next class of words
    if(j<strlen(these[i]))          { return(these[i][j++]); }
    i++; j=0; //next colon def in this list of strings
    return('\n');
  }while(true);
}
//
char OkCompile(void){
char thechar;
  switch (State){
    case Start: NextState(); thechar = '\n'; break;
    case Gpio:  thechar = CompileThis(gpio_word_extensions); break;
    case Adc:   thechar = CompileThis( adc_word_extensions); break;
    case Spi:   thechar = CompileThis( spi_word_extensions); break;
    case Done:  CompileWaiting = false; thechar = '\n';
  }
  return(thechar);
}
