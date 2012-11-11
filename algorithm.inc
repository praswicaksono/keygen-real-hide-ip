DoKey	proto	:DWORD
GetRandSerial proto :DWORD,:DWORD

.data
ToDec		db "%.2d",0
PubKey	db	"1CC74813BE6F01D6DF007E5E5944CF23",0
PrvtKey	db	"175DDFAB4688289098139063930917DB",0
szTable	db	"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ",0

SNBuffer	db	256 dup(?)
MCode		db	256 dup(?)
UnlockBuffer	db	256	dup(?)
PlainText		db	256	dup(?)
Seed		dd	?

.code
_rand	proc	Var:DWORD
push ebx
mov eax,Var
xor ebx,ebx
imul edx,dword ptr ds:[ebx+Seed],08088405h
inc edx
mov dword ptr ds:[ebx+Seed],edx
mul edx
mov eax,edx
pop ebx
	Ret
_rand EndP

GetRandSerial	proc	_retval:dword, _range:dword


xor eax,eax
mov esi,_range
@@:
push esi
call _rand
cmp eax,4
jbe @b
mov _retval,eax

	Ret
GetRandSerial EndP

DoKey proc	hWnd:dword

local _N:DWORD,_C:DWORD,_D:DWORD,_M:DWORD


invoke _BigCreate,0
mov _N,eax
invoke _BigCreate,0
mov _D,eax
invoke _BigCreate,0
mov _M,eax
invoke _BigCreate,0
mov _C,eax

invoke _BigIn,addr PubKey,10h,_N
invoke _BigIn,addr PrvtKey,10h,_D



mov edi,offset MCode
add edi,3
invoke RtlMoveMemory,addr PlainText,edi,10h

invoke _BigIn,addr PlainText,10h,_M
invoke _BigPowMod,_M,_D,_N,_C
invoke _BigOut,_C,16,addr UnlockBuffer

invoke lstrlen,addr UnlockBuffer
cmp eax,32
je @f
mov ecx,32
sub ecx,eax
invoke RtlFillMemory,addr UnlockBuffer+100,ecx,30h
@@:
invoke lstrcat,addr UnlockBuffer+100,addr UnlockBuffer

invoke SetDlgItemText,hWnd,EditUnlock,addr UnlockBuffer+100

invoke _BigDestroy,_N
invoke _BigDestroy,_D
invoke _BigDestroy,_C
invoke _BigDestroy,_M

invoke RtlZeroMemory,addr SNBuffer,sizeof SNBuffer
invoke RtlZeroMemory,addr UnlockBuffer,sizeof UnlockBuffer
invoke RtlZeroMemory,addr PlainText,sizeof PlainText
invoke RtlZeroMemory,addr MCode,sizeof MCode

	Ret
DoKey EndP