#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
//
#define NOECHO 0
#define ECHO  -1
#define MEMSIZE 16384
//
#ifdef __cplusplus
extern "C" {
#endif
int serial_getchar(bool); 
void serial_putchar(char); 
#ifdef __cplusplus
}
#endif
