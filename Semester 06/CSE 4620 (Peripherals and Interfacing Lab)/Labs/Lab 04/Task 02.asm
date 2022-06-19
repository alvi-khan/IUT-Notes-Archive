CODE SEGMENT

ASSUME CS:CODE, DS:CODE, ES:CODE, SS:CODE

PPIC_C EQU 1EH ; Control register address
PPIC EQU 1CH ; Port C address
PPIB EQU 1AH ; Port B address
PPIA EQU 18H ; Port A address

ORG 1000H

MOV AL, 10000000B ; All ports set to output
OUT PPIC_C, AL

L1: MOV AL, 00000001B ; Reset port C

L2: OUT PPIC, AL
    
	MOV BL, AL        ; Save port C value in BL
    
	MOV AL, 11111111B ; Turn off port A (green lights)
    OUT PPIA, AL
	
    MOV AL, 00000000B ; Turn on port B (red lights)
    OUT PPIB, AL

    CALL TIMER        ; Timeout (to see lights)
    
	CLC               ; Clear carry flag
    MOV AL, BL        ; Load port C value from BL
    ROL AL, 1         ; Shift port C by one column 
    OUT PPIC, AL
    MOV BL, AL        ; Save port C value in BL
 
    MOV AL, 11111111B ; Turn off Port B (red lights)
    OUT PPIB, AL
	
    MOV AL, 00000000B ; Turn on port A (green lights)
    OUT PPIA, AL

    CALL TIMER        ; Timeout (to see lights)
	
    CLC               ; Clear carry flag
    MOV AL, BL        ; Load port C value from BL
    ROL AL, 1         ; Shift port C by one column

    JNC L2            ; if carry flag is not set (if not out of bounds), start again
    JMP L1            ; otherwise reset and start again
    INT 3

; Timeout code
TIMER:  MOV CX, 0FFFFH
TIMER1: NOP
        NOP
        NOP
        NOP
        LOOP TIMER1
        RET

CODE ENDS
END