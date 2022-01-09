ORG 0100h

.DATA
values DB ?, ?, ?, ?, ?
average DB ?
largest DB 0
smallest DB 9
averageText DB 'AVERAGE=$'
largestText DB ' LARGEST=$'
smallestText DB ' SMALLEST=$'

.CODE
MAIN PROC
    CALL getInput
    CALL findAvg
    CALL findLargest
    CALL findSmallest
    CALL printOutput
    RET
MAIN ENDP

getInput PROC
    MOV CL, 5               ; taking 5 inputs
    MOV SI, 0               ; array index
    
    inputLoop:              ; loop and store digits in array
        MOV AH, 01h         ; single character input
        INT 21h
        SUB AL, 48          ; ASCII -> decimal
        MOV values[SI], AL
        INC SI              ; increment index
    LOOP inputLoop
    
    RET
getInput ENDP

findAvg PROC
    MOV CL, 5
    MOV BL, CL              ; to be used for division
    MOV SI, OFFSET values   ; start of array
    MOV AL, 0               ; clear AL
    
    avgLoop:                ; sum up array values
        ADD AL, [SI]
        INC SI
    LOOP avgLoop
    
    MOV AH, 0               ; clear AH
    DIV BL                  ; AL stores average
    MOV average, AL
    RET
findAVG ENDP

findLargest PROC
    MOV CL, 5
    MOV SI, OFFSET values
    
    largestLoop:
        MOV AL, [SI]        ; move array value to AL
        INC SI
        CMP AL, largest     ; check if larger
        JL skipSetMax       ; if not, skip next line
        MOV largest, AL
        skipSetMax:
    LOOP largestLoop
    
    RET
findLargest ENDP

findSmallest PROC
    MOV CL, 5
    MOV SI, OFFSET values
    
    smallestLoop:
        MOV AL, [SI]        ; move array value to AL
        INC SI
        CMP AL, smallest    ; check if smaller
        JG skipSetMin       ; if not, skip next line
        MOV smallest, AL
        skipSetMin:
    LOOP smallestLoop
    
    RET
findSmallest ENDP

printOutput PROC
    MOV AH, 02h                 ; print single character
    MOV DL, 0Dh                 ; print carriage return
    INT 21h
    MOV DL, 0Ah                 ; print new line
    INT 21h
    
    MOV AH, 09h                 ; print string
    MOV DX, OFFSET averageText  ; print average text
    INT 21h
    MOV AH, 02h                 ; print single character
    MOV DL, average             ; print average value
    ADD DL, 48                  ; decimal -> ASCII
    INT 21h
    
    MOV AH, 09h
    MOV DX, OFFSET largestText  ; print largest text
    INT 21h
    MOV AH, 02h
    MOV DL, largest             ; print largest value
    ADD DL, 48
    INT 21h
    
    MOV AH, 09h
    MOV DX, OFFSET smallestText ; print smallest text
    INT 21h
    MOV AH, 02h
    MOV DL, smallest            ; print smallest value
    ADD DL, 48
    INT 21h
    RET
printOutput ENDP

END MAIN