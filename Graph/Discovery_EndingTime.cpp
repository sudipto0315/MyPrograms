#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void addEdge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
}

void DFS(vector<vector<int>> &adj, vector<int> &discoveryTime, vector<int> &finishingTime)
{
    int V = adj.size();
    vector<bool> visited(V, false);
    int time = 0;
    stack<int> stack;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            stack.push(i);
            while (!stack.empty())
            {
                int v = stack.top();
                stack.pop();
                if (!visited[v])
                {
                    visited[v] = true;
                    discoveryTime[v] = time++;
                    stack.push(v); // Push the node back onto the stack for finishing time
                    for (int u : adj[v])
                    {
                        if (!visited[u])
                        {
                            stack.push(u);
                        }
                    }
                }
                else if (finishingTime[v] == -1)
                {
                    finishingTime[v] = time++;
                }
            }
        }
    }
}

int main()
{
    int V, E;
    cout << "Enter the number of nodes (vertices): ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);
    vector<int> discoveryTime(V, -1);
    vector<int> finishingTime(V, -1);

    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }

    DFS(adj, discoveryTime, finishingTime);

    cout << "Node\tDiscovery Time\tFinishing Time\n";
    for (int i = 0; i < V; i++)
    {
        cout << i << "\t" << discoveryTime[i] << "\t\t" << finishingTime[i] << endl;
    }

    return 0;
}
