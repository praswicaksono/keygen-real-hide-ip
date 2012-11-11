.686
.model flat,stdcall
option casemap:none

include keygen.inc

include algorithm.inc


.code
tsrh:

invoke GetModuleHandle,NULL
mov hInstance,eax

invoke LoadIcon,eax,500
mov hIcon,eax

invoke InitCommonControls
invoke DialogBoxParam,hInstance,MainDlg,NULL,addr MainProc,0
invoke ExitProcess,NULL


MainProc	proc	hWnd:DWORD, uMsg:DWORD, wParam:DWORD, lParam:DWORD
.if uMsg == WM_INITDIALOG
invoke SetWindowPos,hWnd,HWND_TOPMOST,0,0,0,0,SWP_NOMOVE+SWP_NOSIZE
invoke SendMessage,hWnd,WM_SETICON,1,hIcon

.elseif uMsg == WM_COMMAND
mov eax,wParam
.if eax == GenBtn
invoke GetDlgItemText,hWnd,EditMachine,addr MCode,sizeof MCode
.if eax >= 16
invoke DoKey,hWnd
.else
invoke SetDlgItemText,hWnd,EditUnlock,chr$("Invalid Machine Code!")
.endif

.elseif eax == GenSNBtn
invoke GetTickCount
mov Seed,eax
push 0FFFFFFFFh
call _rand
invoke wsprintf,addr SNBuffer,chr$("%.8X"),eax
invoke SetDlgItemText,hWnd,EditSerial,addr SNBuffer

.elseif eax == AboutBtn
invoke MessageBox,hWnd,addr aboutText,chr$("About.."),MB_ICONINFORMATION
.endif

.elseif uMsg == WM_CLOSE
invoke EndDialog,hWnd,0
.endif

xor eax,eax
	Ret
MainProc EndP

end tsrh