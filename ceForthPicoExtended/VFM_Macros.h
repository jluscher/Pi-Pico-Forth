#include "Common.h"
/* Macro Assembler */
//
extern int32_t IMEDD;
extern int32_t COMPO;
extern int32_t BRAN, QBRAN, DONXT, DOTQP, STRQP, TOR, ABORQP;
//
#define GAP1  0
#define GAP2  0,0
#define GAP3  0,0,0
#define GAP4  0,0,0,0
#define GAP5  0,0,0,0,0
#define GAP6  0,0,0,0,0,0
#define GAP7  0,0,0,0,0,0,0
#define GAP8  0,0,0,0,0,0,0,0
#define GAP9  0,0,0,0,0,0,0,0,0
#define GAP10 0,0,0,0,0,0,0,0,0,0
#define GAP11 0,0,0,0,0,0,0,0,0,0,0
#define GAP12 0,0,0,0,0,0,0,0,0,0,0,0
#define GAP13 0,0,0,0,0,0,0,0,0,0,0,0,0
#define GAP14 0,0,0,0,0,0,0,0,0,0,0,0,0,0
#define GAP15 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
#define GAP16 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
#define GAP17 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
#define GAP18 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
#define GAP19 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
#define GAP20 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
#define GAP21 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
#define GAP22 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
#define GAP23 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
#define GAP24 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
//
#define iL int32_t
#define PARAM32_24 iL i0, iL i1, iL i2, iL i3, iL i4, iL i5, iL i6, iL i7, \
                   iL i8, iL i9, iL i10, iL i11, iL i12, iL i13, iL i14, iL i15, \
                   iL i16,iL i17,iL i18,iL i19,iL i20,iL i21,iL i22,iL i23
#define iS int8_t
#define PARAM08_08 iS c0, iS c1, iS c2, iS c3, iS c4, iS c5, iS c6, iS c7
//
void  HEADER(int32_t  , char *);
int32_t CODE(int32_t  , PARAM08_08); 
int32_t COLON(int32_t , PARAM32_24);
int32_t LABEL(int32_t , PARAM32_24); 
void BEGIN(int32_t    , PARAM32_24); 
void AGAIN(int32_t    , PARAM32_24); 
void UNTIL(int32_t    , PARAM32_24); 
void WHILE(int32_t    , PARAM32_24); 
void REPEAT(int32_t   , PARAM32_24); 
void IF(int32_t       , PARAM32_24);
void ELSE(int32_t     , PARAM32_24);
void THEN(int32_t     , PARAM32_24);
void FOR(int32_t      , PARAM32_24);
void NEXT(int32_t     , PARAM32_24);
void AFT(int32_t      , PARAM32_24);
void DOTQ(const char *);
void STRQ(const char *);
void ABORQ(const char *);
