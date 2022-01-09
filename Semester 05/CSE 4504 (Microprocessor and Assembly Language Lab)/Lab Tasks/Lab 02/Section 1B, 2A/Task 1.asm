ORG 0100h

MAIN PROC
 
    MOV AH,1            ; input a single character
    INT 21h
    
    MOV BL, AL          ; copy to BL, AL gets changed
    
    MOV AH, 2
    MOV DL, 0Dh         ; carriage return
    INT 21h
    MOV DL, 0Ah         ; line feed
    INT 21h
    
    MOV AX, 0
    MOV AL,BL           ; copy back to AL
    MOV BL,2            ; store 2 in BL
    
    DIV BL              ; DIV AX by BL
    CMP AH,0
    JE display_even     ; if even, go to even
    JNE display_odd     ; if odd, go to odd
    
display_odd: 

    MOV AH,2
    MOV DL, 'O'
    INT 21h
    JMP end_prog        ; jump to end
     
display_even:
    
    MOV AH,2
    MOV DL, 'E'
    INT 21h
    
end_prog:
    MAIN ENDP
END MAIN
RET