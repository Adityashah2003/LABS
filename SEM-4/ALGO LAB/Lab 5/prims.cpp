#include <iostream>
#include <climits>
using namespace std;

const int n = 5;
int graph[n][n];
void addEdge(int x, int y, int c) {
    graph[x][y] = c;
    graph[y][x] = c; 
}
int minKey(int key[], bool mstSet[]) {
    int minKey = INT_MAX, minIndex = -1;
    for (int i = 0; i < n; i++) {
        if (!mstSet[i] && key[i] < minKey) {
            minKey = key[i];
            minIndex = i;
        }
    }
    return minIndex;
}
void printMST(int parent[]) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
    }
}
void primMST() {
    /*The key array stores the minimum edge weight required to reach each vertex in the 
    MST, and the mstSet array keeps track of which vertices have already been included 
    in the MST. */
    int parent[n];
    int key[n];
    bool mstSet[n];

    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet);
        //used to keep track of the current vertex that is being considered for MST
        mstSet[u] = true;
        for (int i = 0; i < n; i++) {
            if (graph[u][i] && !mstSet[i] && graph[u][i] < key[i]) {
                parent[i] = u;
                key[i] = graph[u][i];
            }
        }
    }
    printMST(parent);
}
int main() {
    addEdge(0, 1, 2);
    addEdge(0, 3, 6);
    addEdge(1, 2, 3);
    addEdge(1, 3, 8);
    addEdge(1, 4, 5);
    addEdge(2, 4, 7);
    addEdge(3, 4, 9);

    primMST();
    return 0;
}
