.586
.model flat, stdcall
includelib libucrt.lib
includelib kernel32.lib
includelib "D:\KPO\Compiler\IDI-2022\Debug\IDI_Lib.lib"
ExitProcess PROTO:DWORD 
.stack 4096

 outnum PROTO : DWORD

 outstr PROTO : DWORD

 outstrline PROTO : DWORD

 outnumline PROTO : DWORD

 system_pause PROTO 

 random PROTO  : DWORD

 sqrt_num PROTO  : DWORD

 power PROTO : DWORD, : DWORD
.const
 zero BYTE 'ERROR: DIVISION BY ZERO', 0
 overflow BYTE 'ERROR: VARIABLE OVERFLOW', 0 
	L1 SDWORD 2
	L2 SDWORD 0
	L3 DWORD 1
	L4 DWORD 0
	L5 BYTE '+', 0
	L6 BYTE '-', 0
	L7 BYTE '/', 0
	L8 BYTE '*', 0
	L9 BYTE ' ', 0
	L10 BYTE 'Squaring and finding the square root of a number', 0
	L11 SDWORD 9
	L12 BYTE 'Our number: ', 0
	L13 BYTE 'Number squared: ', 0
	L14 BYTE 'Square root: ', 0
	L15 SDWORD 7
	L16 SDWORD 6
	L17 BYTE 'Our Operation ', 0
	L18 BYTE ' + ', 0
	L19 BYTE ' = ', 0
	L20 BYTE ' - ', 0
	L21 BYTE ' / ', 0
	L22 BYTE ' * ', 0
	L23 BYTE 'Check randoms 5 numbs for even', 0
	L24 SDWORD 5
	L25 BYTE 'Number ', 0
	L26 BYTE ' is ', 0
	L27 BYTE 'even', 0
	L28 BYTE 'odd', 0
	L29 SDWORD 1
.data
	_CheckEvenRemains SDWORD 0
	_CheckEvenEven DWORD 0
	_OperationRes SDWORD 0
	_DegreeNumb SDWORD 0
	_DegreePowNumb SDWORD 0
	_DegreeSqrtNumb SDWORD 0
	main_x SDWORD 0
	main_y SDWORD 0
	main_plus DWORD ?
	main_minus DWORD ?
	main_division DWORD ?
	main_hum DWORD ?
	main_OurText DWORD ?
	main_Result SDWORD 0
	main_num SDWORD 0
	main_isEven DWORD 0
	main_c SDWORD 0

.code

_CheckEven PROC _CheckEvennumb :  SDWORD 
	push _CheckEvennumb
	push L1
	pop ebx
	pop eax
	cmp ebx,0
	je NULL_DIVISION
	cdq
	idiv ebx
	push edx
	pop _CheckEvenRemains

	mov eax, _CheckEvenRemains
	mov ebx, L2
	.IF SDWORD PTR eax  ==  SDWORD PTR ebx
	push L3
	pop _CheckEvenEven

	.ELSE
	push L4
	pop _CheckEvenEven


	.ENDIF
	mov eax, _CheckEvenEven
	ret

NULL_DIVISION:
push offset zero
call outstrline
call system_pause
push -1
call ExitProcess

