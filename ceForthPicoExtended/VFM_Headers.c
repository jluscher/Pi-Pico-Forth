#include "VFM_Macros.h"
#include "VFM_Primitives.h"
#include "PicoPrimitivesGPIO.h"
#include "PicoPrimitivesADC.h"
#include "Utilities.h"
//
extern MemoryImage *M;
//
void CompileVFM_Headers(void){
	/* Kernel */
	HEADER(3, "HLD");
  	int32_t HLD = VFM_CODE(8, as_docon, as_next, 0, 0, 0X80, 0, 0, 0);
	HEADER(4, "SPAN");
  	int32_t SPAN = VFM_CODE(8, as_docon, as_next, 0, 0, 0X84, 0, 0, 0);
	HEADER(3, ">IN");
    int32_t INN = VFM_CODE(8, as_docon, as_next, 0, 0, 0X88, 0, 0, 0); 
	HEADER(4, "#TIB");
	int32_t NTIB = VFM_CODE(8, as_docon, as_next, 0, 0, 0X8C, 0, 0, 0);
	HEADER(4, "'TIB");
	int32_t TTIB = VFM_CODE(8, as_docon, as_next, 0, 0, 0X90, 0, 0, 0);
	HEADER(4, "BASE");
	int32_t BASE = VFM_CODE(8, as_docon, as_next, 0, 0, 0X94, 0, 0, 0);
	HEADER(7, "CONTEXT");
	int32_t CNTXT = VFM_CODE(8, as_docon, as_next, 0, 0, 0X98, 0, 0, 0);
	HEADER(2, "CP");
	int32_t CP = VFM_CODE(8, as_docon, as_next, 0, 0, 0X9C, 0, 0, 0);
	HEADER(4, "LAST");
	int32_t LAST = VFM_CODE(8, as_docon, as_next, 0, 0, 0XA0, 0, 0, 0);
	HEADER(5, "'EVAL");
	int32_t TEVAL = VFM_CODE(8, as_docon, as_next, 0, 0, 0XA4, 0, 0, 0);
	HEADER(6, "'ABORT");
	int32_t TABRT = VFM_CODE(8, as_docon, as_next, 0, 0, 0XA8, 0, 0, 0);
	HEADER(3, "tmp");
	int32_t TEMP = VFM_CODE(8, as_docon, as_next, 0, 0, 0XAC, 0, 0, 0);

	HEADER(3, "NOP");
	  int32_t NOP = VFM_CODE(4, as_next, 0, 0, 0, GAP4);
	HEADER(3, "BYE");
	int32_t BYE = VFM_CODE(4, as_bye, as_next, 0, 0, GAP4);
	HEADER(3, "?RX");
	int32_t QRX = VFM_CODE(4, as_qrx, as_next, 0, 0, GAP4);
	HEADER(3, "TX!");
	int32_t TXSTO = VFM_CODE(4, as_txsto, as_next, 0, 0, GAP4);
	HEADER(5, "DOCON");
	int32_t DOCON = VFM_CODE(4, as_docon, as_next, 0, 0, GAP4);
	HEADER(5, "DOLIT");
	int32_t DOLIT = VFM_CODE(4, as_dolit, as_next, 0, 0, GAP4);
	HEADER(6, "DOLIST");
	int32_t DOLST = VFM_CODE(4, as_dolist, as_next, 0, 0, GAP4);
	HEADER(4, "EXIT");
	int32_t EXITT = VFM_CODE(4, as_exit, as_next, 0, 0, GAP4);
	HEADER(7, "EXECUTE");
	int32_t EXECU = VFM_CODE(4, as_execu, as_next, 0, 0, GAP4);
	HEADER(6, "DONEXT");
	DONXT = VFM_CODE(4, as_donext, as_next, 0, 0, GAP4);
	HEADER(7, "QBRANCH");
	QBRAN = VFM_CODE(4, as_qbran, as_next, 0, 0, GAP4);
	HEADER(6, "BRANCH");
	BRAN = VFM_CODE(4, as_bran, as_next, 0, 0, GAP4);
	HEADER(1, "!");
	int32_t STORE = VFM_CODE(4, as_store, as_next, 0, 0, GAP4);
	HEADER(1, "@");
	int32_t AT = VFM_CODE(4, as_at, as_next, 0, 0, GAP4);
	HEADER(2, "C!");
	int32_t CSTOR = VFM_CODE(4, as_cstor, as_next, 0, 0, GAP4);
	HEADER(2, "C@");
	int32_t CAT = VFM_CODE(4, as_cat, as_next, 0, 0, GAP4);
	HEADER(2, "R>");
	int32_t RFROM = VFM_CODE(4, as_rfrom, as_next, 0, 0, GAP4);
	HEADER(2, "R@");
	int32_t RAT = VFM_CODE(4, as_rat, as_next, 0, 0, GAP4);
	HEADER(2, ">R");
	TOR = VFM_CODE(4, as_tor, as_next, 0, 0, GAP4);
	HEADER(4, "DROP");
	int32_t DROP = VFM_CODE(4, as_drop, as_next, 0, 0, GAP4);
	HEADER(3, "DUP");
	int32_t DUPP = VFM_CODE(4, as_dup, as_next, 0, 0, GAP4);
	HEADER(4, "SWAP");
	int32_t SWAP = VFM_CODE(4, as_swap, as_next, 0, 0, GAP4);
	HEADER(4, "OVER");
	int32_t OVER = VFM_CODE(4, as_over, as_next, 0, 0, GAP4);
	HEADER(2, "0<");
	int32_t ZLESS = VFM_CODE(4, as_zless, as_next, 0, 0, GAP4);
	HEADER(3, "AND");
	int32_t ANDD = VFM_CODE(4, as_andd, as_next, 0, 0, GAP4);
	HEADER(2, "OR");
	int32_t ORR = VFM_CODE(4, as_orr, as_next, 0, 0, GAP4);
	HEADER(3, "XOR");
	int32_t XORR = VFM_CODE(4, as_xorr, as_next, 0, 0, GAP4);
	HEADER(3, "UM+");
	int32_t UPLUS = VFM_CODE(4, as_uplus, as_next, 0, 0, GAP4);
	HEADER(4, "NEXT");
	int32_t NEXTT = VFM_CODE(4, as_next, as_next, 0, 0, GAP4);
	HEADER(4, "?DUP");
	int32_t QDUP = VFM_CODE(4, as_qdup, as_next, 0, 0, GAP4);
	HEADER(3, "ROT");
	int32_t ROT = VFM_CODE(4, as_rot, as_next, 0, 0, GAP4);
	HEADER(5, "2DROP");
	int32_t DDROP = VFM_CODE(4, as_ddrop, as_next, 0, 0, GAP4);
	HEADER(4, "2DUP");
	int32_t DDUP = VFM_CODE(4, as_ddup, as_next, 0, 0, GAP4);
	HEADER(1, "+");
	int32_t PLUS = VFM_CODE(4, as_plus, as_next, 0, 0, GAP4);
	HEADER(3, "NOT");
	int32_t INVER = VFM_CODE(4, as_inver, as_next, 0, 0, GAP4);
	HEADER(6, "NEGATE");
	int32_t NEGAT = VFM_CODE(4, as_negat, as_next, 0, 0, GAP4);
	HEADER(7, "DNEGATE");
	int32_t DNEGA = VFM_CODE(4, as_dnega, as_next, 0, 0, GAP4);
	HEADER(1, "-");
	int32_t SUBBB = VFM_CODE(4, as_subb, as_next, 0, 0, GAP4);
	HEADER(3, "ABS");
	int32_t ABSS = VFM_CODE(4, as_abss, as_next, 0, 0, GAP4);
	HEADER(1, "=");
	int32_t EQUAL = VFM_CODE(4, as_equal, as_next, 0, 0, GAP4);
	HEADER(2, "U<");
	int32_t ULESS = VFM_CODE(4, as_uless, as_next, 0, 0, GAP4);
	HEADER(1, "<");
	int32_t LESS = VFM_CODE(4, as_less, as_next, 0, 0, GAP4);
	HEADER(6, "UM/MOD");
	int32_t UMMOD = VFM_CODE(4, as_ummod, as_next, 0, 0, GAP4);
	HEADER(5, "M/MOD");
	int32_t MSMOD = VFM_CODE(4, as_msmod, as_next, 0, 0, GAP4);
	HEADER(4, "/MOD");
	int32_t SLMOD = VFM_CODE(4, as_slmod, as_next, 0, 0, GAP4);
	HEADER(3, "MOD");
	int32_t MODD = VFM_CODE(4, as_mod, as_next, 0, 0, GAP4);
	HEADER(1, "/");
	int32_t SLASH = VFM_CODE(4, as_slash, as_next, 0, 0, GAP4);
	HEADER(3, "UM*");
	int32_t UMSTA = VFM_CODE(4, as_umsta, as_next, 0, 0, GAP4);
	HEADER(1, "*");
	int32_t STAR = VFM_CODE(4, as_star, as_next, 0, 0, GAP4);
	HEADER(2, "M*");
	int32_t MSTAR = VFM_CODE(4, as_mstar, as_next, 0, 0, GAP4);
	HEADER(5, "*/MOD");
	int32_t SSMOD = VFM_CODE(4, as_ssmod, as_next, 0, 0, GAP4);
	HEADER(2, "*/");
	int32_t STASL = VFM_CODE(4, as_stasl, as_next, 0, 0, GAP4);
	HEADER(4, "PICK");
	int32_t PICK = VFM_CODE(4, as_pick, as_next, 0, 0, GAP4);
	HEADER(2, "+!");
	int32_t PSTOR = VFM_CODE(4, as_pstor, as_next, 0, 0, GAP4);
	HEADER(2, "2!");
	int32_t DSTOR = VFM_CODE(4, as_dstor, as_next, 0, 0, GAP4);
	HEADER(2, "2@");
	int32_t DAT = VFM_CODE(4, as_dat, as_next, 0, 0, GAP4);
	HEADER(5, "COUNT");
	int32_t COUNT = VFM_CODE(4, as_count, as_next, 0, 0, GAP4);
	HEADER(3, "MAX");
	int32_t MAX = VFM_CODE(4, as_max, as_next, 0, 0, GAP4);
	HEADER(3, "MIN");
	int32_t MIN = VFM_CODE(4, as_min, as_next, 0, 0, GAP4);
	HEADER(2, "BL");
	int32_t BLANK = VFM_CODE(8, as_docon, as_next, 0, 0, 32, 0, 0, 0);
  HEADER(3, "TAB"); // DJW
  int32_t TAB = VFM_CODE(8, as_docon, as_next, 0, 0, 9, 0, 0, 0);  
	HEADER(4, "CELL");
	int32_t CELL = VFM_CODE(8, as_docon, as_next, 0, 0, 4, 0, 0, 0);
	HEADER(5, "CELL+");
	int32_t CELLP = VFM_CODE(8, as_docon, as_plus, as_next, 0, 4, 0, 0, 0);
	HEADER(5, "CELL-");
	int32_t CELLM = VFM_CODE(8, as_docon, as_subb, as_next, 0, 4, 0, 0, 0);
	HEADER(5, "CELLS");
	int32_t CELLS = VFM_CODE(8, as_docon, as_star, as_next, 0, 4, 0, 0, 0);
	HEADER(5, "CELL/");
	int32_t CELLD = VFM_CODE(8, as_docon, as_slash, as_next, 0, 4, 0, 0, 0);
	HEADER(2, "1+");
	int32_t ONEP = VFM_CODE(8, as_docon, as_plus, as_next, 0, 1, 0, 0, 0);
	HEADER(2, "1-");
	int32_t ONEM = VFM_CODE(8, as_docon, as_subb, as_next, 0, 1, 0, 0, 0);
	HEADER(5, "DOVAR");
	int32_t DOVAR = VFM_CODE(4, as_dovar, as_next, 0, 0, GAP4);
	/* Common Colon Words */

	HEADER(4, "?KEY");
	int32_t QKEY = COLON(2, QRX, EXITT, GAP22);
	HEADER(3, "KEY");
	int32_t KEY = COLON(0, GAP24);
	BEGIN(1, QKEY, GAP23);
	UNTIL(1, EXITT, GAP23);
	HEADER(4, "EMIT");
	int32_t EMIT = COLON(2, TXSTO, EXITT, GAP22);
	HEADER(6, "WITHIN");
	int32_t WITHI = COLON(7, OVER, SUBBB, TOR, SUBBB, RFROM, ULESS, EXITT, GAP17);
	HEADER(5, ">CHAR");
	int32_t TCHAR = COLON(8, DOLIT, 0x7F, ANDD, DUPP, DOLIT, 0X7F, BLANK, WITHI, GAP16);
	IF(3, DROP, DOLIT, 0X5F, GAP21);
	THEN(1, EXITT, GAP23);
	HEADER(7, "ALIGNED");
	int32_t ALIGN = COLON(7, DOLIT, 3, PLUS, DOLIT, 0XFFFFFFFC, ANDD, EXITT, GAP17);
	HEADER(4, "HERE");
	int32_t HERE = COLON(3, CP, AT, EXITT, GAP21);
	HEADER(3, "PAD");
	int32_t PAD = COLON(5, HERE, DOLIT, 0X50, PLUS, EXITT, GAP19);
	HEADER(3, "TIB");
	int32_t TIB = COLON(3, TTIB, AT, EXITT, GAP21);
	HEADER(8, "@EXECUTE");
	int32_t ATEXE = COLON(2, AT, QDUP, GAP22);
	IF(1, EXECU, GAP23);
	THEN(1, EXITT, GAP23);
	HEADER(5, "CMOVE");
	int32_t CMOVEE = COLON(0,GAP24);
	FOR(0, GAP24);
	AFT(8, OVER, CAT, OVER, CSTOR, TOR, ONEP, RFROM, ONEP, GAP16);
	THEN(0, GAP24);
	NEXT(2, DDROP, EXITT, GAP22);
	HEADER(4, "MOVE");
	int32_t MOVE = COLON(1, CELLD, GAP23);
	FOR(0, GAP24);
	AFT(8, OVER, AT, OVER, STORE, TOR, CELLP, RFROM, CELLP, GAP16);
	THEN(0, GAP24);
	NEXT(2, DDROP, EXITT, GAP22);
	HEADER(4, "FILL");
	int32_t FILL = COLON(1, SWAP, GAP23);
	FOR(1, SWAP, GAP23);
	AFT(3, DDUP, CSTOR, ONEP, GAP21);
	THEN(0, GAP24);
	NEXT(2, DDROP, EXITT, GAP22);

	/* Number Conversions */

	HEADER(5, "DIGIT");
	int32_t DIGIT = COLON(12, DOLIT, 9, OVER, LESS, DOLIT, 7, ANDD, PLUS, DOLIT, 0X30, PLUS, EXITT, GAP12);
	HEADER(7, "EXTRACT");
	int32_t EXTRC = COLON(7, DOLIT, 0, SWAP, UMMOD, SWAP, DIGIT, EXITT, GAP17);
	HEADER(2, "<#");
	int32_t BDIGS = COLON(4, PAD, HLD, STORE, EXITT, GAP20);
	HEADER(4, "HOLD");
	int32_t HOLD = COLON(8, HLD, AT, ONEM, DUPP, HLD, STORE, CSTOR, EXITT, GAP16);
	HEADER(1, "#");
	int32_t DIG = COLON(5, BASE, AT, EXTRC, HOLD, EXITT, GAP19);
	HEADER(2, "#S");
	int32_t DIGS = COLON(0, GAP24);
	BEGIN(2, DIG, DUPP, GAP22);
	WHILE(0, GAP24);
	REPEAT(1, EXITT, GAP23);
	HEADER(4, "SIGN");
	int32_t SIGN = COLON(1, ZLESS, GAP23);
	IF(3, DOLIT, 0X2D, HOLD, GAP21);
	THEN(1, EXITT, GAP23);
	HEADER(2, "#>");
	int32_t EDIGS = COLON(7, DROP, HLD, AT, PAD, OVER, SUBBB, EXITT, GAP17);
	HEADER(3, "str");
	int32_t STRR = COLON(9, DUPP, TOR, ABSS, BDIGS, DIGS, RFROM, SIGN, EDIGS, EXITT, GAP15);
	HEADER(3, "HEX");
	int32_t HEXX = COLON(5, DOLIT, 16, BASE, STORE, EXITT, GAP19);
	HEADER(7, "DECIMAL");
	int32_t DECIM = COLON(5, DOLIT, 10, BASE, STORE, EXITT, GAP19);
	HEADER(6, "wupper");
	int32_t UPPER = COLON(4, DOLIT, 0x5F5F5F5F, ANDD, EXITT, GAP20);
	HEADER(6, ">upper");
	int32_t TOUPP = COLON(6, DUPP, DOLIT, 0x61, DOLIT, 0x7B, WITHI, GAP18);
	IF(3, DOLIT, 0x5F, ANDD, GAP21);
	THEN(1, EXITT, GAP23);
	HEADER(6, "DIGIT?");
	int32_t DIGTQ = COLON(9, TOR, TOUPP, DOLIT, 0X30, SUBBB, DOLIT, 9, OVER, LESS, GAP15);
	IF(8, DOLIT, 7, SUBBB, DUPP, DOLIT, 10, LESS, ORR, GAP16);
	THEN(4, DUPP, RFROM, ULESS, EXITT, GAP20);
	HEADER(7, "NUMBER?");
	int32_t NUMBQ = COLON(12, BASE, AT, TOR, DOLIT, 0, OVER, COUNT, OVER, CAT, DOLIT, 0X24, EQUAL, GAP12);
	IF(5, HEXX, SWAP, ONEP, SWAP, ONEM, GAP19);
	THEN(13, OVER, CAT, DOLIT, 0X2D, EQUAL, TOR, SWAP, RAT, SUBBB, SWAP, RAT, PLUS, QDUP, GAP11);
	IF(1, ONEM, GAP23);
	FOR(6, DUPP, TOR, CAT, BASE, AT, DIGTQ, GAP18);
	WHILE(7, SWAP, BASE, AT, STAR, PLUS, RFROM, ONEP, GAP17);
	NEXT(2, DROP, RAT, GAP22);
	IF(1, NEGAT, GAP23);
	THEN(1, SWAP, GAP23);
	ELSE(6, RFROM, RFROM, DDROP, DDROP, DOLIT, 0, GAP18);
	THEN(1, DUPP, GAP23);
	THEN(6, RFROM, DDROP, RFROM, BASE, STORE, EXITT, GAP18);

	/* Terminal Output */

	HEADER(5, "SPACE");
	int32_t SPACE = COLON(3, BLANK, EMIT, EXITT, GAP21);
  HEADER(5, "DOTAB");
  int32_t DOTAB = COLON(3, TAB, EMIT, EXITT, GAP21);  // DJW
	HEADER(5, "CHARS");
	int32_t CHARS = COLON(4, SWAP, DOLIT, 0, MAX, GAP20);
	FOR(0, GAP24);
	AFT(2, DUPP, EMIT, GAP22);
	THEN(0, GAP24);
	NEXT(2, DROP, EXITT, GAP22);
	HEADER(6, "SPACES");
	int32_t SPACS = COLON(3, BLANK, CHARS, EXITT, GAP21);
	HEADER(4, "TYPE");
	int32_t TYPES = COLON(0, GAP24);
	FOR(0, GAP24);
	AFT(3, COUNT, TCHAR, EMIT, GAP21);
	THEN(0, GAP24);
	NEXT(2, DROP, EXITT, GAP22);
	HEADER(2, "CR");
	int32_t CR = COLON(7, DOLIT, 10, DOLIT, 13, EMIT, EMIT, EXITT, GAP17);
	HEADER(3, "do$");
	int32_t DOSTR = COLON(10, RFROM, RAT, RFROM, COUNT, PLUS, ALIGN, TOR, SWAP, TOR, EXITT, GAP14);
	HEADER(3, "$\"|");
	int32_t STRQP = COLON(2, DOSTR, EXITT, GAP22);
	HEADER(3, ".\"|");
	DOTQP = COLON(4, DOSTR, COUNT, TYPES, EXITT, GAP20);
	HEADER(2, ".R");
	int32_t DOTR = COLON(8, TOR, STRR, RFROM, OVER, SUBBB, SPACS, TYPES, EXITT, GAP16);
	HEADER(3, "U.R");
	int32_t UDOTR = COLON(10, TOR, BDIGS, DIGS, EDIGS, RFROM, OVER, SUBBB, SPACS, TYPES, EXITT, GAP14);
	HEADER(2, "U.");
	int32_t UDOT = COLON(6, BDIGS, DIGS, EDIGS, SPACE, TYPES, EXITT, GAP18);
	HEADER(1, ".");
	int32_t DOT = COLON(5, BASE, AT, DOLIT, 0XA, XORR, GAP19);
	IF(2, UDOT, EXITT, GAP22);
	THEN(4, STRR, SPACE, TYPES, EXITT, GAP20);
	HEADER(1, "?");
	int32_t QUEST = COLON(3, AT, DOT, EXITT, GAP21);

	/* Parser */

	HEADER(7, "(parse)");
	int32_t PARS = COLON(5, TEMP, CSTOR, OVER, TOR, DUPP, GAP19);
	IF(5, ONEM, TEMP, CAT, BLANK, EQUAL, GAP19);
	IF(0, GAP24);
	FOR(6, BLANK, OVER, CAT, SUBBB, ZLESS, INVER, GAP18);
	WHILE(1, ONEP, GAP23);
	NEXT(6, RFROM, DROP, DOLIT, 0, DUPP, EXITT, GAP18);
	THEN(1, RFROM, GAP23);
	THEN(2, OVER, SWAP, GAP22);
	FOR(9, TEMP, CAT, OVER, CAT, SUBBB, TEMP, CAT, BLANK, EQUAL, GAP15);
	IF(1, ZLESS, GAP23);
	THEN(0, GAP24);
	WHILE(1, ONEP, GAP23);
	NEXT(2, DUPP, TOR, GAP22);
	ELSE(5, RFROM, DROP, DUPP, ONEP, TOR, GAP19);
	THEN(6, OVER, SUBBB, RFROM, RFROM, SUBBB, EXITT, GAP18);
	THEN(4, OVER, RFROM, SUBBB, EXITT, GAP20);
	HEADER(5, "PACK$");
	int32_t PACKS = COLON(18, DUPP, TOR, DDUP, PLUS, DOLIT, 0xFFFFFFFC, ANDD, DOLIT, 0, SWAP, STORE, DDUP, CSTOR, ONEP, SWAP, CMOVEE, RFROM, EXITT, GAP6);
	HEADER(5, "PARSE");
	int32_t PARSE = COLON(15, TOR, TIB, INN, AT, PLUS, NTIB, AT, INN, AT, SUBBB, RFROM, PARS, INN, PSTOR, EXITT, GAP9);
	HEADER(5, "TOKEN");
	int32_t TOKEN = COLON(9, BLANK, PARSE, DOLIT, 0x1F, MIN, HERE, CELLP, PACKS, EXITT, GAP15);
	HEADER(4, "WORD");
	int32_t WORDD = COLON(5, PARSE, HERE, CELLP, PACKS, EXITT, GAP19);
	HEADER(5, "NAME>");
	int32_t NAMET = COLON(7, COUNT, DOLIT, 0x1F, ANDD, PLUS, ALIGN, EXITT, GAP17);
	HEADER(5, "SAME?");
	int32_t SAMEQ = COLON(4, DOLIT, 0x1F, ANDD, CELLD, GAP20);
	FOR(0, GAP24);
	AFT(14, OVER, RAT, CELLS, PLUS, AT, UPPER, OVER, RAT, CELLS, PLUS, AT, UPPER, SUBBB, QDUP, GAP10);
	IF(3, RFROM, DROP, EXITT, GAP21);
	THEN(0, GAP24);
	THEN(0, GAP24);
	NEXT(3, DOLIT, 0, EXITT, GAP21);
	HEADER(4, "find");
	int32_t FIND = COLON(10, SWAP, DUPP, AT, TEMP, STORE, DUPP, AT, TOR, CELLP, SWAP, GAP14);
	BEGIN(2, AT, DUPP, GAP22);
	IF(9, DUPP, AT, DOLIT, 0xFFFFFF3F, ANDD, UPPER, RAT, UPPER, XORR, GAP15);
	IF(3, CELLP, DOLIT, 0XFFFFFFFF, GAP21);
	ELSE(4, CELLP, TEMP, AT, SAMEQ, GAP20);
	THEN(0, GAP24);
	ELSE(6, RFROM, DROP, SWAP, CELLM, SWAP, EXITT, GAP18);
	THEN(0, GAP24);
	WHILE(2, CELLM, CELLM, GAP22);
	REPEAT(9, RFROM, DROP, SWAP, DROP, CELLM, DUPP, NAMET, SWAP, EXITT, GAP15);
	HEADER(5, "NAME?");
	int32_t NAMEQ = COLON(3, CNTXT, FIND, EXITT, GAP21);

	/* Terminal Input */

	HEADER(2, "^H");
	int32_t HATH = COLON(6, TOR, OVER, RFROM, SWAP, OVER, XORR, GAP18);
	IF(9, DOLIT, 8, EMIT, ONEM, BLANK, EMIT, DOLIT, 8, EMIT, GAP15);
	THEN(1, EXITT, GAP23);
	HEADER(3, "TAP");
	int32_t TAP = COLON(6, DUPP, EMIT, OVER, CSTOR, ONEP, EXITT, GAP18);
	HEADER(4, "kTAP");
	int32_t KTAP = COLON(9, DUPP, DOLIT, 0XD, XORR, OVER, DOLIT, 0XA, XORR, ANDD, GAP15);
	IF(3, DOLIT, 8, XORR, GAP21);
	IF(2, BLANK, TAP, GAP22);
	ELSE(1, HATH, GAP23);
	THEN(1, EXITT, GAP23);
	THEN(5, DROP, SWAP, DROP, DUPP, EXITT, GAP19);
	HEADER(6, "ACCEPT");
	int32_t ACCEP = COLON(3, OVER, PLUS, OVER, GAP21);
	BEGIN(2, DDUP, XORR, GAP22);
	WHILE(7, KEY, DUPP, BLANK, SUBBB, DOLIT, 0X5F, ULESS, GAP17);
	IF(1, TAP, GAP23);
	ELSE(1, KTAP, GAP23);
	THEN(0, GAP24);
	REPEAT(4, DROP, OVER, SUBBB, EXITT, GAP20);
	HEADER(6, "EXPECT");
	int32_t EXPEC = COLON(5, ACCEP, SPAN, STORE, DROP, EXITT, GAP19);
	HEADER(5, "QUERY");
	int32_t QUERY = COLON(12, TIB, DOLIT, 0X50, ACCEP, NTIB, STORE, DROP, DOLIT, 0, INN, STORE, EXITT, GAP12);

	/* Text int32_terpreter */

	HEADER(5, "ABORT");
	int32_t ABORT = COLON(2, TABRT, ATEXE, GAP22);
	HEADER(6, "abort\"");
	ABORQP = COLON(0, GAP24);
	IF(4, DOSTR, COUNT, TYPES, ABORT, GAP20);
	THEN(3, DOSTR, DROP, EXITT, GAP21);
	HEADER(5, "ERROR");
	int32_t ERRORR = COLON(11, SPACE, COUNT, TYPES, DOLIT, 0x3F, EMIT, DOLIT, 0X1B, EMIT, CR, ABORT, GAP13);
	HEADER(10, "$INTERPRET");
	int32_t INTERR = COLON(2, NAMEQ, QDUP, GAP22);
	IF(4, CAT, DOLIT, COMPO, ANDD, GAP20);
	ABORQ(" compile only");
	int32_t INTERR0 = LABEL(2, EXECU, EXITT, GAP22);
	THEN(1, NUMBQ, GAP23);
	IF(1, EXITT, GAP23);
	ELSE(1, ERRORR, GAP23);
	THEN(0, GAP24);
	HEADER(IMEDD + 1, "[");
	int32_t LBRAC = COLON(5, DOLIT, INTERR, TEVAL, STORE, EXITT, GAP19);
	HEADER(3, ".OK");
	int32_t DOTOK = COLON(6, CR, DOLIT, INTERR, TEVAL, AT, EQUAL, GAP18);
	IF(14, TOR, TOR, TOR, DUPP, DOT, RFROM, DUPP, DOT, RFROM, DUPP, DOT, RFROM, DUPP, DOT, GAP10);
	DOTQ(" ok>");
	THEN(1, EXITT, GAP23);
	HEADER(4, "EVAL");
	int32_t EVAL = COLON(0, GAP24);
	BEGIN(3, TOKEN, DUPP, AT, GAP21);
	WHILE(2, TEVAL, ATEXE, GAP22);
	REPEAT(3, DROP, DOTOK, EXITT, GAP21);
	HEADER(4, "QUIT");
	int32_t QUITT = COLON(5, DOLIT, 0X100, TTIB, STORE, LBRAC, GAP19);
	BEGIN(2, QUERY, EVAL, GAP22);
	AGAIN(0, GAP24);

	/* Colon Word Compiler */

	HEADER(1, ",");
	int32_t COMMA = COLON(7, HERE, DUPP, CELLP, CP, STORE, STORE, EXITT, GAP17);
	HEADER(IMEDD + 7, "LITERAL");
	int32_t LITER = COLON(5, DOLIT, DOLIT, COMMA, COMMA, EXITT, GAP19);
	HEADER(5, "ALLOT");
	int32_t ALLOT = COLON(4, ALIGN, CP, PSTOR, EXITT, GAP20);
	HEADER(3, "$,\"");
	int32_t STRCQ = COLON(9, DOLIT, 0X22, WORDD, COUNT, PLUS, ALIGN, CP, STORE, EXITT, GAP15);
	HEADER(7, "?UNIQUE");
	int32_t UNIQU = COLON(3, DUPP, NAMEQ, QDUP, GAP21);
	IF(6, COUNT, DOLIT, 0x1F, ANDD, SPACE, TYPES, GAP18);
	DOTQ(" reDef");
	THEN(2, DROP, EXITT, GAP22);
	HEADER(3, "$,n");
	int32_t SNAME = COLON(2, DUPP, AT, GAP22);
	IF(14, UNIQU, DUPP, NAMET, CP, STORE, DUPP, LAST, STORE, CELLM, CNTXT, AT, SWAP, STORE, EXITT, GAP10);
	THEN(1, ERRORR, GAP23);
	HEADER(1, "'");
	int32_t TICK = COLON(2, TOKEN, NAMEQ, GAP22);
	IF(1, EXITT, GAP23);
	THEN(1, ERRORR, GAP23);
	HEADER(IMEDD + 9, "[COMPILE]");
	int32_t BCOMP = COLON(3, TICK, COMMA, EXITT, GAP21);
	HEADER(7, "COMPILE");
	int32_t COMPI = COLON(7, RFROM, DUPP, AT, COMMA, CELLP, TOR, EXITT, GAP17);
	HEADER(8, "$COMPILE");
	int32_t SCOMP = COLON(2, NAMEQ, QDUP, GAP22);
	IF(4, AT, DOLIT, IMEDD, ANDD, GAP20);
	IF(1, EXECU, GAP23);
	ELSE(1, COMMA, GAP23);
	THEN(1, EXITT, GAP23);
	THEN(1, NUMBQ, GAP23);
	IF(2, LITER, EXITT, GAP22);
	THEN(1, ERRORR, GAP23);
	HEADER(5, "OVERT");
	int32_t OVERT = COLON(5, LAST, AT, CNTXT, STORE, EXITT, GAP19);
	HEADER(1, "]");
	int32_t RBRAC = COLON(5, DOLIT, SCOMP, TEVAL, STORE, EXITT, GAP19);
	HEADER(1, ":");
	int32_t COLN = COLON(7, TOKEN, SNAME, RBRAC, DOLIT, 0x6, COMMA, EXITT, GAP17);
	HEADER(IMEDD + 1, ";");
	int32_t SEMIS = COLON(6, DOLIT, EXITT, COMMA, LBRAC, OVERT, EXITT, GAP18);

	/* Debugging Tools */

	HEADER(3, "dm+");
	int32_t DMP = COLON(4, OVER, DOLIT, 6, UDOTR, GAP20);
	FOR(0, GAP24);
	AFT(6, DUPP, AT, DOLIT, 9, UDOTR, CELLP, GAP18);
	THEN(0, GAP24);
	NEXT(1, EXITT, GAP23);
	HEADER(4, "DUMP");
	int32_t DUMP = COLON(10, BASE, AT, TOR, HEXX, DOLIT, 0x1F, PLUS, DOLIT, 0x20, SLASH, GAP14);
	FOR(0, GAP24);
	AFT(10, CR, DOLIT, 8, DDUP, DMP, TOR, SPACE, CELLS, TYPES, RFROM, GAP14);
	THEN(0, GAP24);
	NEXT(5, DROP, RFROM, BASE, STORE, EXITT, GAP19);
	HEADER(5, ">NAME");
	int32_t TNAME = COLON(1, CNTXT, GAP23);
	BEGIN(2, AT, DUPP, GAP22);
	WHILE(3, DDUP, NAMET, XORR, GAP21);
	IF(1, ONEM, GAP23);
	ELSE(3, SWAP, DROP, EXITT, GAP21);
	THEN(0, GAP24);
	REPEAT(3, SWAP, DROP, EXITT, GAP21);
	HEADER(3, ".ID");
	int32_t DOTID = COLON(7, COUNT, DOLIT, 0x1F, ANDD, TYPES, SPACE, EXITT, GAP17);
//
  #define WORDS_ON_LINE_MINUS_1 3 
	HEADER(5, "WORDS");
	int32_t WORDS = COLON(6, CR, CNTXT, DOLIT, 0, TEMP, STORE, GAP18);
	BEGIN(2, AT, QDUP, GAP22);
	WHILE(10, DUPP, DOTAB, DOTAB, DOTID, CELLM, TEMP, AT, DOLIT, WORDS_ON_LINE_MINUS_1, LESS, GAP14); 
	IF(4, DOLIT, 1, TEMP, PSTOR, GAP20);
	ELSE(5, CR, DOLIT, 0, TEMP, STORE, GAP19);
	THEN(0, GAP24);
	REPEAT(1, EXITT, GAP23);
//	
	HEADER(6, "FORGET");
	int32_t FORGT = COLON(3, TOKEN, NAMEQ, QDUP, GAP21);
	IF(12, CELLM, DUPP, CP, STORE, AT, DUPP, CNTXT, STORE, LAST, STORE, DROP, EXITT, GAP12);
	THEN(1, ERRORR, GAP23);
	HEADER(4, "COLD");
	int32_t COLD = COLON(1, CR, GAP23);
//	DOTQ("eForth in C,Ver 2.3,2017 ");
	DOTQ("Cold Boot "); 
	int32_t DOTQ1 = LABEL(2, CR, QUITT, GAP22);

	/* Structure Compiler */

	HEADER(IMEDD + 4, "THEN");
	int32_t THENN = COLON(4, HERE, SWAP, STORE, EXITT, GAP20);
	HEADER(IMEDD + 3, "FOR");
	int32_t FORR = COLON(4, COMPI, TOR, HERE, EXITT, GAP20);
	HEADER(IMEDD + 5, "BEGIN");
	int32_t BEGIN = COLON(2, HERE, EXITT, GAP22);
	HEADER(IMEDD + 4, "NEXT");
	int32_t NEXT = COLON(4, COMPI, DONXT, COMMA, EXITT, GAP20);
	HEADER(IMEDD + 5, "UNTIL");
	int32_t UNTIL = COLON(4, COMPI, QBRAN, COMMA, EXITT, GAP20);
	HEADER(IMEDD + 5, "AGAIN");
	int32_t AGAIN = COLON(4, COMPI, BRAN, COMMA, EXITT, GAP20);
	HEADER(IMEDD + 2, "IF");
	int32_t IFF = COLON(7, COMPI, QBRAN, HERE, DOLIT, 0, COMMA, EXITT, GAP17);
	HEADER(IMEDD + 5, "AHEAD");
	int32_t AHEAD = COLON(7, COMPI, BRAN, HERE, DOLIT, 0, COMMA, EXITT, GAP17);
	HEADER(IMEDD + 6, "REPEAT");
	int32_t REPEA = COLON(3, AGAIN, THENN, EXITT, GAP21);
	HEADER(IMEDD + 3, "AFT");
	int32_t AFT = COLON(5, DROP, AHEAD, HERE, SWAP, EXITT, GAP19);
	HEADER(IMEDD + 4, "ELSE");
	int32_t ELSEE = COLON(4, AHEAD, SWAP, THENN, EXITT, GAP20);
	HEADER(IMEDD + 4, "WHEN");
	int32_t WHEN = COLON(3, IFF, OVER, EXITT, GAP21);
	HEADER(IMEDD + 5, "WHILE");
	int32_t WHILEE = COLON(3, IFF, SWAP, EXITT, GAP21);
	HEADER(IMEDD + 6, "ABORT\"");
	int32_t ABRTQ = COLON(6, DOLIT, ABORQP, HERE, STORE, STRCQ, EXITT, GAP18);
	HEADER(IMEDD + 2, "$\"");
	int32_t STRQ = COLON(6, DOLIT, STRQP, HERE, STORE, STRCQ, EXITT, GAP18);
	HEADER(IMEDD + 2, ".\"");
	int32_t DOTQQ = COLON(6, DOLIT, DOTQP, HERE, STORE, STRCQ, EXITT, GAP18);
 
	HEADER(4, "CODE");
	int32_t CODE = COLON(4, TOKEN, SNAME, OVERT, EXITT, GAP20);
	
	HEADER(6, "CREATE");
	int32_t CREAT = COLON(5, CODE, DOLIT, 0x203D, COMMA, EXITT, GAP19);
	HEADER(8, "VARIABLE");
	int32_t VARIA = COLON(5, CREAT, DOLIT, 0, COMMA, EXITT, GAP19);
	HEADER(8, "CONSTANT");
	int32_t CONST = COLON(6, CODE, DOLIT, 0x2004, COMMA, COMMA, EXITT, GAP18);
	HEADER(IMEDD + 2, ".(");
	int32_t DOTPR = COLON(5, DOLIT, 0X29, PARSE, TYPES, EXITT, GAP19);
	HEADER(IMEDD + 1, "\\");
	int32_t BKSLA = COLON(5, DOLIT, 0xA, WORDD, DROP, EXITT, GAP19);
	HEADER(IMEDD + 1, "(");
	int32_t PAREN = COLON(5, DOLIT, 0X29, PARSE, DDROP, EXITT, GAP19);
	HEADER(12, "COMPILE-ONLY");
	int32_t ONLY = COLON(6, DOLIT, 0x40, LAST, AT, PSTOR, EXITT, GAP18);
//
// Steps to add a primitive:
// 1) wrap a pico skd function with name f_{thename}, see PicoPrimitivesADC.c
// 2) add as_f_{thename} to ByteCodes.h
// 3) in Common.h increment the PRIMITIVE_ARRAYSIZE
// 4) add the f_{thename} to the end of the primitive array at end of VFM_Primitives.c
// 5) Generate suitable HEADER and Variable below, don't forget the damn as_ prefix
//
#ifdef EXTENSIONS
// PICO EXTENSIONS
  // ADC
  HEADER(7 , "TEMP_ON");     int32_t   TEMP_ON     = VFM_CODE(4, as_f_temp_on, as_next, 0, 0, GAP4);   
  HEADER(8,  "TEMP_OFF");    int32_t   TEMP_OFF    = VFM_CODE(4, as_f_temp_off, as_next, 0, 0, GAP4);     
  HEADER(8,  "ADC_INIT");    int32_t   ADC_INIT    = VFM_CODE(4, as_f_adc_init, as_next, 0, 0, GAP4);
  HEADER(11, "ADC_IO_INIT"); int32_t   ADC_IO_INIT = VFM_CODE(4, as_f_adc_gpio_init, as_next, 0, 0, GAP4); 
  HEADER(9,  "ADC_INPUT");   int32_t   ADC_INPUT   = VFM_CODE(4, as_f_adc_select_input, as_next, 0, 0, GAP4);
  HEADER(8,  "ADC_READ");    int32_t   ADC_READ    = VFM_CODE(4, as_f_adc_read, as_next, 0, 0, GAP4);
  HEADER(7,  "RAWTEMP");     int32_t   RAWTEMP     = COLON(7, ADC_INIT, TEMP_ON, DOLIT, 4, ADC_INPUT, ADC_READ, EXITT, GAP17);
  // GPIO
  HEADER(10, "GET_IO_DIR");       int32_t   GET_IO_DIR       = VFM_CODE(4, as_f_gpio_get_dir, as_next, 0, 0, GAP4); 
  HEADER(10, "GET_IO_AMP");       int32_t   GET_IO_AMP       = VFM_CODE(4, as_f_gpio_get_drive_strength, as_next, 0, 0, GAP4); 
  HEADER(11, "GET_IO_SLEW");      int32_t   GET_IO_SLEW      = VFM_CODE(4, as_f_gpio_get_slew_rate, as_next, 0, 0, GAP4); 
  HEADER(16, "SET_IO_DIS_PULLS"); int32_t   SET_IO_DIS_PULLS = VFM_CODE(4, as_f_gpio_disable_pulls, as_next, 0, 0, GAP4); 
  HEADER(14, "SET_IO_PULL_UP");   int32_t   SET_IO_PULL_UP   = VFM_CODE(4, as_f_gpio_pull_up, as_next, 0, 0, GAP4); 
  HEADER(14, "SET_IO_PULL_DN");   int32_t   SET_IO_PULL_DN   = VFM_CODE(4, as_f_gpio_pull_down, as_next, 0, 0, GAP4); 
  HEADER(15, "CHK_IO_PULL_UP?");  int32_t   CHK_IO_PULL_UPQ  = VFM_CODE(4, as_f_gpio_is_pulled_up, as_next, 0, 0, GAP4); 
  HEADER(15, "CHK_IO_PULL_DN?");  int32_t   CHK_IO_PULL_DNQ  = VFM_CODE(4, as_f_gpio_is_pulled_down, as_next, 0, 0, GAP4); 
  HEADER(15, "CHK_IO_HIST_ON?");  int32_t   CHK_IO_HIST_ONQ  = VFM_CODE(4, as_f_gpio_is_input_hysteresis_enabled, as_next, 0, 0, GAP4); 
  HEADER(10, "GET_IO_BIT");       int32_t   GET_IO_BIT       = VFM_CODE(4, as_f_gpio_get, as_next, 0, 0, GAP4); 
  HEADER(14, "SET_IO_BIT_SIO");   int32_t   SET_IO_BIT_SIO   = VFM_CODE(4, as_f_gpio_init, as_next, 0, 0, GAP4); 
  HEADER(14, "SET_IO_BIT_DIR");   int32_t   SET_IO_BIT_DIR   = VFM_CODE(4, as_f_gpio_set_dir, as_next, 0, 0, GAP4); 
  HEADER(10, "PUT_IO_BIT");       int32_t   PUT_IO_BIT       = VFM_CODE(4, as_f_gpio_put, as_next, 0, 0, GAP4); 
  HEADER(10, "SET_IO_AMP");       int32_t   SET_IO_AMP       = VFM_CODE(4, as_f_gpio_set_drive_strength, as_next, 0, 0, GAP4); 
  HEADER(11, "SET_IO_SLEW");      int32_t   SET_IO_SLEW      = VFM_CODE(4, as_f_gpio_set_slew_rate, as_next, 0, 0, GAP4); 
  HEADER(11, "SET_IO_HIST");      int32_t   SET_IO_HIST      = VFM_CODE(4, as_f_gpio_set_input_hysteresis_enabled, as_next, 0, 0, GAP4); 
  //
  HEADER(12, "SECTOR_ERASE");     int32_t   SECTOR_ERASE     = VFM_CODE(4, as_f_flash_sector_erase, as_next, 0, 0, GAP4);   
  HEADER(12, "SECTOR_STORE");     int32_t   SECTOR_STORE     = VFM_CODE(4, as_f_flash_store, as_next, 0, 0, GAP4);   
  HEADER(9,  "PAGE_LIST");        int32_t   PAGE_LIST        = VFM_CODE(4, as_f_flash_page_list, as_next, 0, 0, GAP4);     
  HEADER(6,  "GET_ID");           int32_t   GET_ID           = VFM_CODE(4, as_f_flash_get_unique_id, as_next, 0, 0, GAP4);     
  HEADER(12, "PATTERN_PAGE");     int32_t   PATTERN_PAGE     = VFM_CODE(4, as_f_page_pattern, as_next, 0, 0, GAP4);     
  HEADER(16, "WIPE_ALL_SECTORS"); int32_t   WIPE_ALL_SECTORS = VFM_CODE(4, as_f_WipeAllSectors, as_next, 0, 0, GAP4);     
#endif
  
	HEADER(9, "IMMEDIATE");
	int32_t IMMED = COLON(6, DOLIT, 0x80, LAST, AT, PSTOR, EXITT, GAP18);
#ifdef REPORT_COUNTS
  ReportCounts(); 
#endif
  // 
	int32_t ENDD = M->P;
  //
  M->P = 0;
  int32_t RESET = LABEL(2, 6, COLD, GAP22);
  M->P = 0x90;
  int32_t USER = LABEL(8, 0X100, 0x10, IMMED - 12, ENDD, IMMED - 12, INTERR, QUITT, 0, GAP16);  
}
