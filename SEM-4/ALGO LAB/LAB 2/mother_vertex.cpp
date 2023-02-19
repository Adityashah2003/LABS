#include <bits/stdc++.h>
using namespace std;

stack <int> s;
int vertices, edges;
int adj[10][10];

void addEdge(int x,int y){
    adj[x][y] = 1;
}

void dfs(int source,int visited[]){
    cout<<source;
    visited[source]=1;
    for(int i=0;i<=vertices;i++){
        if(adj[source][i]==1 && visited[i]==0){
                dfs(i,visited);
        }
    }
}

void mother_vertex(){
    int visited[20];
    int v=0;
    for(int i=0;i<=vertices;i++){
        if(visited[i]==0){
            dfs(i,visited);
            v=i;
        }
    }
    for(int i=0;i<=vertices;i++){
        visited[i]=0;
    }
    dfs(v,visited);
    for(int i=0;i<=vertices;i++){
        if(visited[i]==0)
            break;
    }
    cout<<"Mother vertex is: "<<v<<endl;
}

int main(){

    int i, j,m=0,n=0;
    cout << "Enter Number of Vertices : ";
    cin >> vertices;
    cout << "Enter Number of Edges : ";
    cin >> edges;

    for(i=0;i<edges;i++){
        cout<<"Enter the adjacency matrix";
        cin>>m;
        cin>>n; 
        addEdge(m,n);
    }
    cout << "\nThe Adjacency Matrix is : \n\n";
    for (i = 0; i < vertices; i++){
        for (j = 0; j < vertices; j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    mother_vertex();
}