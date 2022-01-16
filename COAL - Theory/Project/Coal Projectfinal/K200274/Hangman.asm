

INCLUDE Irvine32.inc



.data
msg4 BYTE "Guessed letter are: ",0
msg3 BYTE "I repeat you one more time the letter what you guessed. ",0
guess BYTE "Guess a letter: ",0
msg2 BYTE "Sorry, you alredy guessed letter ",0
consoleHandle HANDLE 0     ; handle to standard output device
bytesWritten  DWORD ?      ; number of bytes written

message byte "Hangman for coal Project",0
messagesize dword sizeof message

win0				BYTE "+------+       ",0
                    BYTE "|      |       ",0
                    BYTE "|              ",0
                    BYTE "|      O       ",0
                    BYTE "|     /|\      ",0
                    BYTE "|     / \      ",0
                    BYTE "+------------+ ",0
                    BYTE "| YOU   WIN  | ",0
                    BYTE "+------------+ ",0


win1				BYTE "+------+       ",0
                    BYTE "|      |       ",0
                    BYTE "|              ",0
                    BYTE "|      O_      ",0
                    BYTE "|     /|       ",0
                    BYTE "|     / \      ",0
                    BYTE "+------------+ ",0
                    BYTE "| YOU   WIN  | ",0
                    BYTE "+------------+ ",0

win2				BYTE "+------+       ",0
                    BYTE "|      |       ",0
                    BYTE "|              ",0
                    BYTE "|      O/      ",0
                    BYTE "|     /|       ",0
                    BYTE "|     / \      ",0
                    BYTE "+------------+ ",0
                    BYTE "| YOU   WIN  | ",0
                    BYTE "+------------+ ",0



gameOver0			BYTE "+------+       ",0
                    BYTE "|      |       ",0
                    BYTE "|      O       ",0
                    BYTE "|     /|\      ",0
                    BYTE "|     / \      ",0
                    BYTE "|              ",0
                    BYTE "+------------+ ",0
                    BYTE "|  YOU  DIE  | ",0
                    BYTE "+------------+ ",0

gameOver1			BYTE "+------+       ",0
                    BYTE "|     /        ",0
                    BYTE "|   _O         ",0
                    BYTE "|  _/\         ",0
                    BYTE "|   \          ",0
                    BYTE "|              ",0
                    BYTE "+------------+ ",0
                    BYTE "|  YOU  DIE  | ",0
                    BYTE "+------------+ ",0


gameOver3			BYTE "+------+       ",0
                    BYTE "|       \      ",0
                    BYTE "|        O_    ",0
                    BYTE "|        /\_   ",0
                    BYTE "|         /    ",0
                    BYTE "|              ",0
                    BYTE "+------------+ ",0
                    BYTE "|  YOU  DIE  | ",0
                    BYTE "+------------+ ",0

life6			    BYTE "+------+       ",0
					BYTE "|      |       ",0
					BYTE "|              ",0
					BYTE "|              ",0
					BYTE "|              ",0
					BYTE "|              ",0
					BYTE "+------------+ ",0
					BYTE "|            | ",0
					BYTE "+------------+ ",0

life5			 	BYTE "+------+       ",0
					BYTE "|      |       ",0
					BYTE "|      O       ",0
					BYTE "|              ",0
					BYTE "|              ",0
					BYTE "|              ",0
					BYTE "+------------+ ",0
					BYTE "|            | ",0
					BYTE "+------------+ ",0

life4			 	BYTE "+------+       ",0
					BYTE "|      |       ",0
					BYTE "|      O       ",0
					BYTE "|      |       ",0
					BYTE "|              ",0
					BYTE "|              ",0
					BYTE "+------------+ ",0
					BYTE "|            | ",0
					BYTE "+------------+ ",0

life3				BYTE "+------+       ",0
					BYTE "|      |       ",0
					BYTE "|      O       ",0
					BYTE "|     /|       ",0
					BYTE "|              ",0
					BYTE "|              ",0
					BYTE "+------------+ ",0
					BYTE "|            | ",0
					BYTE "+------------+ ",0

life2				BYTE "+------+       ",0
					BYTE "|      |       ",0
					BYTE "|      O       ",0
					BYTE "|     /|\      ",0
					BYTE "|              ",0
					BYTE "|              ",0
					BYTE "+------------+ ",0
					BYTE "|            | ",0
					BYTE "+------------+ ",0

life1				BYTE "+------+       ",0
					BYTE "|      |       ",0
					BYTE "|      O       ",0
					BYTE "|     /|\      ",0
					BYTE "|     /        ",0
					BYTE "|              ",0
					BYTE "+------------+ ",0
					BYTE "|            | ",0
					BYTE "+------------+ ",0

life0				BYTE "+------+       ",0
					BYTE "|      |       ",0
					BYTE "|      O       ",0
					BYTE "|     /|\      ",0
					BYTE "|     / \      ",0
					BYTE "|              ",0
					BYTE "+------------+ ",0
					BYTE "|            | ",0
					BYTE "+------------+ ",0

