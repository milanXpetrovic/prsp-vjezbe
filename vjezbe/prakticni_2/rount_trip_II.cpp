#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> adjList;
vector<int> visited;
vector<int> predecessor;
int cycle_start = -1, cycle_end = -1;

bool dfs(int node)
{
    visited[node] = 1;
    for (int neighbor : adjList[node])
    {
        if (visited[neighbor] == 0)
        {
            predecessor[neighbor] = node;
            if (dfs(neighbor))
                return true;
        }
        else if (visited[neighbor] == 1)
        {
            cycle_end = node;
            cycle_start = neighbor;
            return true;
        }
    }
    visited[node] = 2;
    return false;
}

int main()
{
    cin >> n >> m;
    adjList.resize(n + 1);
    visited.assign(n + 1, 0);
    predecessor.assign(n + 1, -1);

    for (int i = 0; i < m; ++i)
    {
        int from, to;
        cin >> from >> to;
        adjList[from].push_back(to);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (visited[i] == 0 && dfs(i))
            break;
    }

    if (cycle_start == -1)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = predecessor[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());

        cout << cycle.size() << endl;
        for (int v : cycle)
            cout << v << " ";
        cout << endl;
    }

    return 0;
}