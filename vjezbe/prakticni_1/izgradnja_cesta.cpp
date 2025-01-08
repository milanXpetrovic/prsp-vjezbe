#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<int>* adjList, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adjList, visited);
        }
    }
}

int main() {
    //freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m, a,b;
    cin>>n>>m;

    vector<int>* adjList = new vector<int>[n+1];
    for (int i=0; i<m; i++) {
        cin>>a>>b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    vector<bool> visited(n+1, false);
    vector<int> representatives;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            representatives.push_back(i);
            dfs(i, adjList, visited);
        }
    }

    int roadsNeeded = representatives.size() - 1;
    cout<<roadsNeeded<<endl;
    for (int i=1; i<=roadsNeeded; i++) {
        cout<<representatives[i-1] <<" " <<representatives[i]<<endl;
    }

    delete [] adjList;
    return 0;
}
