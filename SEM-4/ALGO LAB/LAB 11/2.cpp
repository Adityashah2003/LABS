#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define INF 1e9
using namespace std;
const int MAXN = 1000;

int n, m;
int graph[MAXN][MAXN];
int parent[MAXN];
int key[MAXN];
bool visited[MAXN];

void primMST(int src){
    for (int i = 0; i < n; i++){
        key[i] = INF;
        visited[i] = false;
    }

    key[src] = 0;
    parent[src] = -1;

    for (int i = 0; i < n - 1; i++){
        int u, min_key = INF;
        for (int v = 0; v < n; v++){
            if (!visited[v] && key[v] < min_key){
                u = v;
                min_key = key[v];
            }
        }
        visited[u] = true;
        for (int v = 0; v < n; v++){
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]){
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
}
int tsp(int src){
    primMST(src);
    int min_cost = 0;
    for (int i = 0; i < n; i++)
        if (parent[i] != -1)
            min_cost += graph[i][parent[i]];

    vector<int> tour;
    tour.push_back(src);
    int cur = src;
    while (tour.size() < n){
        int next = -1;
        for (int i = 0; i < n; i++){
            if (i == cur || find(tour.begin(), tour.end(), i) != tour.end())
                continue;

            if (next == -1 || graph[cur][i] < graph[cur][next])
                next = i;
        }
        tour.push_back(next);
        cur = next;
    }
    tour.push_back(src);
    cout << "Travelling Salesperson Tour: ";
    for (int i = 0; i < tour.size(); i++)
        cout << tour[i] << " ";
    cout << endl;

    return min_cost;
}

int main(){
    memset(graph, 0, sizeof(graph));

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = graph[v][u] = w;
    }

    int src;
    cout << "Enter the source node: ";
    cin >> src;

    int min_cost = tsp(src);

    cout << "Minimum Cost: " << min_cost << endl;

    return 0;
}
