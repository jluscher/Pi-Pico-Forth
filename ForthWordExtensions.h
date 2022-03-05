#include "ForthAtomicExtensions.h"
//
#define ForthExtensions_0 \
": gpio_lbls 30 0 do I dup . 9 < if 2 spaces else space then loop .\"  Bit# \" cr ;\n" \
": gpio_io dup  0= if drop .\" I \"  \
      else     1 = if      .\" O \" then then ;\n" \
": gpio_dirs 30 0 do I gpio_dir gpio_io 2 spaces loop .\" Out/In \" cr ;\n" 
//
#define ForthExtensions_1 \
": gpio_ma dup  0= if drop .\" 2 \"  else  \
           dup 1 = if drop .\" 4 \"  else  \
           dup 2 = if drop .\" 8 \"  else  \
               3 = if drop .\" 12 \" then then then then ;\n" \
": gpio_amps  30 0 do I gpio_amp gpio_ma 2 spaces loop .\" ma \" cr ;\n" 
//
#define ForthExtensions_2 \
": gpio_speed dup  0= if drop .\" S \"  \
         else     1 = if      .\" F \" then then ;\n" \
": gpio_slews 30 0 do I gpio_slew gpio_speed 2 spaces loop .\" Fast/Slow \" cr ;\n" \
": gpio gpio_lbls gpio_dirs gpio_amps gpio_slews ;\n"
