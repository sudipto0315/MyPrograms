#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector<vector<int>> &adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Function to print the graph
void printGraph(const vector<vector<int>> &adj)
{
    int V = adj.size();
    for (int v = 0; v < V; ++v)
    {
        cout << "Adjacency list of vertex " << v << ": ";
        for (int neighbor : adj[v])
        {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

bool isBipartiteUtil(vector<vector<int>>& adjList, int src, vector<int> &colorArr, int V) {
    colorArr[src] = 1;
    queue<int> q;
    q.push(src);
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adjList[u]) {
            if (colorArr[v] == -1) {
                colorArr[v] = 1 - colorArr[u];
                q.push(v);
            } else if (colorArr[v] == colorArr[u]) {
                return false;
            }
        }
    }

    return true;
}

bool isBipartite(vector<vector<int>>& adjList, int V) {
    vector<int> colorArr(V, -1);

    for (int i = 0; i < V; i++) {
        if (colorArr[i] == -1) {
            if (isBipartiteUtil(adjList, i, colorArr, V)==false) {
                return false;
            }
        }
    }

    return true;
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

    cout << "Graph representation:" << endl;
    printGraph(adj);

    bool result = isBipartite(adj, V);
    if (result) {
        cout << "Yes, the graph is Bipartite." << endl;
    } else {
        cout << "No, the graph is not Bipartite." << endl;
    }

    return 0;
}
