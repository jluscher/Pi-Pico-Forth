#include <stdio.h>
#include "ScreenEditor.h"
#include "BlocksViaRamSPI.h"
//
void f_flash_sector_erase(cell SectorNumber){ // erase one sector = 4096 bytes
  int s = FLASH_SECTORS_AVAILABLE; 
  long Offset = (FLASH_SECTORS_OFFSET + (SectorNumber * FLASH_SECTOR_SIZE));  
  //
  if( (SectorNumber >= 0) && (SectorNumber < s) ){
    uint32_t ints = save_and_disable_interrupts();
    flash_range_erase(Offset, FLASH_SECTOR_SIZE);
    restore_interrupts (ints);
    //tell("Interupts Restored\n");
  }else{
    tell("Sector Erase Failed, sector number out of range: 0,1,2,...");
    tellnumber(s-1);
  }
}
//
void show_buffer(const uint8_t* data, cell number){ // for testing
  int i;
  char buf[8];
  for(i=0;i<number;i++){
    sprintf(buf,"%02X",data[i]);
    tell(buf);
    if (i % 16 == 15){
      tell("\n");
    }else{
      tell(" ");
    }     
  }
}
//
void f_flash_store(cell SectorNumber, cell PageNumber, dcell data){ // store one page = 256 bytes
  int s = FLASH_SECTORS_AVAILABLE;
  int p = PAGES_PER_SECTOR;
  long Offset = (FLASH_SECTORS_OFFSET + (SectorNumber * FLASH_SECTOR_SIZE) + (PageNumber * FLASH_PAGE_SIZE) );
  if( (SectorNumber >= 0) && (SectorNumber < s) ){                                     
    if( (PageNumber >= 0) && (PageNumber < p) ){      
      //show_buffer((const uint8_t*)data, FLASH_PAGE_SIZE);
      uint32_t ints = save_and_disable_interrupts();
      flash_range_program(Offset, (const uint8_t*)data, FLASH_PAGE_SIZE);                                    
      restore_interrupts (ints); 
    }else{
      tell("Page Store Failed, page number out of range: 0,1,2,...");
      tellnumber(p-1);
    }
  }else{
    tell("Sector?, sector number out of range: 0,1,2,...");
    tellnumber(s-1);
  }
}
//
void f_flash_page_list(cell SectorNumber, cell PageNumber){
  int i, len = FLASH_PAGE_SIZE;
  char buf[8], mess[30];
  //
  sprintf(mess,"Sector(%d) Page(%d)\n",SectorNumber, PageNumber);
  tell(mess);  
  int s = FLASH_SECTORS_AVAILABLE;
  int p = PAGES_PER_SECTOR;
  const uint8_t* Offset = (const uint8_t*)(XIP_BASE + FLASH_SECTORS_OFFSET + 
                                          (SectorNumber * FLASH_SECTOR_SIZE) +
                                          (PageNumber * FLASH_PAGE_SIZE) );
                                          
  if( (SectorNumber >= 0) && (SectorNumber < s) ){                                     
    if( (PageNumber >= 0) && (PageNumber < p) ){      
      for (i = 0; i < len; ++i) {
        sprintf(buf,"%02x", Offset[i]);
        tell(buf);
        if (i % 16 == 15){
          tell("\n");
        }else{
          tell(" ");
        } 
      }
    }else{
      tell("Page Read Failed, page number out of range: 0,1,2,...");
      tellnumber(p-1);
    }
  }else{
    tell("Page Read Failed, due to sector number out of range: 0,1,2,...");
    tellnumber(s-1);
  }
}
//
void f_flash_get_unique_id(dcell buf){
  flash_get_unique_id((uint8_t*)buf);
}
//
// make page pattern to test writing flash
//
unsigned char pattern_buf[256];
unsigned char* f_page_pattern(cell type){
  cell i;
  tell("Pattern Inc Offset is: ");
  tellnumber(type);
  for(i=0;i<256;i++){
    pattern_buf[i] = (unsigned char)(i+type);
  }
  //show_buffer(pattern_buf, 256);
  return(pattern_buf);
}
/*
void f_flash_do_cmd(cell*, cell*, cell){
  flash_do_cmd(cell*, cell*, cell);
}
*/
//
void WipeAllSectors(void){
  cell i;
  for(i=0;i<FLASH_SECTORS_AVAILABLE;i++){
    f_flash_sector_erase(i);
  }
}
