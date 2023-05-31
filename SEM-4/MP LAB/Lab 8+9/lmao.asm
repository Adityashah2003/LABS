data segment
    input db 'Enter two-digit hexadecimal numbers: $'
    arr db 4 dup(0)
data ends

code segment
    assume cs:code, ds:data

start:
    mov ax, data
    mov ds, ax
    lea si, arr

    mov ah, 09h
    mov dx, offset input
    int 21h

inp macro
    mov dl, 03h
input_loop:
    mov ah, 01h
    int 21h
    sub al, 30h
    cmp al, 9
    jbe skip_conversion
    sub al, 7h    ; Adjust for A-F hexadecimal digits

skip_conversion:
    mov bl, al

    mov ah, 01h
    int 21h
    sub al, 30h
    cmp al, 9
    jbe skip_conversion2
    sub al, 7h    ; Adjust for A-F hexadecimal digits

skip_conversion2:
    mov cl,al
	mov al,10h
	mul bl
	add al,cl
 	mov [si], al
    inc si
    dec dl
    JNZ input_loop
endm
disp macro
lea si,  arr
mov bl, 03h
display_loop:
    mov al, [si]
    push ax        
    mov ah,0h    
	 mov cl,4
	 shr al,cl    
	 cmp al, 9
    jbe skip_adjustment
    add al, 7h      

skip_adjustment:
    add al, 30h    

    mov dl, al
    mov ah, 02h
    int 21h

    pop ax          
    and al,0Fh
    cmp al, 9
    jbe skip_adjustment2
    add al, 7h      

skip_adjustment2:
    add al, 30h     
    mov dl, al
    mov ah, 02h
    int 21h

    add si, 1       
    dec bl
    JNZ display_loop
endm

MOV BX, 3
DEC BX
inp
lea si,arr
OUTLOOP:
MOV CX,BX
;MOV SI,0

	INLOOP:
	MOV AL,[SI]
	CMP AL,[SI+1]
	JB GO; JGE for signed
	XCHG AL,[SI+1]
	MOV [SI],AL
	GO:
	LOOP INLOOP
	DEC BX

JNZ OUTLOOP
disp
mov ah, 4Ch
int 21h
code ends
end start
