#include "ScreenEditor.h"
//
SectorData *FlashDataAdr = (unsigned char)(XIP_BASE + FLASH_SECTORS_OFFSET); // the complete allocated flash
#define COMMAND_MODE true
#define TEXT_MODE false
//
bool exit_sed = false;
//
void sed_previous(void){}
void sed_next(void){}
void sed_forward(void){}
void sed_back(void){}
void sed_exit(bool x){ exit_sed = x; }
//
void ScreenEditor(cell Screen){}
void _ScreenEditor(cell Screen){
int key;
bool mode = COMMAND_MODE; 
  do{
    key =  serial_getchar(NOECHO);  
    //
    if ( key == 0x1B ){ // test for ESC key which toggles command/text mode
      mode = !mode;
    }
    //
    if(mode == COMMAND_MODE){ 
      switch (key){
        case ('p'):  sed_previous(); break;
        case ('n'):      sed_next(); break;
        case ('f'):   sed_forward(); break;
        case ('b'):      sed_back(); break;
        case ('x'):  sed_exit(true); break;
      }     
    }else{  // TEXT_MODE
      if( key != -1){ serial_putchar(key); }
    }
  }while(!exit_sed); // only exit with 'x' in COMMAND_MODE
  serial_putchar('\n');
}
