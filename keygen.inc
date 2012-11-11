include	windows.inc
include	kernel32.inc
include	user32.inc
include	gdi32.inc
include	ole32.inc
include	oleaut32.inc
include	masm32.inc
include	macros.inc
include	comdlg32.inc
include	winmm.inc
include	shell32.inc
include	comctl32.inc
include	cryptohash.inc
include	biglib.inc

includelib	user32.lib
includelib	kernel32.lib
includelib	gdi32.lib
includelib	ole32.lib
includelib	oleaut32.lib
includelib	masm32.lib
includelib	comdlg32.lib
includelib	winmm.lib
includelib	shell32.lib
includelib	comctl32.lib
includelib	cryptohash.lib
includelib	biglib.lib


MainProc	proto	:DWORD,:DWORD,:DWORD,:DWORD

.const
EditSerial		EQU 104
MainDlg		EQU 100
GenBtn		EQU 201
AboutBtn		EQU 202
LOGO		EQU 200
GenSNBtn		EQU 203
EditMachine		EQU 101
EditUnlock		EQU 102


.data
aboutText	db	"Real Hide IP v4.0.4.2",13,10,13,10
			db	"Keygen by Jowy / TSRh",13,10
			db	"Protection : RSA-128",13,10,13,10
			db	"Greetz to all my friends",0

.data?
hInstance	dd	?
hIcon		dd	?