MOV AX, 04789h
MOV BX, 0AB9Fh
MOV CX, 0C25Ah
MOV DX, 0B21Ch

ADD AX, BX
SUB CX, DX

MOV BX, AX
MOV DX, CX

AND AX, CX