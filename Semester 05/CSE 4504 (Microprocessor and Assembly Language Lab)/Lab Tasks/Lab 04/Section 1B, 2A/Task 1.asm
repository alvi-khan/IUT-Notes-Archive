ORG 100h
   
   
   
.DATA                                                       ; Data segment starts 
givenString DB 'microprocessors and assembly language lab$'  ; 1-D array for string
dummy DB 00h                                                ; dummy value to calculate string length
getCharacter DB 'Given character: $'                         ; 1-D array for taking character input 
outputMessage DB 'Number of Frequency: $'

.CODE                                                       ; Code segment starts

MAIN PROC

    MOV AX, @DATA
    MOV DS, AX

    XOR AX,AX                                               ; reset AX

    MOV SI, OFFSET givenString
    MOV DI, OFFSET dummy
    MOV DX, OFFSET givenString                              ; Load Effective Address of the given string in DX register


    MOV AH, 09h                                             ; display string function 
    INT 21h                                                 ; display given string (stored in DX)
    
    MOV DL, 10                                              ; to print new line
    MOV AH, 02h
    INT 21h
    MOV DL, 13                                              ; carriage return
    MOV AH, 02h
    INT 21h
    
    MOV DX, OFFSET getCharacter
    MOV AH, 09h                                             ; display string function 
    INT 21h
    
    MOV AH, 01h                                             ; single character input function 
    INT 21h                                                 ; display message to enter character
    
    MOV CX, DI
    SUB CX, SI                                              ; to get string length. Now CX holds the string length 

    MOV BL,0                                                ; to count frequency
    
    calc_frequency: 
        CMP AL, [SI]                                        ; compare given character at AL with string character at SI
        JNE skip                                            ; if doesn't match, skip the increment of frequency
        ADD BL,1                                            ; if mathces, increment the frequency in BL 
        
    
    skip:
        INC SI                                              ; go to next character in string
        LOOP calc_frequency     
    
    
    ADD BL, 48                                              ; to convert the ascii value of the output to decimal
    
    MOV DL, 10                                              ; to print new line
    MOV AH, 02h
    INT 21h
    MOV DL, 13                                              ; carriage return
    MOV AH, 02h
    INT 21h
    
    MOV DX, OFFSET outputMessage
    MOV AH, 09h                                             ; display string function function 
    INT 21h
                                                             
    MOV AH, 02h                                             ; display the output frequency
    MOV DL, BL                                              ; store the frequency in DL
    INT 21h

MAIN ENDP
END MAIN

RET




