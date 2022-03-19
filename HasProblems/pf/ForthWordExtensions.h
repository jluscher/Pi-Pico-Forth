#include "ForthHardwareGPIO.h"
#include "ForthHardwareADC.h"
//
#define ForthExtensions_Hardware_GPIO \
": gpio_lbls 30 0 do I dup . 9 < if 2 spaces else space then loop .\"  Bit# \" cr ;\n" \
": gpio_io dup  0= if drop .\" I \"  \
      else     1 = if      .\" O \" then then ;\n" \
": gpio_dirs 30 0 do I gpio_dir gpio_io 2 spaces loop .\" [Out/In](Dir) \" cr ;\n" \
": gpio_ma dup  0= if drop .\" 2 \"  2 else  \
           dup 1 = if drop .\" 4 \"  2 else  \
           dup 2 = if drop .\" 8 \"  2 else  \
               3 = if      .\" 12 \" 1 then then then then ;\n" \
": gpio_amps  30 0 do I gpio_amp gpio_ma spaces loop .\" [I](ma) \" cr ;\n" \
": gpio_speed dup  0= if drop .\" S \"  \
         else     1 = if      .\" F \" then then ;\n" \
": gpio_slews 30 0 do I gpio_getslew gpio_speed 2 spaces loop .\" [Fast/Slow](Slew) \" cr ;\n" \
": gpio_up? gpio_puq if -1 else 0 then ;\n" \
": gpio_dn? gpio_pdq if -1 else 0 then ;\n" \
": gpio_pulls? dup gpio_up? if .\" U \" drop exit then gpio_dn? if .\" D \" else .\" N \" then ;\n" \
": gpio_pulls 30 0 do I gpio_pulls? 2 spaces loop .\" [Up/None/Down](Pulls) \" cr ;\n" \
": gpio_hists? gpio_histq if .\" Y \" exit then .\" N \" ;\n" \
": gpio_hists 30 0 do I gpio_hists? 2 spaces loop .\" [Yes/No](Histo) \" cr ;\n"\
": gpio_vals? gpio_valq if .\" H \" exit then .\" L \" ;\n" \
": gpio_vals 30 0 do I gpio_vals? 2 spaces loop .\" [High/Low](Level) \" cr ;\n" \
": gpio gpio_lbls gpio_vals gpio_dirs gpio_amps gpio_slews gpio_pulls gpio_hists ;\n" \
": gpio_sio_init 30 0 do I gpio_sio loop ;\n" \
": gpio_dirs_out 30 0 do I -1 gpio_putdir loop ;\n" \
": gpio_dirs_in  30 0 do I  0 gpio_putdir loop ;\n" \
": gpio_set_bits 30 0 do I -1 gpio_putbit loop ;\n" \
": gpio_clr_bits 30 0 do I  0 gpio_putbit loop ;\n" \
": raw_temp adc_doinit 3 adc_gpioinit 3 adc_port adc_get ;\n"