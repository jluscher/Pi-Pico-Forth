#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
//
#define  FALSE 0
#define  TRUE  -1
#define  LOGICAL ? TRUE : FALSE
#define  LOWER(x,y) ((uint64_t)(x)<(uint64_t)(y))
//
#define  popS  M->top = M->stack[(M->S)--]
#define  pushS M->stack[++(M->S)] = M->top; M->top =
#define  popR  M->rack[(M->R)--]
#define  pushR M->rack[++(M->R)]
//
#ifdef __cplusplus
extern "C" {
#endif
  void serial_putchar(char);
  int32_t serial_getchar(void);
  void Printbuf(char*);
#ifdef __cplusplus
}
#endif
//
#define MEMSIZE 32768
#define STACKSIZE 256
//
#define PRIMITIVE_ARRAYSIZE 70
//
typedef struct{
  union{
    int32_t data[MEMSIZE];
    unsigned char cdata[MEMSIZE*4];
  };
  int32_t  rack[STACKSIZE];
  int32_t  stack[STACKSIZE];
  int64_t  d, n, m;
  int8_t   R, S;
  int32_t  top, P, IP, WP, thread;
} MemoryImage;
