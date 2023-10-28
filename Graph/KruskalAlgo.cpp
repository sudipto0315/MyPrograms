#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
    int u, v, w;
};

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

int find(int x, vector<int> &parent)
{
    if (parent[x] == x)
    {
        return x;
    }
    return parent[x] = find(parent[x], parent);
}

void merge(int x, int y, vector<int> &parent, vector<int> &rank)
{
    int px = find(x, parent);
    int py = find(y, parent);
    if (rank[px] < rank[py])
    {
        parent[px] = py;
    }
    else if (rank[px] > rank[py])
    {
        parent[py] = px;
    }
    else
    {
        parent[px] = py;
        rank[py]++;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    vector<Edge> mst;
    int cost = 0;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;
        if (find(u, parent) != find(v, parent))
        {
            merge(u, v, parent, rank);
            mst.push_back(edges[i]);
            cost += w;
        }
    }

    cout << "Minimum Spanning Tree:\n";
    for (int i = 0; i < mst.size(); i++)
    {
        cout << mst[i].u << " " << mst[i].v << " " << mst[i].w << "\n";
    }
    cout << "Cost: " << cost << "\n";

    return 0;
}
