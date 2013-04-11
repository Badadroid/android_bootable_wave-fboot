#include "BL3.h"

unsigned long c_MemMMUCacheEnable[] = { 0xaab9f874, 0 };
unsigned long c_disp_FOTA_Init[] = { 0xca28d3bd, 0 };
unsigned long c_disp_FOTA_Printf[] = { 0xc742242e, 0 };
unsigned long c_OemSysGetSystemInfo[] = { 0x384591e6, 0 };
unsigned long c___PfsNandInit[] = { 0x0ec652ac, 0 };
unsigned long c___PfsMassInit[] = { 0xa5dc6382, 0 };
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