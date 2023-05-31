DATA SEGMENT
Num1 DW 0005h
Num2 DW 0002h
Ans DW ?
DATA ENDS
M1 MACRO
MOV AX, Num1
MOV BX, Num2

FIRST: CMP AX, BX 
JA NEXT 
XCHG AX, BX 

NEXT: 
MOV DX, 0000h 
DIV BX  
CMP DX, 0000h 
JE LAST
MOV AX, DX
JMP FIRST

LAST: MOV Ans, BX 

ENDM

CODE SEGMENT
ASSUME CS: CODE, DS: DATA
START:
MOV AX, DATA
MOV DS, AX 
M1

MOV AH, 4CH
INT 21H
CODE ENDS
END START

The macro first loads Num1 into the AX register and Num2 into the BX register. It then checks if AX is greater than or equal to BX. If it is not, it exchanges the values of AX and BX. This ensures that AX always holds the larger value.

The macro then performs a loop that repeatedly divides AX by BX until the remainder in DX is equal to zero. At each iteration, it checks if DX is equal to zero. If it is, the loop exits and the GCD is stored in the Ans variable. If it is not, the macro sets AX to DX and repeats the loop.