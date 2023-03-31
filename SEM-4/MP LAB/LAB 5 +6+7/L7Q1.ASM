DATA SEGMENT
arr db 01h ,02h, 03h, 04h, 05h, 06h, 07h, 08h, 09h, 10h
element db 03h
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE,DS:DATA
start:
MOV AX,DATA
MOV DS,AX

mov cx,10
lea si,arr
mov bx,0
mov ax,0
mov dx,00H

up:
mov al,[si]
sub al,element
jz equal
inc si
loop up

equal:      
mov dl,[si]

MOV AH,4CH
INT 21H
CODE ENDS
END START