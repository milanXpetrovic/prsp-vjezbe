#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int find(vector<int> &link, int x) {
    if (x != link[x]) {
        link[x] = find(link, link[x]);
    }
    return link[x];
}

bool unite(vector<int> &link, vector<int> &compSize, int x, int y) {
    int rootX = find(link, x);
    int rootY = find(link, y);
    if (rootX == rootY) return false;

    if (compSize[rootX] > compSize[rootY]) {
        link[rootY] = rootX;
    } else if (compSize[rootX] < compSize[rootY]) {
        link[rootX] = rootY;
    } else {
        link[rootY] = rootX;
        compSize[rootX]++;
    }
    return true;
}

int main() {
    //freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin>>n>>m;

    vector<int> link(n+1), compSize(n+1, 0);
    for (int i = 1; i <= n; i++)
        link[i] = i;

    vector<tuple<ll, int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin>>a>>b>>c;
        edges[i] = {c, a, b};
    }
    sort(edges.begin(), edges.end());

    ll totalCost = 0;
    int edgesUsed = 0;
    for (auto &[c, a, b] : edges) {
        if (unite(link, compSize, a, b)) {
            totalCost += c;
            edgesUsed++;
            if (edgesUsed == n-1) break;
        }
    }

    if (edgesUsed == n-1)
        cout<<totalCost;
    else
        cout<<"NEMOGUĆE";
    return 0;
}
