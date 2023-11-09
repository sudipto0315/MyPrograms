// Given a directed graph. Find all the strongly connected components in the graph Without using DFS.
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void tarjan(int u, vector<vector<int>> &adj, vector<int> &low, vector<int> &disc, vector<bool> &inStack, stack<int> &st, vector<vector<int>> &scc)
{
    static int time = 0;
    disc[u] = low[u] = ++time;
    st.push(u);
    inStack[u] = true;

    for (int v : adj[u])
    {
        if (disc[v] == -1)
        {
            tarjan(v, adj, low, disc, inStack, st, scc);
            low[u] = min(low[u], low[v]);
        }
        else if (inStack[v])
        {
            low[u] = min(low[u], disc[v]);
        }
    }

    if (low[u] == disc[u])
    {
        vector<int> component;
        while (true)
        {
            int v = st.top();
            st.pop();
            inStack[v] = false;
            component.push_back(v);
            if (u == v)
            {
                break;
            }
        }
        scc.push_back(component);
    }
}

vector<vector<int>> tarjanSCC(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<int> disc(n, -1), low(n, -1);
    vector<bool> inStack(n, false);
    stack<int> st;
    vector<vector<int>> scc;

    for (int i = 0; i < n; i++)
    {
        if (disc[i] == -1)
        {
            tarjan(i, adj, low, disc, inStack, st, scc);
        }
    }

    return scc;
}

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<vector<int>> scc = tarjanSCC(adj);

    for (vector<int> &component : scc)
    {
        cout << "Component: ";
        for (int u : component)
        {
            cout << u << " ";
        }
        cout << endl;
    }

    return 0;
}
