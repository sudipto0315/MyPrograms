#include <iostream>
#include <vector>
using namespace std;

vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& adj) {
    vector<int> inDegree(n, 0);
    for (auto& edge : adj) {
        inDegree[edge[1]]++;
    }

    vector<int> result;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            result.push_back(i);
        }
    }

    return result;
}

int main(int argc, char const *argv[]) {
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<int>> adj(m, vector<int>(2));
    cout << "Enter the edges (as pairs of vertices): ";
    for (int i = 0; i < m; i++) {
        cin >> adj[i][0] >> adj[i][1];
    }

    vector<int> result = findSmallestSetOfVertices(n, adj);

    cout << "Smallest set of vertices from which all nodes in the graph are reachable: "<<endl;
    for (int vertex : result) {
        cout << vertex << " ";
    }

    return 0;
}