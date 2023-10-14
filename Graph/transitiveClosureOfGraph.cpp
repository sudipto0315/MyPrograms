// Given a directed graph, find out if a vertex j is reachable from another vertex i
// for all vertex pairs (i, j) in the given graph. Here reachable mean that there is
// a path from vertex i to j. The reach-ability matrix is called the transitive closure
// of a graph.
#include <iostream>
#include <vector>

using namespace std;

// Adjacency matrix of the graph
vector<vector<int>> adj;

// Transitive closure matrix
vector<vector<int>> reach;

// Number of nodes in the graph
int n;

// Function to print the transitive closure matrix
void printSolution()
{
    cout << "Following matrix is transitive closure of the given graph\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << reach[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to compute the transitive closure of the graph
void transitiveClosure()
{
    // Initialize the reach matrix
    reach = adj;

    // Run Warshall's algorithm
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
    }
}

// Function to read the adjacency matrix from the user
void readAdjacencyMatrix()
{
    cout << "Enter the number of nodes in the graph: ";
    cin >> n;

    adj.resize(n, vector<int>(n));

    cout << "Enter the adjacency matrix of the graph:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adj[i][j];
        }
    }
}

int main()
{
    // Read the adjacency matrix from the user
    readAdjacencyMatrix();

    // Compute the transitive closure
    transitiveClosure();

    // Print the transitive closure matrix
    printSolution();

    return 0;
}
