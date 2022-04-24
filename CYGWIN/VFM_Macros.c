#include "VFM_Macros.h"
/* Macro Assembler */
//
#define NAME_LENGTH_MAX 31
extern MemoryImage *M;
//
int32_t IMEDD = 0x80;
int32_t COMPO = 0x40;
int32_t BRAN = 0, QBRAN = 0, DONXT = 0, DOTQP = 0, STRQP = 0, TOR = 0, ABORQP = 0;
//
#define ALIGN_IP M->IP = M->P >> 2
#define DEPOSIT_WORD_INC M->data[M->IP++] 
#define ALIGN_P M->P = M->IP << 2
#define DEPOSIT_BYTE_INC M->cdata[M->P++]
#define DEPOSIT_WORD_AT_POPR M->data[popR]
#define IP2R pushR = M->IP
#define R2IP M->data[(M->IP)++] = popR << 2
#define COPY_LENGTH_SEQ int32_t len = strlen(seq)
#define POPR_TO_TRASH int32_t k = popR
//
#define DEPOSIT_8BYTES_MAX \
  switch (len){ \
    case 8: \
      M->cdata[(M->P)+4] = c4; \
      M->cdata[(M->P)+5] = c5; \
      M->cdata[(M->P)+6] = c6; \
      M->cdata[(M->P)+7] = c7; \
    case 4: \
      M->cdata[(M->P)+0] = c0; \
      M->cdata[(M->P)+1] = c1; \
      M->cdata[(M->P)+2] = c2; \
      M->cdata[(M->P)+3] = c3; \
  } \
  switch (len){ \
    case 8: M->P += 8; break; \
    case 4: M->P += 4; break; \
  } 
//  
#define DEPOSIT_24INT32_MAX \
  switch (len){ \
    case 24: M->data[(M->IP)+23] = i23; \
    case 23: M->data[(M->IP)+22] = i22; \
    case 22: M->data[(M->IP)+21] = i21; \
    case 21: M->data[(M->IP)+20] = i20; \
    case 20: M->data[(M->IP)+19] = i19; \
    case 19: M->data[(M->IP)+18] = i18; \
    case 18: M->data[(M->IP)+17] = i17; \
    case 17: M->data[(M->IP)+16] = i16; \
    case 16: M->data[(M->IP)+15] = i15; \
    case 15: M->data[(M->IP)+14] = i14; \
    case 14: M->data[(M->IP)+13] = i13; \
    case 13: M->data[(M->IP)+12] = i12; \
    case 12: M->data[(M->IP)+11] = i11; \
    case 11: M->data[(M->IP)+10] = i10; \
    case 10: M->data[(M->IP)+9]  = i9;  \
    case 9:  M->data[(M->IP)+8]  = i8;  \
    case 8:  M->data[(M->IP)+7]  = i7;  \
    case 7:  M->data[(M->IP)+6]  = i6;  \
    case 6:  M->data[(M->IP)+5]  = i5;  \
    case 5:  M->data[(M->IP)+4]  = i4;  \
    case 4:  M->data[(M->IP)+3]  = i3;  \
    case 3:  M->data[(M->IP)+2]  = i2;  \
    case 2:  M->data[(M->IP)+1]  = i1;  \
    case 1:  M->data[(M->IP)+0]  = i0;  \
    case 0:  break;       \
  }  \
  switch (len){ \
    case 24: M->IP += 24; break; \
    case 23: M->IP += 23; break; \
    case 22: M->IP += 22; break; \
    case 21: M->IP += 21; break; \
    case 20: M->IP += 20; break; \
    case 19: M->IP += 19; break; \
    case 18: M->IP += 18; break; \
    case 17: M->IP += 17; break; \
    case 16: M->IP += 16; break; \
    case 15: M->IP += 15; break; \
    case 14: M->IP += 14; break; \
    case 13: M->IP += 13; break; \
    case 12: M->IP += 12; break; \
    case 11: M->IP += 11; break; \
    case 10: M->IP += 10; break; \
    case  9: M->IP +=  9; break; \
    case  8: M->IP +=  8; break; \
    case  7: M->IP +=  7; break; \
    case  6: M->IP +=  6; break; \
    case  5: M->IP +=  5; break; \
    case  4: M->IP +=  4; break; \
    case  3: M->IP +=  3; break; \
    case  2: M->IP +=  2; break; \
    case  1: M->IP +=  1; break; \
    case  0: M->IP +=  0; break; \
  } 
