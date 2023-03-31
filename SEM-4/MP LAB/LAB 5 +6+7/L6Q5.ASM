data segment
num db 5
res db ?
data ends

code segment
assume cs: code, ds: data

fact proc
push ax
cmp al, 01
jz down
sub al, 01h
call fact
down:
pop bx
mul bl
mov res, ax
ret
fact endp

start:
mov ax, data
mov ds, ax
mov ah, 0h
mov al, num
call fact
mov ah, 4ch
int 21h
code ends
end start
