#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

const long long INF = LLONG_MAX;

void shortest_routes(int n, int m, int q, vector<tuple<int, int, long long>>& roads, vector<pair<int, int>>& queries) {
    vector<vector<long long>> dist(n, vector<long long>(n, INF));

    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }

    for (auto& road : roads) {
        int a, b;
        long long c;
        tie(a, b, c) = road;
        --a; --b; 
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    for (auto& query : queries) {
        int a, b;
        tie(a, b) = query;
        --a; --b;
        if (dist[a][b] == INF) {
            cout << -1 << "\n";
        } else {
            cout << dist[a][b] << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<tuple<int, int, long long>> roads(m);
    for (int i = 0; i < m; ++i) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        roads[i] = {a, b, c};
    }

    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        queries[i] = {a, b};
    }

    shortest_routes(n, m, q, roads, queries);

    return 0;
}
