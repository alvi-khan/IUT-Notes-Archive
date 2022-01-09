RG 0100h

.DATA
A DB 5 DUP(0)
.CODE

MAIN PROC
    LEA SI, A
    MOV CL, 5
    XOR DX, DX

LOOP1:  MOV AH, 01h
        INT 21h 
        SUB AL,48 
        ADD DL, AL 
        LOOP LOOP1  
         

   CMP DL, 0fH
   JG twoDigit
   ADD DL, 55
   JMP endProg

twoDigit:
   MOV BL, 0
   
   decrement:
   INC BL
   SUB DL, 16
   CMP DL, 0fH
   JG decrement
   
   MOV CL, DL
   MOV DL, BL
   ADD DL, 48
   MOV AH, 02h  
   INT 21h
   
   MOV DL, CL
   
   CMP DL, 9
   JG big
   ADD DL, 48
   JMP endProg
   big:
   ADD DL, 55
   
   
   
        
endProg:    
   MOV AH, 02h  
   INT 21h
 
    MAIN ENDP
END MAIN
RET