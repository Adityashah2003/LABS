#include <bits/stdc++.h>
using namespace std;

queue <int> q;
int vertices, edges;
int adj[10][10];
int counter=0;

void addEdge(int x,int y){
    adj[x][y] = 1;
    adj[y][x] = 1;
    counter+=2;
}
void bfs(int source,int visited[]){
    int z;
    q.push(source);
    counter+=2;
    while(!q.empty()){
        z = q.front();
        counter+=2;
        // if(z%2==0)
        //     cout<<z;
        cout<<z;
        q.pop();
        counter+=2;
        for(int i=0;i<vertices;i++){
            counter++;
            if(adj[z][i]==1 && visited[i]==0){
                visited[i]=1;
                q.push(i);
                counter+=3;
            }
        }
        counter++;
    }
    counter++;
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
        for (j = 0; j < vertices; j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    cout << "Enter Source : ";
    int source;
    cin >> source;

    int visited[10];
    for (i = 0; i < 10; i++)
        visited[i] = 0;
    visited[source] = 1;

    cout << "\nBFS is : ";
    bfs(source,visited);
    cout<<counter;
}