#include "BL3.h"

unsigned long c_MemMMUCacheEnable[] = { 0xaab9f874, 0 };
unsigned long c_disp_FOTA_Init[] = { 0x1e2e7815, 0 };
unsigned long c_disp_FOTA_Printf[] = { 0x2f35cab2, 0 };
unsigned long c_OemSysGetSystemInfo[] = { 0x745ec423, 0 };
unsigned long c___PfsNandInit[] = { 0xa5fef2be, 0 };
unsigned long c___PfsMassInit[] = { 0x24428179, 0 };
unsigned long c_tfs4_stat[] = { 0x603fe251, 0 };
unsigned long c_tfs4_open[] = { 0x3494b08a, 0 };
unsigned long c_tfs4_read[] = { 0xc6a58dfd, 0 };
unsigned long c_tfs4_close[] = { 0x0f926882, 0 };
unsigned long c_MemoryCardMount[] = { 0x555c5307, 0 };
unsigned long c_DRV_Modem_BootingStart[] = { 0xf5a200e1, 0 };
unsigned long c_disp_Normal_Init[] = { 0xa5f01bd4, 0 };
unsigned long c_Flash_Read_Data[] = { 0x7dc705fa, 0 };
unsigned long c_disp_First_Image[] = {0x49bcf18e,0};

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
                                       c_MemoryCardMount,
                                       c_DRV_Modem_BootingStart,
                                       c_disp_Normal_Init,
                                       c_Flash_Read_Data,
                                       c_disp_First_Image,
                                                                 };