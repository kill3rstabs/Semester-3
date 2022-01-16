Include Irvine32.inc
.data
msg1 BYTE "Enter till you wanna calculate fibnacci: ",0

.code

main PROC


	;taking input 
	mov edx,offset msg1
	call writestring 
	call readint


	;loop till that value
	mov ecx,eax
	mov ebx,0
	L1:
		push ebx
		call fib
		inc ebx
		call writedec
		mov eax,','
		call writechar
	LOOP L1


	call crlf
	exit
main ENDP
;fibnacci procedure 
FIB PROC

	push ebp ; pushing ebp
	mov ebp,esp
	sub esp,4 ;  allocating space for 1 local variable
	cmp DWORD PTR [ebp+8],0 ;comparing n and 0 
	jne OneorGreater ;if not equals to then jump to the OneorGreater label
	mov eax,0; eax = 0
	jmp done ;

oneorGreater:
	cmp DWORD PTR [ebp+8],1 ; comparing n and 1 
	jne twoOrGreater ; n not equals to 1 then jump to twoorgreater
	mov eax,1
	jmp done


twoOrGreater:
	mov eax,[ebp+8] ; eax = n
	dec eax ;eax = eax-1
	push eax ; eax pushed onto stack
	call FIB ; recursive call to fib func
	mov [ebp-4],eax ; eax = local_variable
	mov eax,[ebp+8] ; eax = n 
	sub eax,2 ; eax = eax -2 
	push eax ; eax is pushed onto stack
	call fib ; calling fib func recursively 
	add eax,[ebp-4] ; eax = local_variable 


done:
	add esp,4 ; local variable is been popped
	pop ebp ; pop ebp
	ret 4 ; popping n


FIB ENDP
end main
