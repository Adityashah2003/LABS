DATA SEGMENT
A DB 11H,22H,33H,44H,55H
B DB 5 DUP(0)
COUNT DB 05H
DATA ENDS

CODE SEGMENT
	ASSUME CS: CODE, DS: DATA
START:
        MOV AX,DATA
        MOV DS,AX

        LEA SI,A
        LEA DI,B
        MOV CX,05

NEXT:
        MOV AL,[SI]
        MOV [DI],AL
        INC SI
        INC DI
        LOOP NEXT
        MOV AH,4CH
        INT 21H
CODE ENDS
END START
