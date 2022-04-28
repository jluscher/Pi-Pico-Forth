#include "Common.h"
#include "Utilities.h"
//
int32_t astart=0, anend = MEMSIZE-1; // default to entire dictionary
void Set_astart(int32_t st){ astart = st; } // use these for crc one header at a time
void Set_anend (int32_t en){ anend  = en; }
//
char crc32buf[80]; 
extern MemoryImage *M;
//
char* crc32b(char *s) {
   int32_t i, j;
   int32_t cnt = anend - astart;
   uint32_t abyte, crc, mask;
   //
   i = astart;
   crc = 0xFFFFFFFF;
   while (cnt-- >= 0){
      abyte = M->cdata[i];           
      crc = crc ^ abyte;
      for (j = 7; j >= 0; j--) {   
         mask = -(crc & 1);
         crc = (crc >> 1) ^ (0xEDB88320 & mask);
      }
      i++;
   }
   sprintf(crc32buf,"%24s %8.8X \n", s, crc);
   if(strlen(crc32buf)>80)sprintf(crc32buf,"\nCRC String too long!\n");   
   astart = anend;
   return crc32buf;
}
//
void ReportCounts(void){
  char buf[80];
  int32_t hc, vc, vpc;
  hc = HeaderCount;
  vc = VFM_CodeCount;
  vpc = HeaderCount + VFM_CodeCount;
  sprintf(buf,"\nHeaders = 0x%X = (%4d) VFM_Codes = 0x%X = (%4d) Sum = 0x%X = (%4d)\n", hc, hc, vc, vc, vpc, vpc);
  if(strlen(buf)>80)sprintf(buf,"\nReportCounts string too long!\n");
  Printbuf(buf);
}
//
void PrintNumber(int32_t N){
  char buf[20];
  sprintf(buf," %d ",N);
  Printbuf(buf);
}
