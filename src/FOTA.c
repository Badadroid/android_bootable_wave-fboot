/*
 ; This file is part of Badadroid project.
 ;
 ; Copyright (C) 2012 Rebellos, mijoma, b_kubica
 ;
 ;
 ; Badadroid is free software: you can redistribute it and/or modify
 ; it under the terms of the GNU General Public License as published by
 ; the Free Software Foundation, either version 3 of the License, or
 ; (at your option) any later version.
 ;
 ; Badadroid is distributed in the hope that it will be useful,
 ; but WITHOUT ANY WARRANTY; without even the implied warranty of
 ; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ; GNU General Public License for more details.
 ;
 ; You should have received a copy of the GNU General Public License
 ; along with Badadroid.  If not, see <http://www.gnu.org/licenses/>.
 ;
 ;
*/
#include "string.h"
#include "BL3.h"
#include "atag.h"

int main(runMode_t mode)
{
   char* cmdlnRM = "bootmode=2 loglevel=4";
   char* cmdln = "loglevel=4";

   unsigned char ATAG_buf[512]={0};
   fun_t kernel;
   unsigned long kernelSize=7*1024*1024; // size of boot mtd partition

   //show bada splash
   disp_First_Image();

   //start modem
   DRV_Modem_BootingStart();

   setup_core_tag(ATAG_buf);
   setup_serial_tag(0x123, 0x456);
   setup_rev_tag('0');

   if (mode == rm_FOTA_RECOVERY)
      setup_cmdline_tag(cmdlnRM);
   else
      setup_cmdline_tag(cmdln);

   setup_end_tag();

   //copy kernel to the right position
   Flash_Read_Data(&KERNEL_START, &KERNEL_ONENAND, kernelSize);

   //SYSCON operations
   *((unsigned int*)SYSCON_NORMAL_CFG) = 0xFFFFFFFF;
   _CoDisableDCache();
   _System_DisableVIC();
   _System_DisableIRQ();
   _System_DisableFIQ();

   kernel = (fun_t)&KERNEL_START;
   kernel(0, &ATAG_MODEL, ATAG_buf);

   //loop forever
   while(1);

   return 0;
}