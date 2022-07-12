#include<stdio.h>
int main(){
    int n=0,k=0,i=0,j=0;
    printf("Enter n");
    scanf("%d",&n);
    printf("Enter n");
    scanf("%d",&k);

    for(i=1;i<=n;i++){
        for(j=1;j<=k;j++){
            printf("%d",i*j);
            printf("\t");
        }
        printf("\n");
    }
    return 0;
}