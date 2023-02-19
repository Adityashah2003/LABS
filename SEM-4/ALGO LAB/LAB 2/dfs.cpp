#include <bits/stdc++.h>
using namespace std;

stack <int> s;
int vertices, edges;
int adj[10][10];

void addEdge(int x,int y)
{
    adj[x][y] = 1;
    adj[y][x] = 1;
}

///// iterative--does not work ////////

// void dfs(int source,int visited[]){
//     s.push(source);
//     while(!s.empty()){
//         int z = s.top();
//         cout<<z;
//         s.pop();
//         for(int i=0;i<vertices;i++){
//             if(adj[z][i]==1 && visited[i]==0){
//                 visited[i]=1;
//                 s.push(i);
//             }
//         }
//         visited[z]=1;
//         
//         }
//     }
// }

void dfs(int source,int visited[]){
    // if(source%2!=0)
    //     cout<<source;
    cout<<source;
    visited[source]=1;
    for(int i=0;i<=vertices;i++){
        if(adj[source][i]==1 && visited[i]==0){
                dfs(i,visited);
            }
    }
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

    int visited[10];
    for (i = 0; i < 10; i++)
        visited[i] = 0;

    cout << "\nDFS is : ";
    dfs(source,visited);

}