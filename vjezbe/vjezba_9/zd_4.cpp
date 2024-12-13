#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> adj[100001];
int visited[100001], parent[100001];

bool dfs(int v, int& cycle_start, int& cycle_end) {
    visited[v] = 1;
    for (int neighbor : adj[v]) {
        if (visited[neighbor] == 0) {
            parent[neighbor] = v;
            if (dfs(neighbor, cycle_start, cycle_end)) return true;
        } else if (visited[neighbor] == 1) {
            cycle_start = neighbor;
            cycle_end = v;
            return true;
        }
    }
    visited[v] = 2;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    int cycle_start = -1, cycle_end = -1;
    for (int i = 1; i <= n; ++i) {
        if (visited[i] == 0) {
            if (dfs(i, cycle_start, cycle_end)) break;
        }
    }

    if (cycle_start == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        int v = cycle_end;
        while (v != cycle_start) {
            cycle.push_back(v);
            v = parent[v];
        }
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());
        cout << cycle.size() << endl;
        for (size_t i = 0; i < cycle.size(); ++i) {
            cout << cycle[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
