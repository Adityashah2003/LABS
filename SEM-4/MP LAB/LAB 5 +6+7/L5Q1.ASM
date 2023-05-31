DATA SEGMENT
BCD DW 1234H
HEX DW ?
DATA ENDS

CODE SEGMENT
ASSUME CS: CODE, DS: DATA
START: 
MOV AX, DATA
MOV DS, AX

CLC ; clear carry flag
MOV AX, BCD 
MOV BX, 0AH ; set BX to 10
MOV CL, 04H ; set CL to 4

AND AX,000FH ; get the lowest 4 bits of BCD
ADC HEX,AX ; add it to HEX with carry
MOV AX,BCD
AND AX,00F0H ; get the second lowest 4 bits of BCD
SHR AX,CL ; shift right by 4 bits
MUL BX ; multiply by 10
ADD HEX,AX ; add to HEX

MOV BX, 000AH ; set BX to 10
ADD CL, 04H ; add 4 to CL
MOV AX,BCD
AND AX,0F00H ; get the second highest 4 bits of BCD
SHR AX,CL ; shift right by 8 bits
MUL BX ; multiply by 10
ADD HEX,AX ; add to HEX

MOV BX, 000AH ; set BX to 10
ADD CL, 04H ; add 4 to CL
MOV AX,BCD
AND AX,0F000H ; get the highest 4 bits of BCD
SHR AX,CL ; shift right by 12 bits
MUL BX ; multiply by 10
ADD HEX,AX ; add to HEX

MOV AH, 4CH ; exit program
INT 21H
CODE ENDS
END START
