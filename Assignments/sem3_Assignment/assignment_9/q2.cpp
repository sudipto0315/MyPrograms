#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(const vector<vector<int>> &graph, int node, vector<int> &shortest, vector<bool> &visited, int current, int &diameter)
{
    visited[node] = true;
    shortest[node] = current;

    for (int neighbor : graph[node])
    {
        if (!visited[neighbor])
        {
            DFS(graph, neighbor, shortest, visited, current + 1, diameter);
        }
    }

    diameter = max(diameter, shortest[node]);
}

int findDiameter(const vector<vector<int>> &graph)
{
    int n = graph.size();
    int diameter = 0;

    for (int i = 0; i < n; i++)
    {
        vector<bool> visited(n, false);
        vector<int> shortest(n, 0);
        DFS(graph, i, shortest, visited, 0, diameter);
    }

    return diameter;
}

int main()
{
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<int>> graph(n);

    cout << "Enter the edges (format: u v):" << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int diameter = findDiameter(graph);

    cout << "The diameter of the graph is: " << diameter << endl;

    return 0;
}