VAR_OVERFLOW:
push offset overflow
call outstrline
call system_pause
push -2
call ExitProcess
_CheckEven ENDP
_Operation PROC _Operationoper :  DWORD , _Operationx :  SDWORD , _Operationy :  SDWORD 
	mov esi, _Operationoper
	mov edi, offset L5
	mov eax, 0
	.WHILE eax == 0

		mov dl, BYTE PTR [edi]
		.IF dl == 0
			mov dl, BYTE PTR [esi]
			.IF dl == 0
				mov eax, 2
			.ENDIF
		.ENDIF

		mov dl, BYTE PTR [edi]
		mov bl, BYTE PTR [esi]
		.IF dl != bl
			mov eax, 1
		.ENDIF

		inc esi;
		inc edi;
	.ENDW

	.IF eax  ==  2
	push _Operationx
	push _Operationy
	pop eax
	pop ebx
	add eax, ebx
	jo VAR_OVERFLOW
	.IF eax < 4294967168
		.IF eax > 127
			jmp VAR_OVERFLOW
		.ENDIF
	.ENDIF
	push eax
	pop _OperationRes


	.ENDIF
	mov esi, _Operationoper
	mov edi, offset L6
	mov eax, 0
	.WHILE eax == 0

		mov dl, BYTE PTR [edi]
		.IF dl == 0
			mov dl, BYTE PTR [esi]
			.IF dl == 0
				mov eax, 2
			.ENDIF
		.ENDIF

		mov dl, BYTE PTR [edi]
		mov bl, BYTE PTR [esi]
		.IF dl != bl
			mov eax, 1
		.ENDIF

		inc esi;
		inc edi;
	.ENDW

	.IF eax  ==  2
	push _Operationx
	push _Operationy
	pop ebx
	pop eax
	sub eax, ebx
	jo VAR_OVERFLOW
	.IF eax < 4294967168
		.IF eax > 127
			jmp VAR_OVERFLOW
		.ENDIF
	.ENDIF
	push eax
	pop _OperationRes


	.ENDIF
	mov esi, _Operationoper
	mov edi, offset L7
	mov eax, 0
	.WHILE eax == 0

		mov dl, BYTE PTR [edi]
		.IF dl == 0
			mov dl, BYTE PTR [esi]
			.IF dl == 0
				mov eax, 2
			.ENDIF
		.ENDIF

		mov dl, BYTE PTR [edi]
		mov bl, BYTE PTR [esi]
		.IF dl != bl
			mov eax, 1
		.ENDIF

		inc esi;
		inc edi;
	.ENDW

	.IF eax  ==  2
	push _Operationx
	push _Operationy
	pop ebx
	pop eax
	cmp ebx,0
	je NULL_DIVISION
	cdq
	idiv ebx
	jo VAR_OVERFLOW
	.IF eax < 4294967168
		.IF eax > 127
			jmp VAR_OVERFLOW
		.ENDIF
	.ENDIF
	push eax
	pop _OperationRes


	.ENDIF
	mov esi, _Operationoper
	mov edi, offset L8
	mov eax, 0
	.WHILE eax == 0

		mov dl, BYTE PTR [edi]
		.IF dl == 0
			mov dl, BYTE PTR [esi]
			.IF dl == 0
				mov eax, 2
			.ENDIF
		.ENDIF

		mov dl, BYTE PTR [edi]
		mov bl, BYTE PTR [esi]
		.IF dl != bl
			mov eax, 1
		.ENDIF

		inc esi;
		inc edi;
	.ENDW

	.IF eax  ==  2
	push _Operationx
	push _Operationy
	pop eax
	pop ebx
	imul ebx
	jo VAR_OVERFLOW
	.IF eax < 4294967168
		.IF eax > 127
			jmp VAR_OVERFLOW
		.ENDIF
	.ENDIF
	push eax
	pop _OperationRes


	.ENDIF
	mov eax, _OperationRes
	ret

NULL_DIVISION:
push offset zero
call outstrline
call system_pause
push -1
call ExitProcess

VAR_OVERFLOW:
push offset overflow
call outstrline
call system_pause
push -2
call ExitProcess
_Operation ENDP
_Degree PROC 

	push offset L9
	call outstrline

	push offset L10
	call outstrline
	push L11
	pop _DegreeNumb

	push power
	push _DegreeNumb
	push L1
	pop edx
	pop edx
	pop edx
	push L1
	push _DegreeNumb
		call power
	push eax
	pop _DegreePowNumb

	push sqrt_num
	push _DegreeNumb
	pop edx
	pop edx
	push _DegreeNumb
		call sqrt_num
	push eax
	pop _DegreeSqrtNumb


	push offset L12
	call outstr

	push _DegreeNumb
	call outnumline

	push offset L13
	call outstr

	push _DegreePowNumb
	call outnumline

	push offset L14
	call outstr

	push _DegreeSqrtNumb
	call outnumline
	ret

