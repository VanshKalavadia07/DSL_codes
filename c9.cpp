#include <iostream>
using namespace std;

#define MAX 10

// Structure for Edge
struct Edge
{
    int u, v, weight;
};

// Structure for Graph
struct Graph
{
    Edge edges[20];
    int edgeCount;
};

// Structure for Adjacency List
struct Node
{
    int vertex, weight;
    Node* next;
};

// Add edge to graph
void addEdge(Graph &g, Node* adj[], int u, int v, int w)
{
    g.edges[g.edgeCount].u = u;
    g.edges[g.edgeCount].v = v;
    g.edges[g.edgeCount].weight = w;
    g.edgeCount++;

    Node* newNode = new Node;
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = new Node;
    newNode->vertex = u;
    newNode->weight = w;
    newNode->next = adj[v];
    adj[v] = newNode;
}

// Find parent
int find(int parent[], int i)
{
    if (parent[i] == i)
        return i;

    return find(parent, parent[i]);
}

// Union of two sets
void unite(int parent[], int a, int b)
{
    int rootA = find(parent, a);
    int rootB = find(parent, b);

    parent[rootA] = rootB;
}

// Kruskal's Algorithm
void kruskal(Graph g, int V)
{
    // Sort edges by weight
    for (int i = 0; i < g.edgeCount - 1; i++)
    {
        for (int j = 0; j < g.edgeCount - i - 1; j++)
        {
            if (g.edges[j].weight > g.edges[j + 1].weight)
            {
                Edge temp = g.edges[j];
                g.edges[j] = g.edges[j + 1];
                g.edges[j + 1] = temp;
            }
        }
    }

    int parent[MAX];

    for (int i = 0; i < V; i++)
        parent[i] = i;

    int totalWeight = 0;
    int count = 0;

    cout << "\nMinimum Spanning Tree:\n";
    cout << "Edge\tWeight\n";

    for (int i = 0; i < g.edgeCount && count < V - 1; i++)
    {
        int u = g.edges[i].u;
        int v = g.edges[i].v;

        int rootU = find(parent, u);
        int rootV = find(parent, v);

        if (rootU != rootV)
        {
            cout << u << " - " << v << "\t"
                 << g.edges[i].weight << endl;

            unite(parent, u, v);

            totalWeight += g.edges[i].weight;
            count++;
        }
    }

    if (count == V - 1)
        cout << "Total MST Weight: " << totalWeight;
    else
        cout << "MST cannot be formed. Graph is disconnected.";
}

int main()
{
    int V = 5;

    Graph g;
    g.edgeCount = 0;

    Node* adj[MAX] = {NULL};

    // Creating weighted graph
    addEdge(g, adj, 0, 1, 2);
    addEdge(g, adj, 0, 3, 6);
    addEdge(g, adj, 1, 2, 3);
    addEdge(g, adj, 1, 3, 8);
    addEdge(g, adj, 1, 4, 5);
    addEdge(g, adj, 2, 4, 7);
    addEdge(g, adj, 3, 4, 9);

    // Display adjacency list
    cout << "Weighted Adjacency List:\n";

    for (int i = 0; i < V; i++)
    {
        cout << i << " -> ";

        Node* temp = adj[i];

        while (temp != NULL)
        {
            cout << "(" << temp->vertex
                 << ", " << temp->weight << ") ";

            temp = temp->next;
        }

        cout << endl;
    }

    // Generate MST
    kruskal(g, V);

    return 0;
}
