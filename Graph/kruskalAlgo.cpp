//without using union by rank
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

bool cmp(Edge a, Edge b) {
    return a.weight < b.weight;
}

int find(int x, vector<int>& parent) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x], parent); // recursively finds the parent node
}

void merge(int x, int y, vector<int>& parent) {
    x = find(x, parent);
    y = find(y, parent);
    if (x != y) parent[x] = y; //T <- T U {ei}
}

int main(int argc, char const *argv[]) {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<Edge> edges(m);
    cout << "Enter edges in the format (u v w): ";
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(n+1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    vector<Edge> mst;
    for (int i = 0; i < m; i++) {
        int u = edges[i].u, v = edges[i].v, weight = edges[i].weight;
        if (find(u, parent) != find(v, parent)) {
            merge(u, v, parent);
            mst.push_back(edges[i]);
        }
    }

    cout << "Minimum Spanning Tree:\n";
    for (int i = 0; i < mst.size(); i++) {
        cout << mst[i].u << " " << mst[i].v << " " << mst[i].weight << "\n";
    }

    return 0;
}
