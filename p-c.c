#include<stdio.h>
int main (){
    int num=0,p=0,c=0,i=0,count=0;
    do{
        scanf("%d",&num);
        for(int i=1 ; i < num/2 ; i++) {
        if(num%i == 0){
            p++;
            count = 1;
            break;
            }
        }
        if(count == 1) {
          c++;
        }  
    }while(num != -1);
    printf("%d\n Prime numbers:",p);
    printf("%d\n Composite numbers:",c);
    return 0;
}