; str_cpy_asm and str_length_asm functions			(StrCpyAsm.asm)

.586
.model flat, C
str_length_asm Proto, stringPtr:Ptr Byte
str_cpy_asm Proto, sourceBegin:Ptr Byte, sourceEnd:Ptr Byte, targetPtr:Ptr Byte

.code
;------------------------------------------------------------------------------
; Calculates zero terminated string length returned in eax register.
; Receives: stringPtr - pointer to the string.
; Returns: eax - length of the string.
;------------------------------------------------------------------------------
str_length_asm Proc Uses esi,
					stringPtr:Ptr Byte
	mov esi,stringPtr
	xor eax,eax

	L1:
		cmp Byte Ptr[esi],0
		je L2
		inc esi
		inc eax
		jmp L1

	L2:
		ret
str_length_asm EndP

;------------------------------------------------------------------------------
; Copies a string from source to target.
; Receives: sourceBegin - pointer to the begin of source string,
;			sourceEnd - pointer to the end of the source string,
;			targetPtr - pointer to the target stting,
; Returns: nothing.
;------------------------------------------------------------------------------
str_cpy_asm Proc Uses ecx esi edi,
					sourceBegin:Ptr Byte,
					sourceEnd:Ptr Byte,
					targetPtr:Ptr Byte
	mov ecx,sourceEnd
	sub ecx,sourceBegin
	mov esi,sourceBegin
	mov edi,targetPtr
	cld
	rep movsb

	ret
str_cpy_asm EndP
End
