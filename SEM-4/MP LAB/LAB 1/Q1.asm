DATA SEGMENT
ARRAY1 DB 10H,20H,30H,40H,50H,60H,70H,80H,90H,95H
ARRAY2 DB 5 DUP(0)
COUNT DB 10H
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA

START:
MOV AX,DATA;
MOV DS,AX;

LEA SI,ARRAY1;
ADD SI,9
LEA DI,ARRAY2;
ADD DI,4;

MOV CH,00H;
MOV CL,COUNT;

NEXT:
MOV AL,[SI+10];
MOV [DI],AL;
DEC SI;
DEC DI;
LOOP NEXT;

MOV AH,4CH;
INT 21H;
CODE ENDS
END START