#include<bits/stdc++.h>
using namespace std;
vector<int> bfs(unordered_map<int, vector<int>>& m,int n, int start) {
    vector<int> ans;
    queue<int> q;
    vector<int> visited(n, 0);
    visited[start]  = 1;
    q.push(start);
    while(q.size()!=0) {
        int temp = q.front();
        ans.push_back(temp);
        q.pop();
        for(auto it: m[temp]) {
            if(visited[it]==0) {
                visited[it]=1;
                q.push(it);
            }
        }
    }
    return ans;
}
int main() {
    unordered_map<int, vector<int>> m;
    int n;
    cout<<"Enter n ";
    cin>>n;
    for(int i=0; i<n; i++) {
        vector<int> v;
        m[i] = v;
    }
    int num;
    cout<<"Edges ";
    cin>>num;
    while(num--) {
        int a,b;
        cin>>a>>b;
        m[a].push_back(b);
        m[b].push_back(a);
    }
    vector<int> idk = bfs(m, n, 0);
    bool found = idk.size()==n;
    if(found)
        cout<<"Yes";
    else 
        cout<<"No";
    return 0;
}