#include<stdio.h>
int main(){
    int n=0,sum=0,i=0;
    scanf("%d",&n);
    for (i=1;i<n;i++){
        if (n%i==0){
            sum +=i;
        }
    }
    if(sum == n){
        printf("Perfect number");
    }
    else{
        printf("NOT Perfect number");

    }
}