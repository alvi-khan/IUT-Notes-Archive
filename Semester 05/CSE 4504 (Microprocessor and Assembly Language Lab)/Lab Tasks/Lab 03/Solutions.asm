ORG 100h

.DATA

input_string DB 'Hello World!$'

.CODE

MAIN PROC
    MOV SI, OFFSET input_string
    MOV DL, 0
    
    count:
        MOV AL, [SI]
        INC SI
        CMP AL, '$'
        JE  endprog
        INC DL
        JMP count
   
   endprog:
        
    
MAIN ENDP
END MAIN
RET