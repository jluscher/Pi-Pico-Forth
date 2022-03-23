#include <Arduino.h>
//
char Title[100];
char Communicate[100];

void establishContact() {
  strcpy(Title, "PICO_Forth Version: 0.00\n");
  strcat(Title, __DATE__);
  strcat(Title, "  ");
  strcat(Title, __TIME__);
  strcat(Title, "\nDerived From: (ceForth v3.3, 01jul19 C.H.Ting) <== Thank You!\n");
  strcpy(Communicate, "Terminal Settings: 19200 Baud, 8N1, No Local Echo, Send <cr>. \n\n");
  //
  while (Serial.available() <= 0) { }
  Serial.read();
}

void setup() { 
  Serial.begin(19200);   
  while (!Serial) { }
  establishContact();   
  Serial.write(Title);
  Serial.write(Communicate);
  delay(100);
}

#ifdef __cplusplus
extern "C" {
#endif
  // compiled under C not C++
  int serial_available(void) { return(Serial.available()); }
  int serial_getchar(bool echoit){ 
    int thekey;
    thekey = Serial.read(); 
    if(echoit){ Serial.print((char)thekey); }
    return(thekey);
  }
  void serial_putchar(char c){ Serial.print(c); }
  void serial_flush(){ Serial.flush(); }  
  int CHT_Forth(void);
}

void loop()  { 
  if ( CHT_Forth() != 0 ){ Serial.write("Forth Issued Error: Restarted. \n"); }
  delay(250);
}
