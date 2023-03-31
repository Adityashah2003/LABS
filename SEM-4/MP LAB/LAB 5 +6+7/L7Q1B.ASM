DATA SEGMENT
arr dw 8523h ,7777h, 9955h, 1000h, 6515h, 5166h, 0ffffh, 0ab56h, 0abcdh, 1080h
element dw 7777h
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE,DS:DATA
start:
MOV AX,DATA
MOV DS,AX

mov cx,10
lea si,arr
mov bx,00h
mov ax,00h
mov dx,00H

up:
mov ax,[si]
sub ax,element
jz equal
inc si
inc si
loop up

equal:      
mov dx,[si]

MOV AH,4CH
INT 21H
CODE ENDS
END START