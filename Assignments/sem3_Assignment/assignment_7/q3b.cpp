#include <iostream>
#include <vector>
using namespace std;

// Function to perform Depth-First Search (DFS)
void DFS(const vector<vector<int>> &adjMatrix, vector<bool> &visited, int v, int V) {
    visited[v] = true;
    for (int u = 0; u < V; ++u) {
        if (adjMatrix[v][u] && !visited[u]) {
            DFS(adjMatrix, visited, u, V);
        }
    }
}

// Function to check if the graph is connected
bool isConnected(const vector<vector<int>> &adjMatrix) {
    int V = adjMatrix.size();
    vector<bool> visited(V, false);
    
    // Start DFS from the first vertex
    DFS(adjMatrix, visited, 0, V);
    
    // Check if all vertices are visited
    for (int v = 0; v < V; ++v) {
        if (!visited[v]) {
            return false; // Graph is not connected
        }
    }
    
    return true; // Graph is connected
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> adjMatrix(V, vector<int>(V, 0));

    int E;
    cout << "Enter the number of edges: ";
    cin >> E;

    cout << "Enter the edges (vertex pairs):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = adjMatrix[v][u] = 1; // Mark the edges in the adjacency matrix
    }

    if (isConnected(adjMatrix)) {
        cout << "The graph is connected." << endl;
    } else {
        cout << "The graph is not connected." << endl;
    }

    return 0;
}
