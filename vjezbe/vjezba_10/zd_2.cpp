#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 200005;
const int LOG = 21;

int succ[LOG][MAX_N], len[MAX_N], vis[MAX_N];

void dfs(int s) {
    if (vis[s]) return;
    vis[s] = 1;
    dfs(succ[0][s]);
    len[s] = len[succ[0][s]] + 1;
}

int lift(int x, int d) {
    for (int i = 0; d > 0; d >>= 1, i++) {
        if (d & 1) x = succ[i][x];
    }
    return x;
}

void solve() {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> succ[0][i];
    }

    for (int i = 1; i < LOG; i++) {
        for (int j = 1; j <= n; j++) {
            succ[i][j] = succ[i-1][succ[i-1][j]];
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i);
    }

    while (q--) {
        int x, y;
        cin >> x >> y;

        int xx = lift(x, len[x]); 
        if (lift(x, len[x] - len[y]) == y) {
            cout << len[x] - len[y] << endl;
        } else if (lift(xx, len[xx] - len[y]) == y) {
            cout << len[x] + len[xx] - len[y] << endl;
        } else {
            cout << -1 << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    
    solve();
    return 0;
}
