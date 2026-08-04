#include <bits/stdc++.h>
using namespace std;
 
int main() {
 
    int n;
    cin >> n;
 
    int edges;
    cin >> edges;
 
    vector<vector<int>> adj(n + 1);
 
    for (int i = 0; i < edges; i++) {
 
        int u, v;
        cin >> u >> v;
 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> visited(n + 1, 0);
    vector<int> ans;
 
    pq.push(1);
 
    while (!pq.empty()) {
 
        int node = pq.top();
        pq.pop();
 
        if (visited[node])
            continue;
 
        visited[node] = 1;
        ans.push_back(node);
 
        for (auto x : adj[node]) {
 
            if (!visited[x])
                pq.push(x);
        }
    }
 
    for (auto x : ans)
        cout << x << " ";
 
    return 0;
}