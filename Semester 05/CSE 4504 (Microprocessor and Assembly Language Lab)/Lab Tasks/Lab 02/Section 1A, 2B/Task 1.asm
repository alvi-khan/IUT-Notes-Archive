ORG 0100h
MAIN PROC

    MOV AH, 1           ; get single-key input
    INT 21h
    MOV BL, AL          ; copy to BL, AL gets changed
    JMP pretty_output

pretty_output:
    MOV AH, 2
    MOV DL, 0Dh         ; carriage return
    INT 21h
    MOV DL, 0Ah         ; line feed
    INT 21h
    JMP process_input

process_input:
    CMP BL, 91
    JG to_upper         ; lower-case characters are > 91
    CMP BL, 91
    JL to_lower         ; upper-case characters are < 91

to_upper:
    SUB BL, 32          ; difference between lower-case and upper-case characters is 32
    JMP display_output

to_lower:
    ADD BL, 32
    JMP display_output

display_output:
    MOV DL, BL          ; copy converted character to DL and display
    INT 21h

    MAIN ENDP
END MAIN
RET