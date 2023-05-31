#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a graph structure
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

// Define a clique structure
struct Clique {
    int size;
    vector<int> vertices;
};

// Compute an upper bound on the size of the maximum clique
int upperBound(Graph& G, vector<int>& clique) {
    int ub = clique.size();
    for (int v = 0; v < G.V; v++) {
        if (find(clique.begin(), clique.end(), v) == clique.end()) {
            int count = 0;
            for (auto u : clique) {
                if (G.adj[u][v]) {
                    count++;
                }
            }
            if (count == clique.size()) {
                ub++;
            }
        }
    }
    return ub;
}

// Compute a lower bound on the size of the maximum clique
int lowerBound(Graph& G, vector<int>& clique) {
    int lb = clique.size();
    for (int v = 0; v < G.V; v++) {
        if (find(clique.begin(), clique.end(), v) == clique.end()) {
            bool can_be_added = true;
            for (auto u : clique) {
                if (!G.adj[u][v]) {
                    can_be_added = false;
                    break;
                }
            }
            if (can_be_added) {
                lb++;
            }
        }
    }
    return lb;
}

// Check if a clique is maximal
bool isMaximal(Graph& G, vector<int>& clique) {
    for (int v = 0; v < G.V; v++) {
        if (find(clique.begin(), clique.end(), v) == clique.end()) {
            bool can_be_added = true;
            for (auto u : clique) {
                if (!G.adj[u][v]) {
                    can_be_added = false;
                    break;
                }
            }
            if (can_be_added) {
                return false;
            }
        }
    }
    return true;
}
Clique maxClique(Graph& G) {
    Clique max_clique;
    vector<int> initial_clique;
    int ub = upperBound(G, initial_clique);
    int lb = lowerBound(G, initial_clique);
    vector<vector<int>> candidates;
    candidates.push_back(initial_clique);
    while (!candidates.empty()) {
        vector<int> current_clique = candidates.back();
        candidates.pop_back();
        if (current_clique.size() > max_clique.size) {
            max_clique.size = current_clique.size();
            max_clique.vertices = current_clique;
        }
        if (current_clique.size() + ub <= max_clique.size) {
            continue;
        }
        if (current_clique.size() == G.V) {
            continue;
        }
        int start = 0;
        if (!current_clique.empty()) {
            start = current_clique.back() + 1;
        }
        for (int v = start; v < G.V; v++) {
            if (find(current_clique.begin(), current_clique.end(), v) == current_clique.end()) {
                vector<int> candidate = current_clique;
                candidate.push_back(v);
                int candidate_ub = upperBound(G, candidate);
                if (candidate_ub > max_clique.size) {
                    if (isMaximal(G, candidate)) {
                        max_clique.size = candidate.size();
                        max_clique.vertices = candidate;
                    } else {
                        candidates.push_back(candidate);
                    }
                }
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