#include <bits/stdc++.h>
using namespace std;

stack <int> s;
int vertices, edges;
int adj[10][10];
int trans[10][10];

void addEdge(int x,int y){
    adj[x][y] = 1;
    trans[y][x]=1;
}

void dfs(int source,int visited[]){
    visited[source]=1;
    for(int i=0;i<vertices;i++){
        if(adj[source][i]==1 && visited[i]==0)
            dfs(i,visited);
    }
    s.push(source);
}
void dfs3(int source,int visited[]){
    visited[source]=1;
    for(int i=0;i<vertices;i++){
        if(trans[source][i]==1 && visited[i]==0){
                dfs3(i,visited);
        }
    }
}
void khr(){
    int scc=0;
    int visited[vertices]={0};

    for(int i=0;i<vertices;i++){
        if(visited[i]==0)
            dfs(i,visited);
    }
    for(int i=0;i<vertices;i++)
        visited[i]=0;

    while(!s.empty()){
        int node = s.top();
        s.pop();
        if(visited[node]==0){
            scc++;
            dfs3(node,visited);
        }
    }
    cout<<scc;
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
    cout << "\nThe Trans Matrix is : \n\n";
    for (i = 0; i < vertices; i++){
        for (j = 0; j < vertices; j++){
            cout << trans[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    khr();
}