addressArr DWORD OFFSET life0, OFFSET life1,OFFSET life2,OFFSET life3,OFFSET life4,OFFSET life5,OFFSET life6
gameOverAddr DWORD OFFSET gameOver0, OFFSET gameover1, OFFSET gameOver0, OFFSET gameOver3
winAddr DWORD OFFSET win0, OFFSET win1, OFFSET win2, OFFSET win1
messageAddr DWORD ?
; random number what we generete
ranNum DWORD ?		

;All words what is posible to guess. 
;Pick by random generartor and put in selectedWords



manyWords	BYTE "PROGRAMMING",	0
			BYTE "ASSEMBLY", 0
			BYTE "TREE", 0
			BYTE "LINEAR", 0
			BYTE "SAMEER", 0
			BYTE "NASHIT", 0
			BYTE "ASHAR", 0
			BYTE "GAME", 0
			BYTE "HANGMAN", 0
			BYTE "HELLO", 0
			BYTE 0					
len equ $ - manyWords

; number what we make to know where are you in game
statusGameLive DWORD ?		

;Wordls what we select by random code
selectedWords BYTE "                    ", 0
;Use as variable in funcstion for lenght of Array
lengthArray DWORD ?

;Letter what we guess, input from keyboard
guessLetter BYTE ?

;World what we print with -------,0
guessWords BYTE 50 DUP (?)

;Array of guess Letter
guessLetterArray BYTE 50 DUP (?)
chardelete   BYTE 'A'

;Letter what are unknows, change with - 
letterDash BYTE '-'

drowDelay = 1000	; delay 1 sec
var_loop BYTE 3; repeat 15 times
temp dword ?

	
.code

main PROC

  ; Get the console output handle:
	INVOKE GetStdHandle, STD_OUTPUT_HANDLE
	
	mov consoleHandle,eax
	

jump_game_start_again:

  ; Write a string to the console:

	call CRLF
	mov edx, OFFSET message
	call WriteString
	call CRLF
	mov edx,0


  ;Part of code for generate random number from 0 until 9
	mov  eax,10			;get random 0 to 9
	call Randomize		;re-seed generator
	call RandomRange   
	mov  ranNum,eax		;save random number
	
	call Crlf			;new line

  ;Find a selectedWords base on generate ranNum from manyWords
	mov edx, ranNum     ;Index
	call find_str       ;Returns EDI = pointer to string, we pick world

  ;Copy find world in variable selectedWords
	INVOKE Str_copy,
        ADDR [edi],
        ADDR selectedWords
  


  ;Make array of dash. It would be world that we guess
	call make_array_dash

  ;Intialization number of life what you have
	mov statusGameLive, 6

again_input_world:

  ;Print figure depending on the number of lives
	call printHangmanLive

  ;Check if you have more live. If player lost all lives, game is over
	cmp statusGameLive, 0
	je loop_game_over

	mov edx,offset guess
	call writestring

	call readChar	;User inputs char
	cmp al, 27		;Check if is press ESC
	je exit_main	;YES, end game
	cmp al, 32		;Check if is press SPACE
	call clrscr
	;je restart_game	;YES, restart game
	and al, 0DFH	;Convert lowercase input to uppercase. 
					;If uppercase, it remains uppercase
	push eax
	sub al, 'A'		;checks if it is a letter
    cmp al, 'Z'-'A'
    jbe uppercase
	jmp again_input_world
uppercase:
	pop eax
	mov guessLetter, al
	call WriteChar
	call Crlf		;new line
	call Crlf		;new line


	;Check if letter is alredy guessed
	mov ecx, LENGTHOF guessLetterArray
	mov edi, offset guessLetterArray
	mov al, guessLetter                 ; Load character to find
	repne scasb                         ; Search
	je loop_guess_letter_exists			; Letter already exist
		

	call guessing 


	;Check if letter is in selectedWords. If not take life
	mov ecx, LENGTHOF selectedWords
	mov edi, offset selectedWords
	mov al, guessLetter                 ; Load character to find
	repne scasb                         ; Search
	jne loop_take_live					; Letter exist take life


  ; We are making new array, guess letter whange dash on right pleace
    mov esi, offset selectedWords       ; Source
    mov edi, offset guessWords          ; Destination
    mov ecx, LENGTHOF selectedWords     ; Number of bytes to check
    mov al, guessLetter                 ; Search for that character
    xor ebx, ebx                        ; Index EBX = 0

