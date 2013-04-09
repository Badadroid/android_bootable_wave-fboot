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
   .arch armv5te
   .fpu softvfp 
   .org 0x00
   .text
   .global _CoDisableMmu
   .type _CoDisableMmu, %function
   .global _CoDisableDCache
   .type _CoDisableDCache, %function
   .global _System_DisableVIC
   .type _System_DisableVIC, %function
   .global _System_DisableIRQ
   .type _System_DisableIRQ, %function
   .global _System_DisableFIQ
   .type _System_DisableFIQ, %function
   .global DisableMmuCache
   .type DisableMmuCache, %function
   .global oldbootstyle
   .type oldbootstyle, %function

DisableMmuCache:
   MCR	p15, 0, R0,c1,c0
	MOV	PC, LR
   
_CoDisableMmu:
	MRC	p15, 0, R0,c1,c0
	BIC	R0, R0, #1
	MCR	p15, 0, R0,c1,c0
	MOV	PC, LR
   
_CoDisableDCache:
	MRC	p15, 0, R0,c1,c0
	BIC	R0, R0, #4
	MCR	p15, 0, R0,c1,c0
	MOV	PC, LR

_System_DisableVIC:
	MRC	p15, 0, R0,c1,c0
	BIC	R0, R0, #0x1000000
	MCR	p15, 0, R0,c1,c0
	BX	LR

_System_DisableIRQ:
	MRS	R0, CPSR
	ORR	R0, R0, #0x80
	MSR	CPSR_cxsf, R0
	BX	LR

_System_DisableFIQ:
	MRS	R0, CPSR
	ORR	R0, R0, #0x40
	MSR	CPSR_cxsf, R0
	BX	LR
oldbootstyle:
   LDR   R0, =0x20000100
   MOV   R1, #0x00
   MOV   R2, #512
   BL    rebell_fillmem 
   LDR   R2, =0x20000100
   MOV   R0, #2
   STR   R0, [R2]
   ADD   R2, R2, #4
   LDR   R0, =0x54410001
   STR   R0, [R2]
   ADD   R2, R2, #4
   MOV   R0, #4
   STR   R0, [R2]
   ADD   R2, R2, #4
   LDR   R0, =0x54410006
   STR   R0, [R2]
   ADD   R2, R2, #4

   STR   R0, [R2]
   ADD   R2, R2, #4

   STR   R0, [R2]
   ADD   R2, R2, #4
   MOV   R0, #3
   STR   R0, [R2]
   ADD   R2, R2, #4
   LDR   R0, =0x54410007
   STR   R0, [R2]
   ADD   R2, R2, #4
   MOV   R0, #0x30
   STR   R0, [R2]
   ADD   R2, R2, #4

   BL    rebell_strlen
   ADD   R0, R0, #1
   MOV   R5, R0
   MOV   R0, R5
   ADD   R0, R0, #0xD
   MOV   R0, R0,LSR#2
   STR   R0, [R2] 
   ADD   R2, R2, #4
   LDR   R0, =0x54410009
   STR   R0, [R2]
   ADD   R2, R2, #4
   MOV   R6, R2

   MOV   R1, R2          
   MOV   R2, R5    
   BL    rebell_memcpy
   MOV   R2, R6
   ADD   R2, R2, R5, LSL#2 
   MOV   R0, #0
   STR   R0, [R2]
   ADD   R2, R2, #4
   MOV   R0, #0 
   STR   R0, [R2]