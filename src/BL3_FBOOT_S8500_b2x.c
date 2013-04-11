#include "BL3.h"

unsigned long c_MemMMUCacheEnable[] = { 0xaab9f874, 0 };
unsigned long c_disp_FOTA_Init[] = { 0xbfab9174, 0 };
unsigned long c_disp_FOTA_Printf[] = { 0xb69c410b, 0 };
unsigned long c_OemSysGetSystemInfo[] = { 0xc3ac31a5, 0 };
unsigned long c___PfsNandInit[] = { 0xa5fef2be, 0 };
unsigned long c___PfsMassInit[] = { 0x24428179, 0 };
unsigned long c_tfs4_stat[] = { 0x603fe251, 0 };
unsigned long c_tfs4_open[] = { 0x3494b08a, 0 };
unsigned long c_tfs4_read[] = { 0xc6a58dfd, 0 };
unsigned long c_tfs4_close[] = { 0x0f926882, 0 };



unsigned long *fun_crc[i_endMarker] = {c_MemMMUCacheEnable,
                                       c_disp_FOTA_Init,
                                       c_disp_FOTA_Printf,
                                       c_OemSysGetSystemInfo,
                                       c___PfsNandInit,
                                       c___PfsMassInit,
                                       c_tfs4_stat,
                                       c_tfs4_open,
                                       c_tfs4_read,
                                       c_tfs4_close,
   };
   