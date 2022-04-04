#include <Arduino.h>
#include "Common.h"
//
char Title[128];
char Communicate[128];
//
void establishContact() {
  strcpy(Title, "Core_Forth Version: 0.00\n");
  strcat(Title, __DATE__);
  strcat(Title, "  ");
  strcat(Title, __TIME__);
  strcat(Title, "\nDerived From: (ceForth v3.3, 01jul19 C.H.Ting) <== Thank You!\n");
  strcpy(Communicate, "Terminal Settings: 19200 Baud, 8N1, No Local Echo, Send <cr>. \n\n");
  //
  while (Serial.available() <= 0) { }
  while (Serial.available() > 0)  { Serial.read(); }
}
//
void setup() { 
  Serial.begin(19200);   
  while (!Serial) { }
  establishContact();   
  Serial.write(Title);
  Serial.write(Communicate);
}
//
extern "C" {
  int CHT_Forth(void);
}
//
void loop(void){ 
  if ( CHT_Forth() != 0 ){ Serial.write("Forth Issued Error: Restarted. \n"); }
  delay(100);
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
  int serial_getchar(bool echoit){ 
    while (Serial.available() <= 0) { }
    int32_t thekey = Serial.read(); // non blocking, returns -1 if no chars
    if(echoit){ serial_putchar((char)thekey); }
    return(thekey & 0xFF);
  }
  //
}
