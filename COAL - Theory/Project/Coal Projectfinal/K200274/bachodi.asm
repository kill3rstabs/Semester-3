include irvine32.inc

.data


Num_msg			BYTE	"Enter a positive number of the values you want to insert: ",0
Input_msg		BYTE	"Enter a 32-bit signed integer: ",0

Selection_Sort: 
		lea ESI,  array 
		mov eax,Itr
		mov OuterCounter,eax
outerloop:
		cmp OuterCounter,0
		jle xx
		dec OuterCounter
		mov eax,OuterCounter
		mov index_max,eax
		dec eax
		mov InnerCounter,eax
		lea ESI,  array	

innerloop: 
		cmp InnerCounter,0
		jl exit1
		lea ESI,  array	
		MOV EDI , index_max				; EDI = indexCounter
		MOV EDX , InnerCounter				;edx=innerCounter        
		SHL EDI,2					; EDI = indexMax *4 
		SHL EDX,2					; ECX = (innercounter)*4
		ADD EDI,ESI					; EDI = offset Array + (indexMax)*4 , EDI = &arr [indexMax]
		ADD EDX,ESI					; EDX = offset Array + (innercounter)*4, EDX= &arr [innercounter]
		MOV EAX,[EDI]					; EAX = arr [indexMax]
		mov EBX,[EDX]					; EBX = arr [innercounter] 
		CMP EBX,EAX					;arr[innercounter] > arr[indexMax] 
		jle mm						;jump if a[indexMax]>arr[innercounter]
		mov edx,InnerCounter				; if arr[innercounter] > arr[indexMax]
		mov index_max,edx				;indexmaximum =innercounter
 mm: 


		dec InnerCounter
		jmp innerloop
		exit1:
		mov EDX ,OuterCounter
		SHL EDX,2	
		ADD EDX,ESI           
;EDX= Address arr [outerCounter]

		mov EDI,index_max
		SHL EDI,2
		ADD EDI,ESI
;EDX= Address arr [index_max]
   
   
		MOV x_ptr,EDX
		MOV Y_ptr,EDI
		mov esi,x_ptr
		mov eax,[esi]
		mov edi,y_ptr
		mov edx,[edi]
		mov [esi],edx
		mov [edi],eax
 
		jmp outerloop
xx:

		jmp Output

