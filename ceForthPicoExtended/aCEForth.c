/******************************************************************************/
/* DJW  (April 2022)                                                          */
/* Seperated Out Primitives, Macros, and HEADERS into new files.              */
/* Changed ambiguous Types to intxx_t Types                                   */
/* Put Memory under Typedef for eventual multi VFM instantiation.             */
/******************************************************************************/
/* ceForth_33.cpp, Version 3.3 : Forth in C                                   */
/******************************************************************************/
/* Chen-Hanson Ting                                                           */
/* 01jul19cht   version 3.3                                                   */
/* Macro assembler, Visual Studio 2019 Community                              */
/* 13jul17cht   version 2.3                                                   */
/* True byte code machine with bytecode                                       */
/* Change w to WP, pointing to parameter field                                */
/* 08jul17cht  version 2.2                                                    */
/* Stacks are 256 cell circular buffers                                       */
/* Clean up, delete SP@, SP!, RP@, RP!                                        */
/* 13jun17cht  version 2.1                                                    */
/* Compiled as a C++ console project in Visual Studio Community 2017          */
/* Follow the eForth model with 64 primitives                                 */
/* Kernel                                                                     */
/* Use int64_t to implement multipy and divide primitives                     */
/* Case insensitive interpreter                                               */
/* M->data[] must be filled with rom_21.h eForth dictionary                   */
/*   from c:/F#/ceforth_21                                                    */
/* C compiler must be reminded that S and R are (char) <-- "I doubt it, djw   */
/******************************************************************************/
//
/* Preamble */
#include "Common.h"
#include "VFM_Headers.h"
//
MemoryImage *M;
//
void PrepareMemory(MemoryImage *mptr){
	for(int i=0;i<MEMSIZE;i++)  { mptr->cdata[i] = (int8_t)  0; } // clear dictionary
	for(int i=0;i<STACKSIZE;i++){ mptr->stack[i] = (int32_t) 0; } // clear M->data M->stack
	for(int i=0;i<STACKSIZE;i++){ mptr->rack [i] = (int32_t) 0; } // clear return M->stack
	mptr->d   = (int64_t)0;
	mptr->n   = (int64_t)0;
	mptr->m   = (int64_t)0;
	mptr->R   = (int8_t)0;
	mptr->S   = (int8_t)0;
	mptr->top = 0;
	mptr->P   = 512; // kernel words location
	mptr->IP  = 0; 
	mptr->WP  = 0;
	mptr->thread  = 0;	
	M = mptr;
}
//
//#define DUMP_DICTIONARY
#ifdef DUMP_DICTIONARY
void CheckSum() {
	int i;
	char sum = 0;
	printf("\n%4X ", (unsigned int)M->P);
	for (i = 0; i < 16; i++) {
		sum += M->cdata[M->P];
		printf("%2X ", M->cdata[(M->P)++]);
	}
	printf(" %2X ", sum & 0XFF);
}
#endif
//
extern void(*primitives[PRIMITIVE_ARRAYSIZE])(void);
//
/*
* Main Program
*/
int CHT_Forth(MemoryImage *MP)
{
	PrepareMemory(MP);
	M->P = 512;
	M->R = 0;
  CompileHeaders();
  //
#ifdef DUMP_DICTIONARY 
  printf("\n\nIZ=%X M->R - M->stack=%X", (unsigned int)M->P, (unsigned int)(popR << 2));
	M->P = 0;
	for (int len = 0; len < 0x200; len++) { CheckSum(); }
#endif
  //
  // Boot Up
  //  
	M->P = 0;
	M->WP = 4;
	M->IP = 0;
	M->S = 0;
	M->R = 0;
	M->top = 0;
  // Run Virtual Forth Machine
	while (TRUE) { primitives[M->cdata[M->P++]](); }
}
