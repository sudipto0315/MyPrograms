#include <iostream>
#include <vector>
using namespace std;

// Function to add an edge to the directed graph
void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
}

// Function to print the directed graph
void printGraph(const vector<vector<int>>& adj) {
    int V = adj.size();
    for (int v = 0; v < V; ++v) {
        cout << "Adjacency list of vertex " << v << ": ";
        for (int neighbor : adj[v]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[]) {
    int V, E;
    
    cout << "Enter the number of vertices: ";
    cin >> V;
    
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);

    cout << "Enter the edges (from vertex to vertex):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }

    cout << "Graph representation:" << endl;
    printGraph(adj);

    return 0;
}
