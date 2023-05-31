DATA SEGMENT
    HEX DB 2Ah
    DECIMAL DB ?
DATA ENDS

CODE SEGMENT
    ASSUME CS: CODE, DS: DATA

START:
    MOV AX, DATA
    MOV DS, AX

    MOV AL, HEX ; Copy the HEX number to AL register
    AND AL, 0FH ; Mask the upper bits
    MOV BL, 10 ; Set BL to 10
    MUL BL ; Multiply the lower bits by 10
    MOV BH, 0 ; Clear BH
    MOV BL, 0 ; Clear BL
    ADD BL, AL ; Add the lower bits to BL
    MOV AL, HEX ; Copy the HEX number to AL register
    SHR AL, 4 ; Shift right by 4 bits to get the upper bits
    AND AL, 0FH ; Mask the upper bits
    MUL BL ; Multiply the upper bits by 10
    ADD AL, BL ; Add the result to BL
    MOV DECIMAL, AL ; Store the result in DECIMAL

    MOV AH, 4CH
    INT 21H

CODE ENDS
END START
