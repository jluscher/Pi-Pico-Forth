#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
//
#define NOECHO 0
#define ECHO  -1
//
void serial_flush(void);
int  serial_getchar(bool);  
int  serial_available(void);
void serial_putchar(char c);
