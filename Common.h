#include "pico/stdlib.h"
//
#define MAX_BUILTIN_ID 92
//
#define CELL_BASE_TYPE short
#define DOUBLE_CELL_BASE_TYPE long
/* Basic memory configuration */
#define MEM_SIZE 65536 /* main memory size in bytes */
#define STACK_SIZE 192 /* cells reserved for the stack */
#define RSTACK_SIZE 64 /* cells reserved for the return stack */
#define INPUT_LINE_SIZE 32 /* bytes reserved for the WORD buffer */
/******************************************************************************/
/* Our basic data types */
typedef CELL_BASE_TYPE scell;
typedef DOUBLE_CELL_BASE_TYPE dscell;
typedef unsigned CELL_BASE_TYPE cell;
typedef unsigned DOUBLE_CELL_BASE_TYPE dcell;
typedef unsigned char byte;
#define CELL_SIZE sizeof(cell)
#define DCELL_SIZE sizeof(dcell)
/* A few constants that describe the memory layout of this implementation */
#define LATEST_POSITION INPUT_LINE_SIZE
#define HERE_POSITION (LATEST_POSITION + CELL_SIZE)
#define BASE_POSITION (HERE_POSITION + CELL_SIZE)
#define STATE_POSITION (BASE_POSITION + CELL_SIZE)
#define STACK_POSITION (STATE_POSITION + CELL_SIZE)
#define RSTACK_POSITION (STACK_POSITION + STACK_SIZE * CELL_SIZE)
#define HERE_START (RSTACK_POSITION + RSTACK_SIZE * CELL_SIZE)
/* Flags and masks for the dictionary */
#define FLAG_IMMEDIATE 0x80
#define FLAG_HIDDEN 0x40
#define MASK_NAMELENGTH 0x1F
//
typedef void(*builtin)();
void addBuiltin(cell, const char*, const byte, builtin);
#define BUILTIN(id, name, c_name, flags) const int c_name##_id=id; const char* c_name##_name=name; const byte c_name##_flags=flags; void c_name()
#define ADD_BUILTIN(c_name) addBuiltin(c_name##_id, c_name##_name, c_name##_flags, c_name)
//
void MoreBuiltInAtomics(void);
cell pop(void);
void push(cell);
