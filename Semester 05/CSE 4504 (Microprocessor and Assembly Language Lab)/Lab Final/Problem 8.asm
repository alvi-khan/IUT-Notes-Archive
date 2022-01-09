ORG 100H

.DATA

arr DB 8 DUP(0)   
askForInput DB 'Enter 8 digits between 0 and 9.', 0DH, 0AH, '$'    
odd DB 8 DUP(0)    
oddCount DB 0      
temp DB 0

.CODE

MAIN PROC    
    MOV AH, 9
    LEA DX, askForInput
    INT 21H
    
    MOV CL, 8
    MOV SI, 0 
    
    take_input: 
    
    MOV AH, 01H
    INT 21H  
    SUB AL, 48
    MOV arr[SI], AL
    INC SI   
    
    LOOP take_input 
     
    MOV CL, 8
    MOV SI, 0  
    MOV DI, 0
    XOR AX, AX
     
    sort_out_odd_digits:   
    
    MOV AL, arr[SI]  
    MOV BL, 2  
    MOV DL, AL
    DIV BL
    CMP AH, 0
    JE continue_loop 
    
    INC oddCount
    MOV odd[DI], DL  
    INC DI  
    
    continue_loop:
    
    INC SI
    LOOP sort_out_odd_digits  
    
    XOR CX, CX
    MOV CL, oddCount
    DEC CL
    MOV SI, 0 
    XOR AX, AX
    XOR BX, BX
    
    
    
    sort_numbers:
    
    MOV DI, SI
    INC DI 
    MOV BL, oddCount
    SUB BX, SI
    DEC BX
    
    
    loop2:
    
    MOV AL, odd[SI]
    CMP AL, odd[DI]
    JLE continue_loop2  
    
    MOV AL, odd[SI]
    MOV AH, odd[DI]
    MOV temp, AL
    MOV AL, AH
    MOV AH, temp
    MOV odd[SI], AL
    MOV odd[DI], AH  
    
    continue_loop2: 
        
    INC DI 
    DEC BX 
    CMP BX, 0  
    JNE loop2  
    
    INC SI
    LOOP sort_numbers  
    
    
    
    
    MOV CL, oddCount  
    MOV SI, 0  
    
    MOV AH, 02H
    MOV DL, 0DH
    INT 21H
    
    MOV DL, 0AH  
    INT 21H
    
    print_sorted_odds:
    
    MOV DL, odd[SI] 
    ADD DL, 48
    INT 21H
    
    INC SI
    LOOP print_sorted_odds
                       
    
MAIN ENDP

END MAIN
    
    
     
    
    
    