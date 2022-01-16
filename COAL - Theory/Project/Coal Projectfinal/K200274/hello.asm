include irvine32.inc
.data
msg byte "Plese enter a no : ",0,13h,10h
msg1 byte "NO is Even ",0,13h,10h
msg2 byte "No is Odd ",0,13h,10h
num word ?
result word ?
.code
main proc
call clrscr
call crlf
mov edx,offset msg
call writestring
call readint
mov num,ax
mov bx,2
mov ax,num
mov dx,0
div bx
mov result,dx
cmp result,0
JE E
JNE O
E:
call crlf
mov edx,offset msg1
call writestring
jmp stop
O:
call crlf
mov edx,offset msg2
call writestring

stop:
exit
main endp
end main