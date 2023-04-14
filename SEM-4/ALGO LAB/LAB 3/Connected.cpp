#include <bits/stdc++.h>
using namespace std;

queue <int> q;
int vertices, edges;
int adj[10][10];
int counter=0;
int flag=0;

void addEdge(int x,int y){
    adj[x][y] = 1;
    adj[y][x]=1;
}
void bfs(int source,int visited[]){
    int z;
    q.push(source);
    while(!q.empty()){
        z = q.front();
        q.pop();
        for(int i=0;i<vertices;i++){
            if(adj[z][i]==1 && visited[i]==0){
                visited[i]=1;
                q.push(i);
            }
        }
    }
    for(int i=0;i<vertices;i++){
        cout<<visited[i];
        if(visited[i]==0)
            flag=1;
    }
    if(flag==0)
        cout<<"Connected"<<endl;
    else
        cout<<"Not Connected";
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
    cout << endl;

    cout << "Enter Source : ";
    int source;
    cin >> source;

    int visited[vertices];
    for (i = 0; i < vertices; i++)
        visited[i] = 0;
    visited[source] = 1;

    //cout << "\nBFS is : ";
    bfs(source,visited);
    cout<<endl;
}
