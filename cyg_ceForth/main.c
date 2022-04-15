#include "Common.h"
//
char Title[128];
char Communicate[128];
//
MemoryImage ThisMemory;
//
int CHT_Forth(MemoryImage *mptr); 
//
int main(void){ 
  //stdio_usb_init();
  strcpy(Title, "Pico_Forth Version: 0.00\n");
  strcat(Title, __DATE__);
  strcat(Title, "  ");
  strcat(Title, __TIME__);
  strcat(Title, "\nDerived From: (ceForth v3.3, 01jul19 C.H.Ting) <== Thank You!\n");
  strcpy(Communicate, "Terminal Settings: 115200 Baud, 8N1, No Local Echo, Send <cr>. \n\n");
  printf(Title);
  printf(Communicate);  
  //
  if ( CHT_Forth(&ThisMemory) != 0 ){ printf("Forth Error! Restarting.\n"); }
}
