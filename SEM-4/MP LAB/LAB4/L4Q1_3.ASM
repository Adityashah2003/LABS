DATA SEGMENT
A DB 90H
B DB 0DEH
RES DW 00H
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE,DS:DATA

START:
MOV AX,DATA
MOV DS,AX
MOV AH,00H
MOV BH,00H

MOV AL,A
MOV BL,B
IMUL BL

MOV RES,AX 
MOV AH,4CH
INT 21H
CODE ENDS
END START
















