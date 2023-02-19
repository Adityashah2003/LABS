#include <bits/stdc++.h>
using namespace std;

queue <int> q;
int vertices, edges;
int adj[10][10];

void addEdge(int x,int y){
    adj[x][y] = 1;
}

int main(){

    int i, j,m=0,n=0;
    cout << "Enter Number of Vertices : ";
    cin >> vertices;
    cout << "Enter Number of Edges : ";
    cin >> edges;

    for(i=0;i<edges;i++){
        cout<<"Enter the edges";
        cin>>m;
        cin>>n; 
        addEdge(m,n);
    }

    cout << "\nThe Adjacency Matrix is : \n\n";
    for (i = 0; i < vertices; i++){
        for (j = 0; j < vertices; j++){
            cout << adj[j][i] << " ";
        }
        cout << endl;
    }
}

