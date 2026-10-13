#include <iostream>
using namespace std;

// Global variables declared outside the class so both dfs() and main() can access them
int graph[5][5];
int visitedVertex[5];
int n;

void dfs(int vertex)
{
    visitedVertex[vertex] = 1;
    cout << vertex << " ";

    for(int i = 0; i < n; i++)
    {
        // Fixed: Use 'graph' instead of 'adj'
        if(graph[vertex][i] == 1 && !visitedVertex[i])
        {
            dfs(i);
        }
    }
}

int main()
{
    int e;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> e;

    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        // Fixed: Use 'graph' instead of 'adj'
        graph[u][v] = 1;
        graph[v][u] = 1; // For an undirected graph
    }

    int start;
    cout << "Enter the Starting Vertex: "; // Fixed: Added missing semicolon
    cin >> start;

    cout << "DFS Traversal: ";
    dfs(start);
    cout << endl;

    return 0;
}
