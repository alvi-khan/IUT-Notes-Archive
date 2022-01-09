ORG 100h

.DATA
input DB ?, ?, ?, ?, ?
oddNums DB ?, ?, ?, ?, ?
oddLen DB 0
evenNums DB ?, ?, ?, ?, ?
evenLen DB 0
oddOut DB 'Odd: $'
evenOut DB 'Even: $'

.CODE

MAIN PROC
    MOV CL, 5               
    MOV SI, 0               
    
    inputLoop:              
        CALL getInput                  
    LOOP inputLoop
 
    MOV CL, 5
    MOV SI, 0
    MOV BL, 2
    MOV BP, 0
    
    sortOdd:
        XOR AH, AH
        MOV AL, input[SI]
        DIV BL
        CMP AH, 0
        JNE storeOdd
        oddReturn:
        INC SI
    LOOP sortOdd
    
    MOV CL, 5
    MOV SI, 0
    MOV BP, 0
    
    sortEven:
        XOR AH, AH
        MOV AL, input[SI]
        DIV BL
        CMP AH, 0
        JE storeEven
        evenReturn:
        INC SI
    LOOP sortEven
    
    JMP endProgram
    
    storeOdd:
        MOV AL, input[SI]
        MOV oddNums[BP], AL
        MOV AL, oddLen
        INC AL
        MOV oddLen, AL
        INC BP
        JMP oddReturn
    storeEven:
        MOV AL, input[SI]
        MOV evenNums[BP], AL
        MOV AL, evenLen
        INC AL
        MOV evenLen, AL
        INC BP
        JMP evenReturn
    
    endProgram:
        
        MOV AH, 02h                 
        MOV DL, 0Dh                 
        INT 21h
        MOV DL, 0Ah                 
        INT 21h
        
    MOV AH, 09h               
    MOV DX, OFFSET oddOut
    INT 21h
    
    MOV CL, oddLen
    CMP CL, 0
    JE skipOdd
    MOV SI, 0
    oddPrint:
        MOV AH, 02h
        MOV DL, oddNums[SI]
        ADD DL, 48
        INT 21h
        INC SI
        LOOP oddPrint:
    
    skipOdd:
    
    
    MOV AH, 02h                 
    MOV DL, 0Dh                 
    INT 21h
    MOV DL, 0Ah                 
    INT 21h
        
    MOV AH, 09h               
    MOV DX, OFFSET evenOut
    INT 21h
    
    MOV CL, evenLen
    CMP CL, 0
    JE skipEven
    MOV SI, 0
    evenPrint:
        MOV AH, 02h
        MOV DL, evenNums[SI]
        ADD DL, 48
        INT 21h
        INC SI
        LOOP evenPrint:
    
    skipEven:    
        
        
    
        
RET    
MAIN ENDP



getInput PROC
    MOV AH, 01h         
        INT 21h
        SUB AL, 48          
        MOV input[SI], AL
        INC SI
        RET
    
getInput ENDP


END MAIN