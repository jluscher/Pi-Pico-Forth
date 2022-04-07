#include "Common.h"
#include "SerialUSB.h"
//
SerialUSB USB;
//
char Title[128];
char Communicate[128];
//
void setup() { 
  stdio_init_all();
  USB.begin(0); 
  strcpy(Title, "Pico_Forth Version: 0.00\n");
  strcat(Title, __DATE__);
  strcat(Title, "  ");
  strcat(Title, __TIME__);
  strcat(Title, "\nDerived From: (ceForth v3.3, 01jul19 C.H.Ting) <== Thank You!\n");
  strcpy(Communicate, "Terminal Settings: 115200 Baud, 8N1, No Local Echo, Send <cr>. \n\n");
  USB.printf(Title);
  USB.printf(Communicate);
}
//
extern "C" { int CHT_Forth(void); }
//
int main(void){ 
  USB.printf("Hellow World\n");
  //if ( CHT_Forth() != 0 ){ Serial.write("Forth Issued Error: Restarted. \n"); }
}


