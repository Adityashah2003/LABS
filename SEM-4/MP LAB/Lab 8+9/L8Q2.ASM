data segment
    num1 db 0h
    num2 db 0h
    sum db 0h
    first db 'Input First Number (2 digits, HEX):$'
    second db 'Input Second Number (2 digits, HEX):$'
    res db 'Sum is:$'
data ends

code segment
assume cs:code,ds:data
start:
mov ax,data
mov ds,ax

lea dx,first
mov ah,09h
int 21h
call input_hex
mov num1,al

lea dx,second
mov ah,09h
int 21h
call input_hex
mov num2,al

mov al,num1
add al,num2
mov sum,al

lea dx,res
mov ah,09h
int 21h

mov bh,0h
mov bl,num1
call hex_to_ascii
mov ah,02h
mov dl,bh
int 21h
mov dl,bl
int 21h

mov bh,0h
mov bl,num2
call hex_to_ascii
mov ah,02h
mov dl,bh
int 21h
mov dl,bl
int 21h

mov bh,0h
mov bl,sum
call hex_to_ascii
mov ah,02h
mov dl,bh
int 21h
mov dl,bl
int 21h

mov ah,4ch
int 21h

input_hex proc
mov ah,01h
int 21h
cmp al,39h
jae L2
sub al,30h
jmp L3
L2:
sub al,37h
L3:
mov bl,al
mov ah,01h
int 21h
cmp al,39h
jae L4
sub al,30h
jmp L5
L4:
sub al,37h
L5:
add bl,al
ret
input_hex endp

hex_to_ascii proc
push bx
mov bh,0h
mov bl,al
shr al,4
cmp al,9h
jbe L1
add al,7h
L1:
add al,30h
mov bh,al
mov al,bl
and al,0fh
cmp al,9h
jbe L2
add al,7h
L2:
add al,30h
pop bx
ret
hex_to_ascii endp

code ends
end start
