#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    set<int> vertex_cover;
    vector<vector<int>> adj_list(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    for (int u = 0; u < n; u++) {
        for (int v : adj_list[u]) {
            if (vertex_cover.find(u) == vertex_cover.end() && vertex_cover.find(v) == vertex_cover.end()) {
                vertex_cover.insert(u);
                vertex_cover.insert(v);
            }
        }
    }
    cout << "Minimum size vertex cover: " << vertex_cover.size() << endl;
    cout << "Vertices in the vertex cover: ";
    for (int v : vertex_cover) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
