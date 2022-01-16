INCLUDE Irvine32.inc
.data
message byte "Enter no of colomns: ",0
pattern byte "Pattern: ",0
.code

MAIN PROC 
mov edx,OFFSET message
call writestring
call readdec
call crlf
call crlf
call crlf
push eax ; stack =5 
call fun
exit 
main ENDP

fun PROC
push ebp 
mov ebp,esp
mov eax,[ebp+8] 
mov edx, OFFSET pattern
call writestring
call crlf
mov ecx,eax
mov esi,0
mov eax,0
mov ebx,0
mov al,'*'
mov bl,' '
L1:
	mov edx,ecx
	mov al,bl
	L3:
	call writechar
	loop L3
	mov al,'*'
	mov ecx,edx
	inc esi
	mov ecx,esi
	L2:
	call writechar
	Loop L2
	mov ecx,edx
	call crlf
loop L1

pop ebp
ret 4
fun ENDP
END MAIN