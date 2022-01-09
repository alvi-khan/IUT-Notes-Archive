
ORG 0100H

.DATA 

input DB 'Input: $' 
outputp DB 'Prime Digits Descending: $'
list DB 8 dup(0)                              ;array of numbers


.CODE    

MAIN PROC    
    
    
    mov dx,OFFSET input 
    mov ah,09h 
    int 21h
    mov cx,8 
    mov si,0 
    mov ah,01h
    
    
loop1: int 21h            ;taking input in the array
    sub al,48
    mov list[si],al
    inc si
    loop loop1            ;done taking input
    
    
    mov ah,2              ;for new line
    mov dl,0Ah
    int 21h
    mov dl,0Dh
    int 21h 
    
    mov cx,8
    dec cx  
    
    continue:
    mov bx,cx
    mov si,0  
                                   ;before finding prime, sorting in descending order
    compare:
    mov al,list[si]
    mov dl,list[si+1]
    cmp al,dl
    jg unchanged
    mov list[si],dl
    mov list[si+1],al 
    
    unchanged:   
    inc si
    dec bx
    jnz compare
    loop continue
    mov bx,offset list
    mov ah,09h
    lea dx,outputp 
    int 21h 
    mov cl,8                         ;done with sorting in descending order
    mov si,0  
                                     
loop2: xor ax,ax                     ;calling the func prime
    call prime                       ;after output prime taking the next index of array
    inc si
    loop loop2 
    
                                     ;ending the program
    MOV AH,4Ch
    MOV AL,00h
    INT 21h 
    
MAIN ENDP 
                                      ;procedure prime number 
prime proc       
    
    cmp list[si],0
    jz not_prime  
    
    cmp list[si],1
    jz not_prime   
    
    cmp list[si],2
    jz yes_prime      
    
    cmp list[si],3
    jz yes_prime      
    
    cmp list[si],4
    jz not_prime  
    
    cmp list[si],5
    jz yes_prime       
    
    cmp list[si],6
    jz not_prime   
    
    cmp list[si],7
    jz yes_prime        
    
    cmp list[si],8
    jz not_prime    
    
    cmp list[si],9
    jz not_prime    


                                       ;doesnt match so we return 
not_prime: ret     
                                       
yes_prime: mov ah,02h                  ;if matches, we output the prime number
       mov dl,list[si]
       add dl,48
       int 21h 
       ret


prime ENDP                            ;end of procedure

END MAIN