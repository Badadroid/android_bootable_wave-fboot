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
   .global SHA1_digest
   .type SHA1_digest, %function

SHA1_digest:
		STMFD	SP!, {R4-R6,LR}
		MOV	R4, R0
		MOV	R0, #1
		MOV	R6, #0xEA000000
		STR	R0, [R6,#0x48]
		MOV	R0, #0
		MOV	R6, #0xEA000000
		STR	R0, [R6,#0x48]
		MOV	R0, #0xC
		LDR	R6, =0xEA006000
		STR	R0, [R6,#0xC]
		MOV	R0, #0xEA000000
		LDR	R5, [R0,#0x14]
		BIC	R5, R5,	#3
		MOV	R0, #0xEA000000
		STR	R5, [R0,#0x14]
		MOV	R5, #0x10
		LDR	R0, =0xEA006000
		STR	R5, [R0]
		MOV	R0, #1
		LDR	R6, =0xEA006000
		STR	R0, [R6,#8]
		LDR	R0, =0xEA006000
		STR	R2, [R0,#0x14]
		MOV	R0, #0
		LDR	R6, =0xEA006000
		STR	R0, [R6,#0x18]
		MOV	R0, #0xEA000000
		STR	R1, [R0,#0x40]
		MOV	R0, #0xEA000000
		STR	R2, [R0,#0x44]

wait_loop:
		LDR	R0, =0xEA006000
		LDR	R0, [R0,#0x10]
		AND	R5, R0,	#0x40
		CMP	R5, #0
		BEQ	wait_loop
		LDR	R0, =0xEA006000
		STR	R5, [R0,#0x10]
		MOV	R3, R4
		LDR	R0, =0xEA006000
		LDR	R0, [R0,#0x60]
		STR	R0, [R3]
		LDR	R0, =0xEA006000
		LDR	R0, [R0,#0x64]
		STR	R0, [R3,#4]
		LDR	R0, =0xEA006000
		LDR	R0, [R0,#0x68]
		STR	R0, [R3,#8]
		LDR	R0, =0xEA006000
		LDR	R0, [R0,#0x6C]
		STR	R0, [R3,#0xC]
		LDR	R0, =0xEA006000
		LDR	R0, [R0,#0x70]
		STR	R0, [R3,#0x10]
		MOV	R0, #2
		MOV	R6, #0xEA000000
		STR	R0, [R6,#0xC]
		MOV	R0, #0
		LDMFD	SP!, {R4-R6,PC}   
