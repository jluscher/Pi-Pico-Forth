#include "VFM_Macros.h"
/* Macro Assembler */
//
extern MemoryImage *M;
//
int32_t IMEDD = 0x80;
int32_t COMPO = 0x40;
int32_t BRAN = 0, QBRAN = 0, DONXT = 0, DOTQP = 0, STRQP = 0, TOR = 0, ABORQP = 0;

void HEADER(int32_t lex, const char seq[]) {
	M->IP = M->P >> 2;
	int32_t i;
	int32_t len = lex & 31;
	M->data[(M->IP)++] = M->thread;
	M->P = M->IP << 2;
	/*print32_tf("\n%X",M->thread);*/
	/*for (i = M->thread >> 2; i < M->IP; i++)*/
	/*{	print32_tf(" %X",M->data[i]); }*/
	M->thread = M->P;
	M->cdata[(M->P)++] = lex;
	for (i = 0; i < len; i++)
	{
		M->cdata[(M->P)++] = seq[i];
	}
	while (M->P & 3) { M->cdata[(M->P)++] = 0; }
	//print32_tf("\n");
	//print32_tf("%s", seq);
	//print32_tf(" %X", (unsigned int32_t)P);
}
int32_t CODE(int32_t len, ...) {
	int32_t addr = M->P;
	va_list argList;
	va_start(argList, len);
	for (; len; len--) {
		int32_t j = va_arg(argList, int32_t);
		M->cdata[(M->P)++] = j;
		/*print32_tf(" %X",j);*/
	}
	va_end(argList);
	return addr;
}
int32_t COLON(int32_t len, ...) {
	int32_t addr = M->P;
	M->IP = M->P >> 2;
	M->data[(M->IP)++] = 6; /* dolist */
	va_list argList;
	va_start(argList, len);
	/*print32_tf(" %X ",6);*/
	for (; len; len--) {
		int32_t j = va_arg(argList, int32_t);
		M->data[(M->IP)++] = j;
		/*print32_tf(" %X",j);*/
	}
	M->P = M->IP << 2;
	va_end(argList);
	return addr;
}
int32_t LABEL(int32_t len, ...) {
	int32_t addr = M->P;
	M->IP = M->P >> 2;
	va_list argList;
	va_start(argList, len);
	/*print32_tf("\n%X ",addr);*/
	for (; len; len--) {
		int32_t j = va_arg(argList, int32_t);
		M->data[(M->IP)++] = j;
		/*print32_tf(" %X",j);*/
	}
	M->P = M->IP << 2;
	va_end(argList);
	return addr;
}
void BEGIN(int32_t len, ...) {
	M->IP = M->P >> 2;
	/*print32_tf("\n%X BEGIN ",M->P);*/
	pushR = M->IP;
	va_list argList;
	va_start(argList, len);
	for (; len; len--) {
		int32_t j = va_arg(argList, int32_t);
		M->data[(M->IP)++] = j;
		/*print32_tf(" %X",j);*/
	}
	M->P = M->IP << 2;
	va_end(argList);
}
void AGAIN(int32_t len, ...) {
	M->IP = M->P >> 2;
	/*print32_tf("\n%X AGAIN ",M->P);*/
	M->data[(M->IP)++] = BRAN;
	M->data[(M->IP)++] = popR << 2;
	va_list argList;
	va_start(argList, len);
	for (; len; len--) {
		int32_t j = va_arg(argList, int32_t);
		M->data[(M->IP)++] = j;
		/*print32_tf(" %X",j);*/
	}
	M->P = M->IP << 2;
	va_end(argList);
}
void UNTIL(int32_t len, ...) {
	M->IP = M->P >> 2;
	/*print32_tf("\n%X UNTIL ",M->P);*/
	M->data[(M->IP)++] = QBRAN;
	M->data[(M->IP)++] = popR << 2;
	va_list argList;
	va_start(argList, len);
	for (; len; len--) {
		int32_t j = va_arg(argList, int32_t);
		M->data[(M->IP)++] = j;
		/*print32_tf(" %X",j);*/
	}
	M->P = M->IP << 2;
	va_end(argList);
}
void WHILE(int32_t len, ...) {
	M->IP = M->P >> 2;
	int32_t k;
	/*print32_tf("\n%X WHILE ",M->P);*/
	M->data[(M->IP)++] = QBRAN;
	M->data[(M->IP)++] = 0;
	k = popR;
	pushR = (M->IP - 1);
	pushR = k;
	va_list argList;
	va_start(argList, len);
	for (; len; len--) {
		int32_t j = va_arg(argList, int32_t);
		M->data[(M->IP)++] = j;
		/*print32_tf(" %X",j);*/
	}
	M->P = M->IP << 2;
	va_end(argList);
}
void REPEAT(int32_t len, ...) {
	M->IP = M->P >> 2;
	/*print32_tf("\n%X REPEAT ",M->P);*/
	M->data[(M->IP)++] = BRAN;
	M->data[(M->IP)++] = popR << 2;
	M->data[popR] = M->IP << 2;
	va_list argList;
	va_start(argList, len);
	for (; len; len--) {
		int32_t j = va_arg(argList, int32_t);
		M->data[(M->IP)++] = j;
		/*print32_tf(" %X",j);*/
	}
	M->P = M->IP << 2;
	va_end(argList);
}
void IF(int32_t len, ...) {
	M->IP = M->P >> 2;
	/*print32_tf("\n%X IF ",M->P);*/
	M->data[(M->IP)++] = QBRAN;
	pushR = M->IP;
	M->data[(M->IP)++] = 0;
	va_list argList;
	va_start(argList, len);
	for (; len; len--) {
		int32_t j = va_arg(argList, int32_t);
		M->data[(M->IP)++] = j;
		/*print32_tf(" %X",j);*/
	}
	M->P = M->IP << 2;
	va_end(argList);
}
void ELSE(int32_t len, ...) {
	M->IP = M->P >> 2;
	/*print32_tf("\n%X ELSE ",M->P);*/
	M->data[(M->IP)++] = BRAN;
	M->data[(M->IP)++] = 0;
	M->data[popR] = M->IP << 2;
	pushR = M->IP - 1;
	va_list argList;
	va_start(argList, len);
	for (; len; len--) {
		int32_t j = va_arg(argList, int32_t);
		M->data[(M->IP)++] = j;
		/*print32_tf(" %X",j);*/
	}
	M->P = M->IP << 2;
	va_end(argList);
}
void THEN(int32_t len, ...) {
	M->IP = M->P >> 2;
	/*print32_tf("\n%X THEN ",M->P);*/
	M->data[popR] = M->IP << 2;
	va_list argList;
	va_start(argList, len);
	for (; len; len--) {
		int32_t j = va_arg(argList, int32_t);
		M->data[(M->IP)++] = j;
		/*print32_tf(" %X",j);*/
	}
	M->P = M->IP << 2;
	va_end(argList);
}
void FOR(int32_t len, ...) {
	M->IP = M->P >> 2;
	/*print32_tf("\n%X FOR ",M->P);*/
	M->data[(M->IP)++] = TOR;
	pushR = M->IP;
	va_list argList;
	va_start(argList, len);
	for (; len; len--) {
		int32_t j = va_arg(argList, int32_t);
		M->data[(M->IP)++] = j;
		/*print32_tf(" %X",j);*/
	}
	M->P = M->IP << 2;
	va_end(argList);
}
void NEXT(int32_t len, ...) {
	M->IP = M->P >> 2;
	/*print32_tf("\n%X NEXT ",M->P);*/
	M->data[(M->IP)++] = DONXT;
	M->data[(M->IP)++] = popR << 2;
	va_list argList;
	va_start(argList, len);
	for (; len; len--) {
		int32_t j = va_arg(argList, int32_t);
		M->data[(M->IP)++] = j;
		/*print32_tf(" %X",j);*/
	}
	M->P = M->IP << 2;
	va_end(argList);
}
void AFT(int32_t len, ...) {
	M->IP = M->P >> 2;
	int32_t k;
	/*print32_tf("\n%X AFT ",M->P);*/
	M->data[(M->IP)++] = BRAN;
	M->data[(M->IP)++] = 0;
	k = popR;
	pushR = M->IP;
	pushR = M->IP - 1;
	va_list argList;
	va_start(argList, len);
	for (; len; len--) {
		int32_t j = va_arg(argList, int32_t);
		M->data[(M->IP)++] = j;
		/*print32_tf(" %X",j);*/
	}
	M->P = M->IP << 2;
	va_end(argList);
}
void DOTQ(const char seq[]) {
	M->IP = M->P >> 2;
	int32_t i;
	int32_t len = strlen(seq);
	M->data[(M->IP)++] = DOTQP;
	M->P = M->IP << 2;
	M->cdata[(M->P)++] = len;
	for (i = 0; i < len; i++)
	{
		M->cdata[(M->P)++] = seq[i];
	}
	while (M->P & 3) { M->cdata[(M->P)++] = 0; }
	/*print32_tf("\n%X ",M->P);*/
	/*print32_tf(seq);*/
}
void STRQ(const char seq[]) {
	M->IP = M->P >> 2;
	int32_t i;
	int32_t len = strlen(seq);
	M->data[(M->IP)++] = STRQP;
	M->P = M->IP << 2;
	M->cdata[(M->P)++] = len;
	for (i = 0; i < len; i++)
	{
		M->cdata[(M->P)++] = seq[i];
	}
	while (M->P & 3) { M->cdata[(M->P)++] = 0; }
	/*print32_tf("\n%X ",M->P);*/
	/*print32_tf(seq);*/
}
void ABORQ(const char seq[]) {
	M->IP = M->P >> 2;
	int32_t i;
	int32_t len = strlen(seq);
	M->data[(M->IP)++] = ABORQP;
	M->P = M->IP << 2;
	M->cdata[(M->P)++] = len;
	for (i = 0; i < len; i++)
	{
		M->cdata[(M->P)++] = seq[i];
	}
	while (M->P & 3) { M->cdata[(M->P)++] = 0; }
	/*print32_tf("\n%X ",M->P);*/
	/*print32_tf(seq);*/
}
