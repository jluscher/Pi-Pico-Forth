#include "Common.h"
#include "hardware/flash.h"
#include "hardware/sync.h"
//
#define LINES_PER_SCREEN        16  
#define LINE_LENGTH             64
#define PAGES_PER_SCREEN         4
#define SCREEN_SIZE           1024
//
#define FLASH_SIZE              (2 * 1024 * 1024)
#define FLASH_SECTORS_OFFSET    (1024 * 1024)
#define FLASH_SECTORS_AVAILABLE ((FLASH_SIZE - FLASH_SECTORS_OFFSET) / FLASH_SECTOR_SIZE)
#define PAGES_PER_SECTOR        (FLASH_SECTOR_SIZE / FLASH_PAGE_SIZE)
//
typedef union{  // 4 FORTH Screens/Sector == 4096
  unsigned char Lines [PAGES_PER_SCREEN][LINES_PER_SCREEN][LINE_LENGTH];
  unsigned char Pages [PAGES_PER_SECTOR][FLASH_PAGE_SIZE];
  unsigned char Block [PAGES_PER_SCREEN][SCREEN_SIZE];
  unsigned char Sector[FLASH_SECTOR_SIZE];
}SectorData;
//
typedef struct{ // variuos pointers for present Block context
  unsigned char* LinePtr;  
  unsigned char* PagePtr;
  unsigned char* BlockPtr;
  unsigned char* SectorPtr;  
}SectorPtrs;
//
//
extern SectorData *FlashDataAdr;
//
void ScreenEditor(cell);
