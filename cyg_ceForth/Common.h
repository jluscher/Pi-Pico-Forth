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
//
#define MEMSIZE 32768
#define STACKSIZE 128
//
typedef struct{
  union{
    int32_t data[MEMSIZE];
    unsigned char cData[MEMSIZE*4];
  };
  int32_t rack[STACKSIZE];
  int32_t stack[STACKSIZE];
  int64_t d, n, m;
  unsigned char R, S;
  int32_t  top, P, IP, WP, thread;
} MemoryImage;

