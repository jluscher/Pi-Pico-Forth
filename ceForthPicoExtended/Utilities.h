#define EXTENSIONS
#define CRC_HEADER
#define CRC32_DICTIONARY
#define REPORT_COUNTS
extern int32_t HeaderCount, VFM_CodeCount;
char* crc32b(char*);
void reportcrc(char*);
void Set_astart(int32_t);
void Set_anend (int32_t);
void ReportCounts(void);
void PrintNumber(int32_t);
