#include <iostream>
#include <limits.h>
using namespace std;

const int n=9;
int graph[n][n];

void addEdge(int x, int y, int c) {
    graph[x][y] = c;
}
int minDistance(int dist[], bool shortestPathTreeSet[]){
    int min = INT_MAX, min_index;
    for (int i = 0; i < n; i++){
        if (shortestPathTreeSet[i] == false && dist[i] <= min){
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}
void printSolution(int dist[]){
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < n; i++)
        cout << i << " \t\t\t\t" << dist[i] << endl;
}
void dijkstra(int src){
    int dist[n]; 
    bool shortestPathTreeSet[n]; 

    for (int i = 0; i < n; i++){
        dist[i] = INT_MAX;
        shortestPathTreeSet[i] = false;
    }
    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, shortestPathTreeSet);
        //returns the index of the vertex with the minimum distance value from the source 
        //vertex that has not been added to the shortest path tree yet.
        shortestPathTreeSet[u] = true;
        for (int i = 0; i < n; i++){
            if (!shortestPathTreeSet[i] && graph[u][i] && dist[u] != INT_MAX && dist[u] + graph[u][i] < dist[i])
                dist[i] = dist[u] + graph[u][i];
        }
    }
    printSolution(dist);
}
int main(){
    
    addEdge(0, 1, 4);
    addEdge(0, 7, 8);
    addEdge(1, 2, 8);
    addEdge(1, 7, 11);
    addEdge(2, 3, 7);
    addEdge(2, 5, 4);
    addEdge(2, 8, 2);
    addEdge(3, 4, 9);
    addEdge(3, 5, 14);
    addEdge(4, 5, 10);
    addEdge(5, 6, 2);
    addEdge(6, 7, 1);
    addEdge(6, 8, 6);
    addEdge(7, 8, 7);

    int src=0;
    dijkstra(src);

    return 0;
}
