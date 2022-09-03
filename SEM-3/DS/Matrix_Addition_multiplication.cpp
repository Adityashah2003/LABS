/* LAB-1:
    problem:1)Matrix Addition and Multiplication. */

#include<iostream>
using namespace std;

int matrix_addition(int a[50][50], int m, int n, int b[50][50], int p, int q){
    int i, j;
    int sum[100][100];

    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            sum[i][j]=a[i][j]+b[i][j];
        }
    }

    cout<<"Sum of the matrices:"<<endl;
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            cout<<sum[i][j]<<"\t";
        }
        cout<<endl;
    }

}

int matrix_product(int a[50][50], int m, int n, int b[50][50], int p, int q){
    int i, j, k;
    int prod[100][100];

    for(i=0; i<m; i++){
        for(j=0; j<q; j++){
            for(k=0; k<n; k++){
            prod[i][j]+=a[i][k]*b[k][j];
            }
        }
    }

    cout<<"Product of the matrices:"<<endl;
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            cout<<prod[i][j]<<"\t";
        }
        cout<<endl;
    }

}


int main(){
    int r1, m, n, a[50][50];
    int p, q, b[50][50];
    int i, j;

    cout<<"Enter the size of the first 2-D array:";
    cin>>m>>n;

    cout<<"Enter the elements of the "<<m<<"*"<<n<<" array:";
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            cin>>a[i][j];
        }
    }

    cout<<"Enter the size of the second 2-D array:";
    cin>>p>>q;

    cout<<"Enter the elements of the "<<p<<"*"<<q<<" array:";
    for(i=0; i<p; i++){
        for(j=0; j<q; j++){
            cin>>b[i][j];
        }
    }

    if(m==p && n==q){
        matrix_addition(a, m, n, b, p, q);
    }
    if(n==p){
        matrix_product(a, m, n, b, p, q);
    }

    return 0;
    }

