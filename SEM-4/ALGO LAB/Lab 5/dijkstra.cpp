#include<bits/stdc++.h>
using namespace std;

const int INF = INT_MAX; // Define infinity as maximum integer value

vector<pair<int, int>> adj[100001]; // Adjacency list to store graph
int dist[100001]; // Array to store shortest distances

void dijkstra(int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap to store vertices with their weights
    pq.push(make_pair(0, src)); // Add source vertex to min-heap with 0 distance
    dist[src] = 0; // Distance of source vertex from itself is 0

    while (!pq.empty()) {
        int u = pq.top().second; // Extract vertex with minimum distance
        pq.pop();

        for (auto i = adj[u].begin(); i != adj[u].end(); i++) {
            int v = i->first; // Vertex number
            int weight = i->second; // Weight of edge

            if (dist[v] > dist[u] + weight) { // If distance of vertex v can be reduced
                dist[v] = dist[u] + weight; // Update distance of vertex v
                pq.push(make_pair(dist[v], v)); // Add vertex v to min-heap with updated distance
            }
        }
    }
}

int main() {
    int n, m; // n = number of vertices, m = number of edges
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v, w; // u = source vertex, v = destination vertex, w = weight of edge
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w)); // Add edge to adjacency list
    }

    int src; // Source vertex for finding shortest path
    cin >> src;

    memset(dist, INF, sizeof(dist)); // Initialize all distances to infinity
    dijkstra(src); // Call Dijkstra's algorithm

    // Print shortest distance of each vertex from the source vertex
    for (int i = 1; i <= n; i++) {
        if (dist[i] != INF)
            cout << "Shortest distance from vertex " << src << " to vertex " << i << " is " << dist[i] << endl;
        else
            cout << "Vertex " << i << " is not reachable from vertex " << src << endl;
    }

    return 0;
}

