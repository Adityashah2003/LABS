data segment
input db 'Enter a two-digit hexadecimal number: $'
output db 'The decimal equivalent is: $'
hex db ? 
decimal db ?
data ends

code segment
assume cs:code,ds:data
mov ax,data
mov ds,ax

mov ah, 09
mov dx, offset input
int 21h

lea si,hex
lea di,decimal

mov ah, 01h 
int 21h 
mov [si], al 
mov ah, 01h 
int 21h 
mov [si+1], al 

mov bl, [si] 
sub bl, 30h 
mov bh, 0 
shl bl, 4 ; Shift first digit to high nibble
mov cl, 10 ; Set CL to 10
mul cl ; Multiply BH by 10
add bh, al ; Add AL (numeric digit) to BH
mov bl, [si+1] ; Move second digit to BL register
sub bl, 30h ; Convert ASCII digit to numeric digit
add bh, bl ; Add BL (numeric digit) to BH
mov [di], bh ; Store decimal value in memory

; Display decimal value
mov ah, 09h ; BIOS function to print string
mov dx, output
int 21h ; Display output string
mov dl, [di] ; Move decimal value to DL register
add dl, 30h ; Convert decimal digit to ASCII
mov ah, 02h ; BIOS function to print character
int 21h ; Print tens digit
mov dl, [di+1] ; Move decimal value to DL register
add dl, 30h ; Convert decimal digit to ASCII
mov ah, 02h ; BIOS function to print character
int 21h ; Print ones digit
mov dl, '$' ; Print end-of-line character
mov ah, 02h 
int 21h

mov ah,4ch
int 21h

code ends
end start

