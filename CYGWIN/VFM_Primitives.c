#include "Common.h"
//
extern MemoryImage *M;
//
/* Virtual Forth Machine */
//
void bye(void){ exit(0); }
//
void qrx(void){ 
#ifdef SERIAL_CHAR  
    push(long) serial_getchar(); 
#else
    push(long) getchar(); 
#endif
	if (M->top != 0) push TRUE;
}
//
void txsto(void)
{
#ifdef SERIAL_CHAR  
  serial_putchar((char)M->top);
#else
  putchar((char)M->top);
#endif  
	pop;
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
	push M->WP;
}
//
void docon(void)
{
	push M->data[M->WP >> 2];
}
//
void dolit(void)
{
	push M->data[M->IP >> 2];
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
	pop;
}
//
void donext(void)
{
	if (M->rack[M->R]) {
		M->rack[M->R] -= 1;
		M->IP = M->data[M->IP >> 2]; 
	}
	else {
		M->IP += 4;
		(M->R)--;
	}
	next();
}
//
void qbran(void)
{
	if (M->top == 0) M->IP = M->data[M->IP >> 2];
	else M->IP += 4;
	pop;
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
	pop;
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
	pop;
}
//
void cat(void)
{
	M->top = (long)M->cdata[M->top];
}
//
void rfrom(void)
{
	push M->rack[(M->R)--]; 
}
//
void rat(void)
{
	push M->rack[M->R]; 
}
//
void tor(void)
{
	M->rack[++(M->R)] = M->top; 
	pop;
}
//
void drop(void)
{
	pop;
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
	push M->stack[M->S - 1]; 
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
	push 1;
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
	pop;
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
	pop;
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
	pop;
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
	pop; pop;
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
	M->data[M->top >> 2] += M->stack[(M->S)--], pop; 
}
//
void dstor(void)
{
	M->data[(M->top >> 2) + 1] = M->stack[(M->S)--];
	M->data[M->top >> 2] = M->stack[(M->S)--]; 
	pop;
}
//
void dat(void)
{
	push M->data[M->top >> 2];
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
	if (M->top < M->stack[M->S]) pop;
	else (M->S)--; 
}
//
void min_(void)
{
	if (M->top < M->stack[M->S]) (M->S)--; 
	else pop;
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
  //gpio_dir, // 64
};