NULL_DIVISION:
push offset zero
call outstrline
call system_pause
push -1
call ExitProcess

VAR_OVERFLOW:
push offset overflow
call outstrline
call system_pause
push -2
call ExitProcess
_Degree ENDP
main PROC
	push L15
	pop main_x

	push L16
	pop main_y


	push main_x
	call outnumline

	push main_y
	call outnumline
	push offset L5
	pop main_plus

	push offset L6
	pop main_minus

	push offset L7
	pop main_division

	push offset L8
	pop main_hum

	push offset L17
	pop main_OurText


	push main_OurText
	call outstr

	push main_plus
	call outstrline
	push _Operation
	push main_plus
	push main_x
	push main_y
	pop edx
	pop edx
	pop edx
	pop edx
	push main_y
	push main_x
	push main_plus
		call _Operation
	push eax
	pop main_Result


	push main_x
	call outnum

	push offset L18
	call outstr

	push main_y
	call outnum

	push offset L19
	call outstr

	push main_Result
	call outnumline

	push main_OurText
	call outstr

	push main_minus
	call outstrline
	push _Operation
	push main_minus
	push main_x
	push main_y
	pop edx
	pop edx
	pop edx
	pop edx
	push main_y
	push main_x
	push main_minus
		call _Operation
	push eax
	pop main_Result


	push main_x
	call outnum

	push offset L20
	call outstr

	push main_y
	call outnum

	push offset L19
	call outstr

	push main_Result
	call outnumline

	push main_OurText
	call outstr

	push main_division
	call outstrline
	push _Operation
	push main_division
	push main_x
	push main_y
	pop edx
	pop edx
	pop edx
	pop edx
	push main_y
	push main_x
	push main_division
		call _Operation
	push eax
	pop main_Result


	push main_x
	call outnum

	push offset L21
	call outstr

	push main_y
	call outnum

	push offset L19
	call outstr

	push main_Result
	call outnumline

	push main_OurText
	call outstr

	push main_hum
	call outstrline
	push _Operation
	push main_hum
	push main_x
	push main_y
	pop edx
	pop edx
	pop edx
	pop edx
	push main_y
	push main_x
	push main_hum
		call _Operation
	push eax
	pop main_Result


	push main_x
	call outnum

	push offset L22
	call outstr

	push main_y
	call outnum

	push offset L19
	call outstr

	push main_Result
	call outnumline

	push offset L9
	call outstrline

	push offset L23
	call outstrline
	push L4
	pop main_isEven

	push L2
	pop main_c

while1:
	mov eax, main_c
	mov ebx, L24

	.IF SDWORD PTR eax  >=  SDWORD PTR ebx
		jmp endwhile1
	.ENDIF

	push random
	push main_c
	pop edx
	pop edx
	push main_c
		call random
	push eax
	pop main_num

	push _CheckEven
	push main_num
	pop edx
	pop edx
	push main_num
		call _CheckEven
	push eax
	pop main_isEven


	push offset L25
	call outstr

	push main_num
	call outnum

	push offset L26
	call outstr
	mov eax, main_isEven
	.IF eax  ==  1

	push offset L27
	call outstrline
	.ELSE

	push offset L28
	call outstrline

	.ENDIF
	push main_c
	push L29
	pop eax
	pop ebx
	add eax, ebx
	jo VAR_OVERFLOW
	.IF eax < 4294967168
		.IF eax > 127
			jmp VAR_OVERFLOW
		.ENDIF
	.ENDIF
	push eax
	pop main_c

	jmp while1

endwhile1:

call _Degree
call system_pause
push 0
call ExitProcess
NULL_DIVISION:
push offset zero
call outstrline
call system_pause
push -1
call ExitProcess
VAR_OVERFLOW:
push offset overflow
call outstrline
call system_pause
push -2
call ExitProcess
main ENDP
end main