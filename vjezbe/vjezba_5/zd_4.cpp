#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_STUDENTS = 100005;  
vector<int> adj[MAX_STUDENTS];   
int team[MAX_STUDENTS];           

bool bfs(int start) {
    queue<int> q;
    q.push(start);
    team[start] = 1; 

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : adj[current]) {
            if (team[neighbor] == 0) { 
                team[neighbor] = (team[current] == 1) ? 2 : 1;
                q.push(neighbor);
            } else if (team[neighbor] == team[current]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    fill(team, team + n + 1, 0);

    for (int i = 1; i <= n; i++) {
        if (team[i] == 0) { 
            if (!bfs(i)) { 
                cout << "NEMA" << endl;
                return 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << team[i] << " ";
    }
    cout << endl;

    return 0;
}
