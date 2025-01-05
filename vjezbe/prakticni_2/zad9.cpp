#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void topologicalSortUtil(int v, vector<vector<int>> &adj,
                         vector<bool> &visited,
                         stack<int> &Stack)
{
    visited[v] = true;

    for (int i : adj[v])
    {
        if (!visited[i])
            topologicalSortUtil(i, adj, visited, Stack);
    }

    Stack.push(v);
}

void topologicalSort(vector<vector<int>> &adj, int V)
{
    stack<int> Stack;
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            topologicalSortUtil(i, adj, visited, Stack);
    }

    // Print contents of stack
    while (!Stack.empty())
    {
        char sub = Stack.top();
        cout << static_cast<char>('A' + sub) << " ";
        Stack.pop();
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        char a, b;
        cin >> a >> b;
        int indexA = a - 'A';
        int indexB = b - 'A';
        adj[indexA].push_back(indexB);
    }
    topologicalSort(adj, n);
    cout << endl;
    return 0;
}