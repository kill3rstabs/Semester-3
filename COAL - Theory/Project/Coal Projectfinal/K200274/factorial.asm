INCLUDE Irvine32.inc
.data
tableB DWORD 1,2,3,4,5,6,7,8,9,10
row_size = ($-tableB)
DWORD 11,12,13,14,15,16,17,18,19,20
row_index = 1
col_index = 2
.code

main PROC
mov esi,offset tableB
add esi,(row_size*row_index)+col_index

mov eax,[esi*tableB] ;array[1][2] = 13
call writedec
	

	call crlf
exit
main ENDP
END main