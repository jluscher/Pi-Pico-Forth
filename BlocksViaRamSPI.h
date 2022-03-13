#include "Common.h"
//
// SPI RAM functions
//
void f_flash_sector_erase(cell);
void f_flash_store(cell, cell, dcell);
void f_flash_page_list(cell, cell);
void f_flash_get_unique_id(dcell);
unsigned char* f_page_pattern(cell);
//void f_flash_do_cmd(cell*, cell*, cell);
