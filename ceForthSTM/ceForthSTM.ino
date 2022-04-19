#include <Arduino.h>
#include "Common.h"
//
char Title[128];
char Communicate[128];
//
void establishContact() {
  strcpy(Title, "CSTM_Forth Version: 0.00\n");
  strcat(Title, __DATE__);
  strcat(Title, "  ");
  strcat(Title, __TIME__);
  strcat(Title, "\nDerived From: (ceForth v3.3, 01jul19 C.H.Ting) <== Thank You!\n");
  strcpy(Communicate, "Terminal Settings: 19200 Baud, 8N1, No Local Echo, Send <cr>. \n\n");
  //
  while (Serial.available() <= 0) { } // wait for key press
  Serial.read();
}
//
void setup() { 
  Serial.begin(19200);   
  while (!Serial) { }
  establishContact();   
  Serial.write(Title);
  Serial.write(Communicate);
  Serial.flush();
}
//
MemoryImage ThisMemory;
extern "C" { int CHT_Forth(MemoryImage*); }
//
int CHT_Forth(MemoryImage*); 
//
void loop(void){ 
    CHT_Forth(&ThisMemory);
}
//
#ifdef __cplusplus
extern "C" {
#endif
  //
  // compiled under C not C++
  //
  void serial_putchar(char c){ Serial.print(c); }
  //
  int32_t serial_getchar(void){ 
    while (Serial.available() <= 0) { }         // block
    int32_t thekey = Serial.read() & 0xFF ;     // non blocking, returns -1 if no chars
    return(thekey);
  }
  //
#ifdef __cplusplus  
}
#endif
