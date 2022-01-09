ORG 100h
   
   
   
.DATA                                                       ; Data segment starts 
inputValues DB 5 DUP(0)
reverseValues DB 5 DUP(0)                                   
inputMessage DB 'Enter 5 lowercase letters: $'
outputMessage DB 'Reversed uppercase String: $'
errorMessage DB 0Ah,0Dh,'Sorry, you did not enter a lowercase string. Enter the string again.$'

.CODE                                                       ; Code segment starts

MAIN PROC
    
    MOV AX, @DATA
    MOV DS, AX
    XOR AX, AX
                                                            ; Print Message to enter values
    MOV DX, OFFSET inputMessage
    MOV AH, 09h
    INT 21h     
                                                            
    
    CALL TAKE_INPUT
    CALL REVERSE
    CALL DISPLAY_OUTPUT    
    
    
    ;RET
    MOV AH,4Ch                                              ; MOV AH,4Ch along with INT 21h does the same as RET
    MOV AL,00h                                              ; MOV AL,00h is optional
    INT 21h                                                 ; (MOV AH,4Ch + INT 21h) only works for MAIN PROC, will not work in other Procedures
                                                            ; Exit to DOS
MAIN ENDP



TAKE_INPUT PROC
    
    XOR CX, CX                                              ; Clear count register
    MOV CX, 5                                               ; To take 5 inputs
    MOV SI, 0                                               ; Initialize SI
    
    input_string:
        MOV AH, 01h                                          
        INT 21h
        
        CMP AL,91                                           ; If input is not lowercase, then show error
        JL showError
        
        MOV inputValues[SI], AL
        INC SI
        JMP end_of_loop
    
    showError:
        MOV DX,OFFSET errorMessage                          ; Show error message to enter the lowercase values again
        MOV AH,09h
        INT 21h
        
        MOV AH, 02h
        MOV DL, 0Ah                                         ; to print new line
        INT 21h
        MOV DL, 0Dh                                         ; carriage return
        INT 21h
        
        MOV DX, OFFSET inputMessage
        MOV AH, 09h
        INT 21h
        
        XOR CX,CX
        MOV CX,6                                            
        MOV SI,0
         
    end_of_loop:
    
    LOOP input_string
    
    RET
    
TAKE_INPUT ENDP



REVERSE PROC
    XOR AX, AX
    XOR DX, DX
    
    MOV CX,5
    MOV SI,0                                                
                                                            
    traverse_string:                                        ; traverse input string and store uppercased reversed letters in reverseValues array
    MOV DI,CX
    DEC DI
    MOV AL,inputValues[SI]
    SUB AL,32                                               ; to get uppercase letters
    MOV reverseValues[DI],AL
    INC SI
                                                      
    
    LOOP traverse_string
    
    RET
    
REVERSE ENDP
    
    
DISPLAY_OUTPUT PROC
    MOV AH, 02h
    MOV DL, 0Ah                                             ; to print new line
    INT 21h
    MOV DL, 0Dh                                             ; carriage return
    INT 21h
    
    MOV DX, OFFSET outputMessage                            ; to print "Reversed uppercase String: " String
    MOV AH, 09h
    INT 21h
                                                            
    MOV CX, 5
    MOV SI, 0
    
    print_reverse_array:
        XOR DX,DX
        XOR AX,AX
                                                            ; print the reverse values one by one
        MOV AH, 02h
        MOV DL, reverseValues[SI]
        INT 21h
        
        INC SI
    
    LOOP print_reverse_array
    
    RET
    
DISPLAY_OUTPUT ENDP