#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii; // {weight, vertex}

void dijkstra(vector<vector<pii>>& graph, int source) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq; // {weight, vertex} min heap

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto& [v, w] : graph[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest distances from source vertex " << source << ":\n";
    for (int i = 0; i < n; i++) {
        cout << i << ": " << dist[i] << "\n";
    }
}

int main(int argc, char const *argv[]) {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<pii>> graph(n);
    cout << "Enter edges and weights:\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    dijkstra(graph, source);

    return 0;
}
