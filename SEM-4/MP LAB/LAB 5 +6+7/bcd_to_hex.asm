DATA SEGMENT
BCD DB 63H
HEX DB ?
DATA ENDS
CODE SEGMENT
ASSUME CS: CODE, DS: DATA
START: MOV AX, DATA
MOV DS, AX

MOV AL, BCD ; Copy the BCD number to AL register
MOV BL, 0AH ; Load BL register with ‘A’ – the hex value
MOV CL, 04H ; Copy 04 to CL register to shift the bits

SHR AL, CL ; Shift AL contents by 4 places to swap digits
MUL BL ; Multiply AL contents with BL contents
MOV CL, BCD ; Copy th BCD number to CL register
AND CL, 0FH ; Perform AND operation to mask higher 4 bits
ADD AL, CL ; Add AL contents with CL contents
MOV HEX, AL ; Copy the result to memory location ‘HEX’

MOV AH, 4CH
INT 21H
CODE ENDS
END START