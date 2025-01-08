#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
typedef long long ll;

void Dijkstra(vector<pair<ll, ll>> *adjList, ll n, ll source) {
    vector<ll> distance(n+1, LLONG_MAX);
    vector<bool> processed(n+1, false);
    distance[source] = 0;

    priority_queue<pair<ll, ll>> q;
    q.push({0, source});

    while (!q.empty()) {
        ll a = q.top().second;
        q.pop();

        if (processed[a]) continue;
        processed[a] = true;

        for (auto u : adjList[a]) {
            ll b = u.first, w = u.second;

            if (distance[a]+w < distance[b]) {
                distance[b] = distance[a]+w;
                q.push({-distance[b], b});
            }
        }
    }

    for (int i=1; i<=n; i++)
        cout<<distance[i]<<" ";
}

int main()
{
    //freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n,m, a,b,c;
    cin>>n>>m;
    vector<pair<ll, ll>>* adjList = new vector<pair<ll, ll>>[n+1];

    for (int i=0; i<m; i++) {
        cin>>a>>b>>c;
        adjList[a].push_back({b, c});
    }
    Dijkstra(adjList, n, 1);

    delete [] adjList;
    return 0;
}