ride_hard_loop:
    cmp [esi+ebx], al                   ; Compare memory/register
    jne @F                              ; Skip next line if no match
    mov [edi+ebx], al                   ; Hang 'em lower
    @@:
    inc ebx                             ; Increment pointer
    dec ecx                             ; Decrement counter
    jne ride_hard_loop                  ; Jump if ECX != 0

 
  ;Is there more letter to guess of we finish
	mov ecx, LENGTHOF guessWords		
    mov edi, offset guessWords
    mov al, letterDash                  ; Load character to find
    repne scasb							; Search
    jne loop_game_win					; No more letter
	jmp again_input_world				; Guess next world


exit_main:
		
	INVOKE ExitProcess,0

loop_guess_letter_exists:


		mov edx,offset msg2
		call writestring

		mov al, guessLetter
		call WriteChar
		call Crlf                       ; new line
		mov edx,offset msg3
		call writestring
		call Crlf                       ; new line
		mov edx,offset msg4
		call writestring

		mov edx, offset guessLetterArray
		call WriteString                ; write a string pointed to by EDX
		call Crlf                       ; new line
		call Crlf						; new line

		jmp again_input_world			; Guess next letter	

loop_take_live:

		dec statusGameLive
		jmp again_input_world			; Guess next letter


loop_game_win:
	
		
	push offset winAddr
	call Animation
	pop messageAddr
	
	dec var_loop
	cmp var_loop, 0
	jne loop_game_win

	
	jmp jump_game_start_again		
	

	
loop_game_over:
	
	

	push offset gameOverAddr
	call Animation
	pop messageAddr

	
	dec var_loop
	cmp var_loop, 0
	jne loop_game_over


	jmp jump_game_start_again				


main ENDP

Animation PROC
	
	push ebp
	mov ebp, esp

	push ecx
	push edx
	push eax

	mov ecx, 0

	L2:
		mov edx, [ebp+8]
		mov messageAddr, edx
		mov eax, 4
		mul ecx
		add messageAddr, eax
		mov eax, [messageAddr]

		mov edx, [eax]
		mov messageAddr, edx
		push messageAddr
		mov dh,0
		mov dl,15
		call gotoxy
		call printSequence
		
		mov eax, 300
		call Delay
		pop messageAddr
		inc ecx
		cmp ecx, 3
		jle l2
	pop eax
	pop edx
	pop ecx
	pop ebp
	ret

Animation endp

find_str PROC					; ARG: EDX = index
    lea edi, manyWords          ; Address of string list

    mov ecx, len                ; Maximal number of bytes to scan
    xor al, al                  ; Scan for 0

    @@:
    sub edx, 1					
    jc done                     ; No index left to scan = string found
    repne scasb                 ; Scan for AL
    jmp @B                      ; Next string

  done:
	ret

find_str ENDP                   ; RESULT: EDI pointer to string[edx]



printHangmanLive Proc

	push eax
	push ecx
	mov ecx, 7
	mov messageAddr, OFFSET addressArr
	L1:
		mov temp, ecx
		dec temp
		mov eax, statusGameLive
		cmp temp, eax
		je printLife

		loop L1

	printLife:
		mov temp, 4
		mul temp
		add messageAddr, eax
		mov eax, [messageAddr]
		push [eax]
		call printSequence
		pop messageAddr

			;--------------code I moved from above part------------------


			call Crlf						; new line
			call Crlf						; new line
			mov edx, offset guessWords
			call WriteString                ; write a string pointed to by EDX
			call Crlf                       ; new line
			call Crlf						; new line
			
			mov edx,offset msg4
			call writestring

			mov edx, offset guessLetterArray
			call WriteString                ; write a string pointed to by EDX
			call Crlf                       ; new line
			call Crlf                       ; new line

			;-------------------------------------------------------------

		;mov edx, [messageAddr]
		;mov edx, [edx]
		;call writeString
		pop ecx
		pop eax

	ret

printHangmanLive endp




make_array_dash PROC     
	mov  edx,OFFSET selectedWords
    call StrLength              ; Length of a null-terminated string pointed to by EDX
    mov  lengthArray,eax

    mov al, '-'                 ; Default charcter for guessWords
    mov ecx, lengthArray		; REP counter
    mov edi, offset guessWords  ; Destination
    rep stosb                   ; Build guessWords
    mov BYTE PTR [edi], 0       ; Store the null termination

    ret
make_array_dash ENDP  

guessing PROC     
	mov  edx, OFFSET guessLetterArray
    call StrLength				; Length of a null-terminated string pointed to by EDX
    mov  lengthArray, eax

    mov edi, offset guessLetterArray ; Destination
    add edi, lengthArray
	mov al, guessLetter
	mov BYTE PTR [edi], al      ; Store guessLetter
	inc edi
	mov BYTE PTR [edi], ','     ; Store the null termination

    ret
guessing ENDP  

printSequence PROC
	push ebp
	mov ebp, esp
	push edx
	push ecx

	mov edx, [ebp+8]
	mov ecx, 9

	L1:

		call crlf
		call writeString
		add edx, 16

	loop L1



		pop ecx
		pop edx
		pop ebp

	ret
printSequence endp
	

END main
