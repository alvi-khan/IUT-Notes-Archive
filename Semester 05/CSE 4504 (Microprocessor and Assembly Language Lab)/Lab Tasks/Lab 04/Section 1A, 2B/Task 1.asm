ORG 0100h

.DATA                       ; Data segment starts
numArr DB 1, 4, 9, 16, 25, 36, 49, 64, 81   ; array of values
result DW ?
prompt DB 'Enter the value of N:$'  ; input prompt

.CODE                       ; Code segment starts
MAIN PROC
    MOV SI, OFFSET numArr   ; SI holds start of numArr
    MOV DX, OFFSET prompt   ; DX holds start of prompt

    MOV AH, 09h             ; string output
    INT 21h                 ; displays input prompt

    MOV AH, 01h             ; single-character input
    INT 21h
    MOV CL, AL              ; store user input in CL
    SUB CL, 48              ; convert user input to decimal
    XOR BX, BX              ; reset BX register

    sum:                    ; add first N numbers of numArr
        XOR AX, AX
        MOV AL, [SI]
        ADD BX, AX
        INC SI              ; go to next element
        LOOP sum            ; decrement CL, end when 0

    MOV result, BX          ; save decimal result
MAIN ENDP
END MAIN
RET