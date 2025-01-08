#include <iostream>
#include <vector>
#include <climits>
using namespace std;
typedef long long ll;

int main()
{
    //freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,q, a,b,c;
    cin>>n>>m>>q;
    vector<ll> distance((n+1) * (n+1), LLONG_MAX);

    for (int i = 1; i <= n; i++) {
        distance[i*n + i] = 0;
    }

    for (int i=0; i<m; i++) {
        cin>>a>>b>>c;
        distance[a*n + b] = min(distance[a*n + b], ll(c));
        distance[b*n + a] = min(distance[a*n + b], ll(c));
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (distance[i*n + k] < LLONG_MAX && distance[k*n + j] < LLONG_MAX) {
                    distance[i*n + j] = min(distance[i*n + j], distance[i*n + k] + distance[k*n + j]);
                }
            }
        }
    }

    for (int i=0; i<q; i++) {
        cin>>a>>b;
        if (distance[a*n + b] == LLONG_MAX)
            cout<<"-1";
        else
            cout<<distance[a*n + b];
        cout<<endl;
    }
    return 0;
}
