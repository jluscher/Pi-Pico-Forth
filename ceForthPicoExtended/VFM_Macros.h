#include "Common.h"
/* Macro Assembler */
//
extern int32_t IMEDD;
extern int32_t COMPO;
extern int32_t BRAN, QBRAN, DONXT, DOTQP, STRQP, TOR, ABORQP;

void HEADER(int32_t , const char *);
int32_t CODE(int32_t , ...);
int32_t COLON(int32_t , ...);
int32_t LABEL(int32_t , ...);
void BEGIN(int32_t , ...);
void AGAIN(int32_t , ...);
void UNTIL(int32_t , ...);
void WHILE(int32_t , ...);
void REPEAT(int32_t , ...);
void IF(int32_t , ...);
void ELSE(int32_t , ...);
void THEN(int32_t , ...);
void FOR(int32_t , ...);
void NEXT(int32_t , ...);
void AFT(int32_t , ...);
void DOTQ(const char *);
void STRQ(const char *);
void ABORQ(const char *);
