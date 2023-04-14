#include <bits/stdc++.h>
using namespace std;

int adj[10][10];
int n;
void addEdge(int x,int y){
    adj[x][y]=1;
}
void topologicalSortUtil(int v, int visited[], stack<int>& s){
    visited[v] = 1;
    for (int i = 0; i < n; ++i){
        if (adj[v][i]==1 && visited[i]==0){
            topologicalSortUtil(i, visited, s);
        }
    }
    s.push(v);
}
void topologicalSort(){
    stack<int> s;
    int visited[n] = { 0 };
    for (int i = 0; i < n; i++){
        if (!visited[i]){
            topologicalSortUtil(i, visited, s);
        }
    }
    while (!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
}
int main(){
    n=6;
    addEdge(5, 2);
    addEdge(5, 0);
    addEdge(4, 0);
    addEdge(4, 1);
    addEdge(2, 3);
    addEdge(3, 1);
    cout << "Topological sorting of the graph: ";
    topologicalSort();
    cout << endl;
    return 0;
}

/*
using lists

#include <iostream>
#include <list>
#include <stack>
using namespace std;

void topologicalSortUtil(int v, bool visited[], stack<int> &Stack, list<int> adj[])
{
    visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if (!visited[*i])
        {
            topologicalSortUtil(*i, visited, Stack, adj);
        }
    }
    Stack.push(v);
}

void topologicalSort(int V, list<int> adj[])
{
    stack<int> Stack;
    bool visited[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            topologicalSortUtil(i, visited, Stack, adj);
        }
    }
    while (!Stack.empty())
    {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

int main()
{
    int V = 6;
    list<int> adj[V];
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);
    cout << "Topological sorting of the graph: ";
    topologicalSort(V, adj);
    cout << endl;
    return 0;
}
*/