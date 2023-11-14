#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<int> &vis, int tin[], int low[],
         vector<int> &mark, vector<vector<int>> &adj, int &timer) {
    vis[node] = 1;
    tin[node] = low[node] = timer;
    timer++;
    int child = 0;
    for (auto it : adj[node]) {
        if (it == parent)
            continue;
        if (!vis[it]) {
            dfs(it, node, vis, tin, low, mark, adj, timer);
            low[node] = min(low[node], low[it]);
            if (low[it] >= tin[node] && parent != -1) {
                mark[node] = 1;
            }
            child++;
        } else {
            low[node] = min(low[node], tin[it]);
        }
    }
    if (child > 1 && parent == -1) {
        mark[node] = 1;
    }
}

vector<int> articulationPoints(int n, vector<vector<int>> &adj) {
    vector<int> vis(n, 0);
    int tin[n];
    int low[n];
    vector<int> mark(n, 0);
    int timer = 1;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, -1, vis, tin, low, mark, adj, timer);
        }
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (mark[i] == 1) {
            ans.push_back(i);
        }
    }
    if (ans.size() == 0)
        return {-1};
    return ans;
}

int main() {
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<int>> adj(n);
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> nodes = articulationPoints(n, adj);
    for (auto node : nodes) {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}
