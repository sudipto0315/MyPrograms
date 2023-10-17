#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void addEdge(vector<vector<int>> &adj, int u, int v) {
    adj[u].push_back(v);
}

void dfs(int node, vector<int> &visited, const vector<vector<int>> &adj, stack<int> &stack) {
    visited[node] = 1;
    for (auto it : adj[node]) {
        if (!visited[it]) {
            dfs(it, visited, adj, stack);
        }
    }
    stack.push(node);
}

void kosarajuUtil(int node, vector<int> &visited, const vector<vector<int>> &adjT, vector<int> &component) {
    visited[node] = 1;
    component.push_back(node);
    for (auto it : adjT[node]) {
        if (!visited[it]) {
            kosarajuUtil(it, visited, adjT, component);
        }
    }
}

int kosaraju(int V, vector<vector<int>> &adj) {
    vector<int> visited(V, 0);
    stack<int> stack;

    // Perform the first DFS to find finishing times
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, visited, adj, stack);
        }
    }

    vector<vector<int>> adjT(V);
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
        for (auto it : adj[i]) {
            adjT[it].push_back(i);
        }
    }

    int scc = 0;
    vector<vector<int>> stronglyConnectedComponents;

    while (!stack.empty()) {
        int node = stack.top();
        stack.pop();
        if (!visited[node]) {
            vector<int> component;
            kosarajuUtil(node, visited, adjT, component);
            stronglyConnectedComponents.push_back(component);
            scc++;
        }
    }

    // Printing strongly connected components
    cout << "Strongly Connected Components:" << endl;
    for (const vector<int> &component : stronglyConnectedComponents) {
        for (int node : component) {
            cout << node << " ";
        }
        cout << endl;
    }

    return scc;
}

int main(int argc, char const *argv[]) {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> adj(V);

    int E;
    cout << "Enter the number of edges: ";
    cin >> E;

    cout << "Enter the edges (vertex pairs):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }
    int ans = kosaraju(V, adj);
    cout << "The number of strongly connected components is: " << ans << endl;
    return 0;
}
