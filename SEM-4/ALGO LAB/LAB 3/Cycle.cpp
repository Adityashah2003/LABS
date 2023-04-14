#include <bits/stdc++.h>
using namespace std;

queue<pair<int, int>> q;
int vertices, edges;
int adj[10][10];

void addEdge(int x,int y){
    adj[x][y] = 1;
    adj[y][x]=1;
}
bool bfs(int source,int visited[],int par){
    visited[source]=1;
    q.push({source,par});
    while(!q.empty()){
        int num = q.front().first;
        par = q.front().second;
        q.pop();
        // for (auto i : adj[num]){
        for(int i=0;i<vertices;i++){
            if(i ==par)
                continue;
            else{
                if(adj[num][i]==1 && visited[i]==1)
                    return true;
                else{
                    visited[i]=1;
                    q.push({i,num});
                }
            }
        }
    }
    return false;
}
bool cycle(){
    int visited[vertices] = {0};
    for(int i=0;i<vertices;i++){
        if(visited[i]==0){
            bool lean = bfs(i,visited,-1); 
            if(lean){
                cout<<i;
                return lean;
            }
        }
    }
    return false;
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

    if(cycle()==true)
        cout<<"cyclic";
    else    
        cout<<"not";
    cout<<endl;
}
