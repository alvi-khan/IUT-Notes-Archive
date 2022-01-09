CODE SEGMENT
ASSUME CS:CODE, DS:CODE, ES:CODE, SS:CODE

PPIC_C EQU 1FH  ; Control register address
PPIC EQU 1DH    ; Port C address
PPIB EQU 1BH    ; Port B address
PPIA EQU 19H    ; Port A address

ORG 1000H

MOV AL, 10000000B   ; Control register initialization with a 8255 Mode set
OUT PPIC_C, AL

MOV AL, 11111111B   ; Turning off Port A
OUT PPIA, AL

MOV AL, 00000000B   ; Turning off Port B
OUT PPIC, AL

L1: MOV AL, 11110001B   ; L1
    OUT PPIB, AL
    CALL TIMER
    
    MOV AL, 11110001B   ; L3
    OUT PPIB, AL
    CALL TIMER
    
    MOV AL, 11110001B   ; L2
    OUT PPIB, AL
    CALL TIMER
    
    MOV AL, 11110001B   ; L3
    OUT PPIB, AL
    CALL TIMER
    
    JMP L1
    
TIMER:  MOV CX, 3       ; 3 second timer
TIMER2: PUSH CX
        MOV CX, 0
TIMER1: NOP
        NOP
        NOP
        NOP
        LOOP TIMER1
        POP CX
        LOOP TIMER2
        RET

CODE ENDS
END