//
#define CRC_HEADER
#ifdef CRC_HEADER
char acrc32buf[48];
int32_t astart=512, anend = MEMSIZE-1;
char* acrc32b(char *s) {
   int32_t i, j;
   int32_t cnt = anend - astart;
   uint32_t abyte, crc, mask;
   //
   i = astart;
   crc = 0xFFFFFFFF;
   while (cnt-- >= 0){
      abyte = M->cdata[i];           
      crc = crc ^ abyte;
      for (j = 7; j >= 0; j--) {   
         mask = -(crc & 1);
         crc = (crc >> 1) ^ (0xEDB88320 & mask);
      }
      i++;
   }
   sprintf(acrc32buf,"%16s %8.8X \n", s, crc);
   astart = anend;
   return acrc32buf;
}
//void reportcrc(char* s){ Printbuf(acrc32b(s)); }
void reportcrc(char* s){ printf("%s",acrc32b(s)); }
#endif
//
void HEADER(int32_t lex,  char seq[]) {
  int32_t len = lex & 0x1F;        // seperate name length
  int32_t nfa = M->thread;         // thread == name field of prior word
  //
  ALIGN_IP ;                       // align Integer Pointer from Character Pointer  
#ifdef CRC_HEADER
  astart = M->P;  
#endif  
  DEPOSIT_WORD_INC = nfa;          // place the nfa
  ALIGN_P ;                        // update Character Pointer to match IP
  M->thread = M->P;                // thread == name field of current word  
  DEPOSIT_BYTE_INC = (int8_t) lex; // copy compile & immediate bits with length of name into dicitonary
  //
  for (int i = 0; i < len; i++){ DEPOSIT_BYTE_INC = seq[i]; }  // copy name chars into dictionary
  while (M->P & 3){ DEPOSIT_BYTE_INC = (char) 0; }             // pad name with zeros
  //
#ifdef CRC_HEADER
  anend = M->P; reportcrc(seq); 
#endif
}
//
int32_t CODE(int32_t len, PARAM08_08){
  int32_t addr = M->P;
  DEPOSIT_8BYTES_MAX 
  return(addr); // return nfa of this CODE
}
//
int32_t COLON(int32_t len,  PARAM32_24 ){
  int32_t addr = M->P;
  ALIGN_IP ;
  DEPOSIT_WORD_INC = 6; // {6 == as_dolist} 
  DEPOSIT_24INT32_MAX
  ALIGN_P ;
  return addr;
}
//
int32_t LABEL(int32_t len, PARAM32_24) {
	int32_t addr = M->P;
	ALIGN_IP ;
  DEPOSIT_24INT32_MAX
	ALIGN_P ;
	return addr;
}
//
void BEGIN(int32_t len, PARAM32_24) {
  ALIGN_IP ;
  IP2R ;
  DEPOSIT_24INT32_MAX 
  ALIGN_P ;
}
//
void AGAIN(int32_t len, PARAM32_24) {
  ALIGN_IP ;
  DEPOSIT_WORD_INC = BRAN;
  R2IP ;
  DEPOSIT_24INT32_MAX
  ALIGN_P ;
}
//
void UNTIL(int32_t len, PARAM32_24) {
	ALIGN_IP ;
	DEPOSIT_WORD_INC = QBRAN;
	R2IP ;
  DEPOSIT_WORD_INC = i0;
	ALIGN_P ;
}
//
void WHILE(int32_t len, PARAM32_24) {
	ALIGN_IP ;
	DEPOSIT_WORD_INC = QBRAN;
	DEPOSIT_WORD_INC = 0;
	POPR_TO_TRASH ;
	pushR = (M->IP - 1);
	pushR = k;
  DEPOSIT_24INT32_MAX 
	ALIGN_P ;
}
//
void REPEAT(int32_t len, PARAM32_24) {
  ALIGN_IP ;
  DEPOSIT_WORD_INC = BRAN;
  R2IP ;
  DEPOSIT_WORD_AT_POPR = M->IP << 2;
  DEPOSIT_24INT32_MAX 
  ALIGN_P ;
}
//
void IF(int32_t len, PARAM32_24) {
  ALIGN_IP ;
	DEPOSIT_WORD_INC = QBRAN;
  IP2R ;
	DEPOSIT_WORD_INC = 0;
  DEPOSIT_24INT32_MAX
	ALIGN_P ;
}
//
void ELSE(int32_t len, PARAM32_24) {
	ALIGN_IP ;
	DEPOSIT_WORD_INC = BRAN;
	DEPOSIT_WORD_INC = 0;
	DEPOSIT_WORD_AT_POPR = M->IP << 2;
	IP2R - 1;
  DEPOSIT_24INT32_MAX
  ALIGN_P ;
}
//
void THEN(int32_t len, PARAM32_24) {
	ALIGN_IP ;
	DEPOSIT_WORD_AT_POPR = M->IP << 2;
  DEPOSIT_24INT32_MAX
  ALIGN_P ;
}
void FOR(int32_t len, PARAM32_24) {
	ALIGN_IP ;
	DEPOSIT_WORD_INC = TOR;
	IP2R ;
  DEPOSIT_24INT32_MAX
  ALIGN_P ;
}
void NEXT(int32_t len, PARAM32_24) {
  ALIGN_IP ;
	/*print32_tf("\n%X NEXT ",M->P);*/
	DEPOSIT_WORD_INC = DONXT;
	R2IP ;
  DEPOSIT_24INT32_MAX
  ALIGN_P ;
}
void AFT(int32_t len, PARAM32_24) {
  ALIGN_IP ;
	DEPOSIT_WORD_INC = BRAN;
	DEPOSIT_WORD_INC = 0;
	POPR_TO_TRASH ;
	IP2R ;
	IP2R - 1;
  DEPOSIT_24INT32_MAX
  ALIGN_P ;
}
void DOTQ(const char seq[]) {
  ALIGN_IP ;
	COPY_LENGTH_SEQ;
	DEPOSIT_WORD_INC = DOTQP;
  ALIGN_P ;
	DEPOSIT_BYTE_INC = len;
	for (int32_t i = 0; i < len; i++){ DEPOSIT_BYTE_INC = seq[i]; }
	while (M->P & 3) { DEPOSIT_BYTE_INC = 0; }
}
void STRQ(const char seq[]) {
  ALIGN_IP ;
	COPY_LENGTH_SEQ;
	DEPOSIT_WORD_INC = STRQP;
  ALIGN_P ;
	DEPOSIT_BYTE_INC = len;
	for (int32_t i = 0; i < len; i++){ DEPOSIT_BYTE_INC = seq[i]; }
	while (M->P & 3) { DEPOSIT_BYTE_INC = 0; }
}
void ABORQ(const char seq[]) {
  ALIGN_IP ;
	COPY_LENGTH_SEQ;
	DEPOSIT_WORD_INC = ABORQP;
  ALIGN_P ;
	DEPOSIT_BYTE_INC = len;
	for (int32_t i = 0; i < len; i++){ DEPOSIT_BYTE_INC = seq[i]; }
	while (M->P & 3) { DEPOSIT_BYTE_INC = 0; }
}
