#include <bits/stdc++.h>
using namespace std;

queue <int> q;
int vertices, edges;
int adj[10][10];
int counter=0;
int flag=0;

void addEdge(int x,int y)
{
    adj[x][y] = 1;
}
void bfs(int source,int visited[],int destination){
    int z;
    q.push(source);
    while(!q.empty()){
        z = q.front();
        q.pop();
        for(int i=0;i<vertices;i++){
            if(adj[z][i]==1 && visited[i]==0){
                visited[i]=1;
                q.push(i);
                //cout<<z;
                if(i==destination){
                    flag=1;
                    break;
                }
            }
        }
    }
    if(flag==1)
        cout<<q.front()<<" ";
        cout<<"Found"<<endl;
    else
        cout<<"Not found";
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

    cout << "Enter Dest : ";
    int destination;
    cin >> destination;

    int visited[10];
    for (i = 0; i < 10; i++)
        visited[i] = 0;
    visited[source] = 1;

    cout << "\nBFS is : ";
    bfs(source,visited,destination);
}
