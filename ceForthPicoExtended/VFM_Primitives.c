#include "Common.h"
#include "ForthWordExtensions.h"
#include "PicoPrimitivesADC.h"
#include "PicoPrimitivesGPIO.h"
#include "PicostoreSPI.h"
#include "Utilities.h"
//
extern MemoryImage *M;
//
/* Virtual Forth Machine */
//
void bye(void){ exit(0); }
//
#define SERIAL_CHAR
void qrx(void){ 
char thechar;  
  if (CompileExtensions()){ thechar =  OkCompile(); }
  else{
#ifdef SERIAL_CHAR  
        thechar = serial_getchar(); 
#else
        thechar = getchar(); 
#endif
  }
  pushS(long) thechar;
	if (M->top != 0) pushS TRUE;
}
//
void txsto(void)
{
#ifdef SERIAL_CHAR  
  serial_putchar((char)M->top);
#else
  putchar((char)M->top);
#endif  
	popS;
}
//
void next(void)
{
	M->P = M->data[M->IP >> 2];
	M->WP = M->P + 4;
	M->IP += 4;
}
//
void dovar(void)
{
	pushS M->WP;
}
//
void docon(void)
{
	pushS M->data[M->WP >> 2];
}
//
void dolit(void)
{
	pushS M->data[M->IP >> 2];
	M->IP += 4;
	next();
}
//
void dolist(void)
{
	M->rack[++(M->R)] = M->IP; 
	M->IP = M->WP;
	next();
}
//
void exitt(void)
{
	M->IP = (long)M->rack[(M->R)--]; 
	next();
}
//
void execu(void)
{
	M->P = M->top;
	M->WP = M->P + 4;
	popS;
}
//
void donext(void)
{
	if (M->rack[M->R]) {                // if top of R-stack element is non-zero
		M->rack[M->R] -= 1;                 // decrement top of R-stack element
		M->IP = M->data[M->IP >> 2];        // continue interpreting at start of loop
	} else {                            // else
		M->IP += 4;                         // step interpreter pointer to next cell
		(M->R)--;                           // DROP top element from R-stack
	} next();                           // resume interpreting
}
//
void qbran(void)
{
	if (M->top == 0) M->IP = M->data[M->IP >> 2];
	else M->IP += 4;
	popS;
	next();
}
//
void bran(void)
{
	M->IP = M->data[M->IP >> 2];
	next();
}
//
void store(void)
{
	M->data[M->top >> 2] = M->stack[M->S--]; 
	popS;
}
//
void at(void)
{
	M->top = M->data[M->top >> 2];
}
//
void cstor(void)
{
	M->cdata[M->top] = (char)M->stack[M->S--]; 
	popS;
}
//
void cat(void)
{
	M->top = (long)M->cdata[M->top];
}
//
void rfrom(void)
{
	pushS M->rack[(M->R)--]; 
}
//
void rat(void)
{
	pushS M->rack[M->R]; 
}
//
void tor(void)
{
	M->rack[++(M->R)] = M->top; 
	popS;
}
//
void drop(void)
{
	popS;
}
//
void dup(void)
{
	M->stack[++(M->S)] = M->top; 
}
//
void swap(void)
{
	M->WP = M->top;
	M->top = M->stack[M->S]; 
	M->stack[M->S] = M->WP;    
}
//
void over(void)
{
	pushS M->stack[M->S - 1]; 
}
//
void zless(void)
{
	M->top = (M->top < 0) LOGICAL;
}
//
void andd(void)
{
	M->top &= M->stack[M->S--]; 
}
//
void orr(void)
{
	M->top |= M->stack[M->S--]; 
}
//
void xorr(void)
{
	M->top ^= M->stack[M->S--]; 
}
//
void uplus(void)
{
	M->stack[M->S] += M->top;
	M->top = LOWER(M->stack[M->S], M->top); 
}
//
void nop(void)
{
	next();
}
//
void qdup(void)
{
	if (M->top) M->stack[++(M->S)] = M->top; 
}
//
void rot(void)
{
	M->WP = M->stack[M->S - 1];
	M->stack[M->S - 1] = M->stack[M->S];
	M->stack[M->S] = M->top; 
	M->top = M->WP;
}
//
void ddrop(void)
{
	drop(); drop();
}
//
void ddup(void)
{
	over(); over();
}
//
void plus(void)
{
	M->top += M->stack[(M->S)--]; 
}
//
void inver(void)
{
	M->top = -M->top - 1;
}
//
void negat(void)
{
	M->top = 0 - M->top;
}
//
void dnega(void)
{
	inver();
	tor();
	inver();
	pushS 1;
	uplus();
	rfrom();
	plus();
}
//
void subb(void)
{
	M->top = M->stack[(M->S)--] - M->top; 
}
//
void abss(void)
{
	if (M->top < 0)
		M->top = -(M->top);
}
//
void great(void)
{
	M->top = (M->stack[(M->S)--] > M->top) LOGICAL; 
}
//
void less(void)
{
	M->top = (M->stack[(M->S)--] < M->top) LOGICAL; 
}
//
void equal(void)
{
	M->top = (M->stack[(M->S)--] == M->top) LOGICAL; 
}
//
void uless(void)
{
	M->top = LOWER(M->stack[M->S], M->top) LOGICAL; (M->S)--; 
}
//
void ummod(void)
{
	M->d = (int64_t)((uint64_t)M->top);
	M->m = (int64_t)((uint64_t)M->stack[M->S]);
	M->n = (int64_t)((uint64_t)M->stack[M->S - 1]); 
	M->n += M->m << 32;
	popS;
	M->top = (uint64_t)(M->n / M->d);
	M->stack[M->S] = (uint64_t)(M->n % M->d);   
}
//
void msmod(void)
{
	M->d = (int64_t)((signed long)M->top);
	M->m = (int64_t)((signed long)M->stack[M->S]);
	M->n = (int64_t)((signed long)M->stack[M->S - 1]); 
	M->n += M->m << 32;
	popS;
	M->top = (signed long)(M->n / M->d);
	M->stack[M->S] = (signed long)(M->n % M->d); 
}
//
void slmod(void)
{
	if (M->top != 0) {
		M->WP = M->stack[M->S] / M->top;
		M->stack[M->S] %= M->top; 
		M->top = M->WP;
	}
}
//
void mod(void)
{
	M->top = (M->top) ? M->stack[(M->S)--] % M->top : M->stack[(M->S)--]; 
}
//
void slash(void)
{
	M->top = (M->top) ? M->stack[(M->S)--] / M->top : (M->stack[(M->S)--], 0); 
}
//
void umsta(void)
{
	M->d = (uint64_t)M->top;
	M->m = (uint64_t)M->stack[M->S]; 
	M->m *= M->d;
	M->top = (uint64_t)(M->m >> 32);
	M->stack[M->S] = (uint64_t)M->m; 
}
//
void star(void)
{
	M->top *= M->stack[(M->S)--]; 
}
//
void mstar(void)
{
	M->d = (int64_t)M->top;
	M->m = (int64_t)M->stack[M->S];     
	M->m *= M->d;
	M->top = (signed long)(M->m >> 32);
	M->stack[M->S] = (signed long)M->m; 
}
//
void ssmod(void)
{
	M->d = (int64_t)M->top;
	M->m = (int64_t)M->stack[M->S];
	M->n = (int64_t)M->stack[(M->S) - 1]; 
	M->n *= M->m;
	popS;
	M->top = (signed long)(M->n / M->d);
	M->stack[M->S] = (signed long)(M->n % M->d); 
}
//
void stasl(void)
{
	M->d = (int64_t)M->top;
	M->m = (int64_t)M->stack[M->S];
	M->n = (int64_t)M->stack[(M->S) - 1]; 
	M->n *= M->m;
	popS; popS;
	M->top = (signed long)(M->n / M->d);
}
//
void pick(void)
{
	M->top = M->stack[(M->S) - (int8_t)M->top]; 
}
//
void pstor(void)
{
	M->data[M->top >> 2] += M->stack[(M->S)--], popS; 
}
//
void dstor(void)
{
	M->data[(M->top >> 2) + 1] = M->stack[(M->S)--];
	M->data[M->top >> 2] = M->stack[(M->S)--]; 
	popS;
}
//
void dat(void)
{
	pushS M->data[M->top >> 2];
	M->top = M->data[(M->top >> 2) + 1];
}
//
void count(void)
{
	M->stack[++(M->S)] = M->top + 1; 
	M->top = M->cdata[M->top];
}
//
void max_(void)
{
	if (M->top < M->stack[M->S]) popS;
	else (M->S)--; 
}
//
void min_(void)
{
	if (M->top < M->stack[M->S]) (M->S)--; 
	else popS;
}
//
void(*primitives[PRIMITIVE_ARRAYSIZE])(void) = {
	/* case 0 */ nop,
	/* case 1 */ bye,
	/* case 2 */ qrx,
	/* case 3 */ txsto,
	/* case 4 */ docon,
	/* case 5 */ dolit,
	/* case 6 */ dolist,
	/* case 7 */ exitt,
	/* case 8 */ execu,
	/* case 9 */ donext,
	/* case 10 */ qbran,
	/* case 11 */ bran,
	/* case 12 */ store,
	/* case 13 */ at,
	/* case 14 */ cstor,
	/* case 15 */ cat,
	/* case 16  rpat, */ nop,
	/* case 17  rpsto, */ nop,
	/* case 18 */ rfrom,
	/* case 19 */ rat,
	/* case 20 */ tor,
	/* case 21 spat, */ nop,
	/* case 22 spsto, */ nop,
	/* case 23 */ drop,
	/* case 24 */ dup,
	/* case 25 */ swap,
	/* case 26 */ over,
	/* case 27 */ zless,
	/* case 28 */ andd,
	/* case 29 */ orr,
	/* case 30 */ xorr,
	/* case 31 */ uplus,
	/* case 32 */ next,
	/* case 33 */ qdup,
	/* case 34 */ rot,
	/* case 35 */ ddrop,
	/* case 36 */ ddup,
	/* case 37 */ plus,
	/* case 38 */ inver,
	/* case 39 */ negat,
	/* case 40 */ dnega,
	/* case 41 */ subb,
	/* case 42 */ abss,
	/* case 43 */ equal,
	/* case 44 */ uless,
	/* case 45 */ less,
	/* case 46 */ ummod,
	/* case 47 */ msmod,
	/* case 48 */ slmod,
	/* case 49 */ mod,
	/* case 50 */ slash,
	/* case 51 */ umsta,
	/* case 52 */ star,
	/* case 53 */ mstar,
	/* case 54 */ ssmod,
	/* case 55 */ stasl,
	/* case 56 */ pick,
	/* case 57 */ pstor,
	/* case 58 */ dstor,
	/* case 59 */ dat,
	/* case 60 */ count,
	/* case 61 */ dovar,
	/* case 62 */ max_,
	/* case 63 */ min_
#ifndef EXTENSIONS
};
#else
,
  f_temp_on,          // 64 PICO ADC
  f_temp_off,         // 65                  
  f_adc_init,         // 66
  f_adc_gpio_init,    // 67
  f_adc_select_input, // 68
  f_adc_read          // 69
,
 f_gpio_get_dir,                     // 70 PICO GPIO
 f_gpio_get_drive_strength,          // 71
 f_gpio_get_slew_rate,               // 72
 f_gpio_disable_pulls,               // 73
 f_gpio_pull_up,                     // 74
 f_gpio_pull_down,                   // 75
 f_gpio_is_pulled_up,                // 76
 f_gpio_is_pulled_down,              // 77
 f_gpio_is_input_hysteresis_enabled, // 78
 f_gpio_get,                         // 79
 f_gpio_init,                        // 80
 f_gpio_set_dir,                     // 81
 f_gpio_put,                         // 82
 f_gpio_set_drive_strength,          // 83
 f_gpio_set_slew_rate,               // 84
 f_gpio_set_input_hysteresis_enabled // 85
,
 f_flash_sector_erase,               // 86
 f_flash_store,                      // 87
 f_flash_page_list,                  // 88
 f_flash_get_unique_id,              // 89
 f_page_pattern,                     // 90
 f_WipeAllSectors                    // 91
};
#endif
