#include <bits/stdc++.h>
using namespace std;
 
int main() {
 
    int cities, ps, range;
    cin >> cities >> ps >> range;
 
    vector<vector<pair<int,int>>> adj(cities + 1);
 
    queue<pair<int,int>> q;
 
    vector<int> visited(cities + 1, 0);
    vector<int> parent(cities + 1, -1);
 
    for (int i = 0; i < ps; i++) {
 
        int x;
        cin >> x;
 
        if (!visited[x]) {
 
            visited[x] = 1;
            q.push({x, 0});
        }
    }
 
    for (int i = 1; i <= cities - 1; i++) {
 
        int u, v;
        cin >> u >> v;
 
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
 
    unordered_set<int> removed;
 
    while (!q.empty()) {
 
        auto [node, dist] = q.front();
        q.pop();
 
        if (dist > range)
            continue;
 
        for (auto [next, edge] : adj[node]) {
 
            if (!visited[next]) {
 
                visited[next] = 1;
                parent[next] = node;
                q.push({next, dist + 1});
 
            }
            else {
 
                if (parent[node] == next)
                    continue;
 
                removed.insert(edge);
            }
        }
    }
 
    cout << removed.size() << "
";
 
    for (auto x : removed)
        cout << x << " ";
 
    return 0;
}