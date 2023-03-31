DATA SEGMENT
arr db 23h ,02h, 03h, 04h, 01h, 06h, 07h, 08h, 09h, 05h
element db 00h
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE,DS:DATA
start:
MOV AX,DATA
MOV DS,AX

mov cx,0AH
lea si,arr
mov bx,00H
mov ax,00H
mov dx,00H

mov al,[si]
mov element,al

up:
mov al,[si]
CMP al,element 
JC DOWN
JMP EX

DOWN:
MOV element ,AL

EX:
inc si
loop up 

MOV AH,4CH
INT 21H
CODE ENDS
END START