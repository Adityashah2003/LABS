#include <iostream>
#include <vector>
using namespace std;

struct Graph {
    int V;
    vector<vector<int>> adj;
    Graph(int V) {
        this->V = V;
        adj.resize(V, vector<int>(V, 0));
    }
    void addEdge(int u, int v) {
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
};
struct Clique {
    int size;
    vector<int> vertices;
};
Clique maxClique(Graph& G) {
    Clique max_clique;
    for (int v = 0; v < G.V; v++) {
        vector<int> candidate{v};
        for (int u = v + 1; u < G.V; u++) {
            if (G.adj[u][v]) {
                candidate.push_back(u);
            }
        }
        for (int w : candidate) {
            vector<int> new_candidate;
            for (int x : candidate) {
                if (G.adj[x][w]) {
                    new_candidate.push_back(x);
                }
            }
            if (new_candidate.size() > max_clique.size) {
                max_clique.size = new_candidate.size();
                max_clique.vertices = new_candidate;
            }
        }
    }
    return max_clique;
}

int main() {
    Graph G(5);
    G.addEdge(0, 1);
    G.addEdge(0, 2);
    G.addEdge(1, 2);
    G.addEdge(1, 3);
    G.addEdge(2, 3);
    G.addEdge(3, 4);
    Clique max_clique = maxClique(G);
    cout << "Maximum clique size: " << max_clique.size << endl;
    cout << "Maximum clique vertices: ";
    for (auto v : max_clique.vertices) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}
