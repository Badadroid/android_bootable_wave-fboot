#include "BL3.h"

unsigned long c_MemMMUCacheEnable[] = { 0x62eb8516, 0x2cc21166, 0 };
unsigned long c_disp_FOTA_Init[] = { 0xfce927f6, 0x7f03eeb8, 0 };
unsigned long c_disp_FOTA_Printf[] = { 0x19720930, 0x272c03e4, 0 };
unsigned long c_OemSysGetSystemInfo[] = { 0xa5004e30, 0xafce0037, 0 };
unsigned long c___PfsNandInit[] = { 0x0ec652ac, 0 };
unsigned long c___PfsMassInit[] = { 0xa5dc6382, 0 };
unsigned long c_tfs4_stat[] = { 0x5ad2c563, 0x603fe251, 0 };
unsigned long c_tfs4_open[] = { 0xe5a3efa4, 0x3494b08a, 0 };
unsigned long c_tfs4_read[] = { 0x5aff2383, 0xc6a58dfd, 0 };
unsigned long c_tfs4_close[] = { 0x12510dab, 0x0f926882, 0 };



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