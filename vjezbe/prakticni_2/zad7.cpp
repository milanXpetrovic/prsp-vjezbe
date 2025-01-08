#include <bits/stdc++.h>
using namespace std;

// A structure to represent a weighted edge in graph
struct Edge
{
    int src, dest, weight;
};

// A structure to represent a connected, directed and
// weighted graph
struct Graph
{
    // V-> Number of vertices, E-> Number of edges
    int V, E;

    // Graph is represented as an array of edges.
    struct Edge *edge;
};

// Creates a graph with V vertices and E edges
struct Graph *createGraph(int V, int E)
{
    struct Graph *graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[graph->E];
    return graph;
}

// The main function that finds shortest distances
// from src to all other vertices using Bellman-
// Ford algorithm. The function also detects
// negative weight cycle and returns one such cycle if found
bool isNegCycleBellmanFord(struct Graph *graph, int src,
                           int dist[], int pred[])
{
    int V = graph->V;
    int E = graph->E;

    // Step 1: Initialize distances from src
    // to all other vertices as INFINITE
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        pred[i] = -1;
    }
    dist[src] = 0;

    // Step 2: Relax all edges |V| - 1 times.
    // A simple shortest path from src to any
    // other vertex can have at-most |V| - 1
    // edges
    for (int i = 1; i <= V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pred[v] = u;
            }
        }
    }

    // Step 3: check for negative-weight cycles.
    // The above step guarantees shortest distances
    // if graph doesn't contain negative weight cycle.
    // If we get a shorter path, then there
    // is a cycle.
    for (int i = 0; i < E; i++)
    {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
        {
            // Negative cycle found, trace back the cycle
            vector<int> cycle;
            int x = v;
            for (int i = 0; i < V; i++)
                x = pred[x];

            for (int cur = x;; cur = pred[cur])
            {
                cycle.push_back(cur);
                if (cur == x && cycle.size() > 1)
                    break;
            }
            reverse(cycle.begin(), cycle.end());

            cout << "YES\n";
            for (int node : cycle)
                cout << node << " ";
            cout << endl;

            return true;
        }
    }

    return false;
}

// Returns true if given graph has negative weight
// cycle.
bool isNegCycleDisconnected(struct Graph *graph)
{
    int V = graph->V;

    // To keep track of visited vertices to avoid
    // recomputations.
    bool visited[V];
    memset(visited, 0, sizeof(visited));

    // This array is filled by Bellman-Ford
    int dist[V];
    int pred[V];

    // Call Bellman-Ford for all those vertices
    // that are not visited
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            // If cycle found
            if (isNegCycleBellmanFord(graph, i, dist, pred))
                return true;

            // Mark all vertices that are visited
            // in above call.
            for (int i = 0; i < V; i++)
                if (dist[i] != INT_MAX)
                    visited[i] = true;
        }
    }

    return false;
}

int main()
{
    int V, E;
    cin >> V >> E;
    struct Graph *graph = createGraph(V, E);

    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph->edge[i].src = a;
        graph->edge[i].dest = b;
        graph->edge[i].weight = c;
    }

    if (!isNegCycleDisconnected(graph))
        cout << "NE" << endl;

    return 0;
}