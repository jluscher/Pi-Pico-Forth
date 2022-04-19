#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
//
//#include "pico/stdlib.h"
//#include "pico/stdio.h"
//#include "pico/time.h"
//
#define SERIAL_CHAR
//
#ifdef SERIAL_CHAR
//
#ifdef __cplusplus
extern "C" {
#endif
void serial_putchar(char c);
int32_t serial_getchar(void);
#ifdef __cplusplus
}
#endif
//
#endif
//
#define MEMSIZE 16384
#define STACKSIZE 256
//
typedef struct{
  union{
    int32_t data[MEMSIZE];
    unsigned char cdata[MEMSIZE*4];
  };
  int32_t rack[STACKSIZE];
  int32_t stack[STACKSIZE];
  int64_t d, n, m;
  int8_t R, S;
  int32_t  top, P, IP, WP, thread;
} MemoryImage;
