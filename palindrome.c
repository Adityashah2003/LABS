#include <stdio.h>
int main(){
    int r,m,n,s = 0;
    printf("Enter a number");
    scanf("%d",&n);
    m=n;
    while (n!=0){
        r = n%10;
        s=s*10 + r;
        n=n/10;
    }
    if (m==s)
    printf("Palindrone numebr");
    else 
    printf("no");
    return 0;
}