#include <bits/stdc++.h>
using namespace std;

bool bfs(int i, int v, vector<int> adj[], int vis[], int par)
{
    queue<pair<int, int>> q;
    vis[i] = 1;
    q.push({i, par});
    while (q.size())
    {
        int num = q.front().first;
        int par = q.front().second;
        q.pop();
        for (auto it : adj[num])
        {
            if (it == par)
            {
                continue;
            }
            else
            {
                if (vis[it] == 1)
                {
                    return true;
                }
                else
                {
                    vis[it] = 1;
                    q.push({it, num});
                }
            }
        }
    }
    return false;
}
bool isCycle(int v, vector<int> adj[])
{
    int vis[v] = {0};
    for (int i = 0; i < v; i++)
    {
        if (vis[i] == 0)
        {
            bool idk = bfs(i, v, adj, vis, -1);
            if (idk)
            {
                cout << i << endl;
                return idk;
            }
        }
    }
    return false;
}
int main()
{
    int n;
    cout << "Enter n ";
    cin >> n;
    vector<int> adj[n];
    int num;
    cout << "Edges ";
    cin >> num;
    while (num--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bool found = isCycle(n, adj);
    if (found)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}
