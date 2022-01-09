ORG 100h
   
   
   
.DATA                                                       ; Data segment starts 
inputValues DB 5 DUP(0)                                     ; Array to store non prime values
nonprimeOutput DB 5 DUP(0)
inputMessage DB 'Enter 5 decimal digits: $'
primeStr DB 'Prime: $'
nonprimeStr DB 'Non-prime: $'

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
    CALL PRIME
    CALL DISPLAY_NONPRIME    
    
    
    RET
    
MAIN ENDP





TAKE_INPUT PROC
    
    XOR CX, CX                                              ; Clear count register
    MOV CL, 5                                               ; To take 5 inputs
    MOV SI, 0                                               ; Initialize SI
    
    input_digits:
        MOV AH, 01h                                          
        INT 21h
        SUB AL, 48                                          ; To get decimal value of the inputs
        MOV inputValues[SI], AL
        INC SI
    LOOP input_digits
    
    RET
    
TAKE_INPUT ENDP




DISPLAY_NONPRIME PROC
    
    MOV DL, 10                                              ; to print new line
    MOV AH, 02h
    INT 21h
    MOV DL, 13                                              ; carriage return
    MOV AH, 02h
    INT 21h
    
    MOV DX, OFFSET nonprimeStr                              ; to print "Non-prime:" String
    MOV AH, 09h
    INT 21h
                                                            ; DI holds the length of nonprimeOutput Array
    MOV CX, DI
    MOV SI, 0
    
    print_nonprime:
        XOR DX,DX
        XOR AX,AX
                                                            ; print the non prime values one by one
        MOV AH, 02h
        MOV DL, nonprimeOutput[SI]
        ADD DL, 48
        INT 21h
        MOV DL, ' '
        INT 21h
        
        INC SI
    
    LOOP print_nonprime
    
    RET
    
DISPLAY_NONPRIME ENDP




PRIME PROC
    
    XOR AX,AX
    XOR DX,DX
    
    MOV DL, 10                                              ; to print new line
    MOV AH, 02h
    INT 21h
    MOV DL, 13                                              ; carriage return
    MOV AH, 02h
    INT 21h
                                                            ; to print "Prime:" String
    MOV DX, OFFSET primeStr
    MOV AH, 09h
    INT 21h
    
    XOR CX, CX                                              ; Initialize count register
    MOV CL, 5                                               ; to loop through the 5 input values
    MOV DI, 0                                               ; Initialize DI to hold the index of nonprimeOutput array  
    MOV SI, OFFSET inputValues
    
    check_Prime:
        MOV AX,[SI]
        XOR DX,DX
                                                            
        CMP AL, 2                                           ; Check if the given value is 2
        JNE skip3                                           ; If the given value is not prime number 2, then check if it's 3
        
        ADD AL, 48                                          ; get 2's ASCII value to print it
        MOV DL, AL
        XOR AX, AX
        MOV AH, 02h
        INT 21h
        
        MOV DL, ' '
        INT 21h
                                                            
        JMP endPrime                                        ; If it's 2, go to end of PRIME to go check next input value
        
    skip3:    
        CMP AL,3                                            ; Check if the given value is 3
        JNE skip5                                           ; If the given value is not prime number 3, then check if it's 5
        
        ADD AL, 48
        MOV DL, AL
        XOR AX, AX
        MOV AH, 02h
        INT 21h
        
        MOV DL, ' '
        INT 21h
        
        JMP endPrime                                        ; If it's 3, go to end of PRIME to go check next input value
        
    skip5:
        CMP AL, 5                                           ; Check if the given value is 5
        JNE skip7                                           ; If the given value is not prime number 5, then check if it's 7
        
        ADD AL, 48
        MOV DL, AL
        XOR AX, AX
        MOV AH, 02h
        INT 21h
        
        MOV DL, ' '
        INT 21h
        
        JMP endPrime                                        ; If it's 5, go to end of PRIME to go check next input value
        
    skip7:                                                  ; Check if the given value is 7
        CMP AL, 7                                           ; If the given value is not prime number 7, then it's not a prime number
        JNE notPrime
        
        ADD AL, 48
        MOV DL, AL
        XOR AX, AX
        MOV AH, 02h
        INT 21h
        
        MOV DL, ' '
        INT 21h
                                                            ; If it's 7, go to end of PRIME to go check next input value
        JMP endPrime
    
    notPrime:                                               ; If it's a non prime number, call NONPRIME procedure
        CALL NON_PRIME
    
    endPrime:    
        INC SI                                              ; Increment SI to get next input value
        LOOP check_Prime 
    
    RET
   
PRIME ENDP




NON_PRIME PROC
    MOV nonprimeOutput[DI], AL                              ; Store non prime values in the array to print after all the prime numbers have been printed
    INC DI                                                  ; Increment DI as it holds the index of nonprimeOutput Array
    
    RET
    
NON_PRIME ENDP



END MAIN

RET




