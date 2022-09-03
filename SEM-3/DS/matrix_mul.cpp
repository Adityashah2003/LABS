#include<iostream>
using namespace std;

int main(){
    int a[50][50], b[50][50], c[50][50];
    int m, n, p, q;
    int i, j;

    cout<<"Enter the size of the first matrix:";
    cin>>m>>n;
    cout<<"Enter the elements of the "<<m<<" * "<<n<<" matrix:"<<endl;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cin>>a[i][j];
        }
    }

    cout<<"Enter the size of the second matrix:";
    cin>>p>>q;
    cout<<"Enter the elements of the "<<p<<" * "<<q<<" matrix:"<<endl;
    for(i=0;i<p;i++){
        for(j=0;j<q;j++){
            cin>>b[i][j];
        }
    }

    cout<<"C(i, j) = max ( A(i, j) , B(i, j))="<<endl;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            c[i][j]=max(a[i][j], b[i][j]);
        }
    }

    cout<<"Matrix c is:"<<endl;
    for(i=0;i<p;i++){
        for(j=0;j<q;j++){
            cout<<c[i][j]<<"\t";
        }
        cout<<"\n";
    }
    return 0;
}

