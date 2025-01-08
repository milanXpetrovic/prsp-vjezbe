#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int MAXD = 30; // ceil(log2(10^9))

int n, q;
int parent[MAXN][MAXD];

int jump(int a, int d)
{
    for (int i = 0; i < MAXD; i++)
        if (d & (1 << i))
            a = parent[a][i];
    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> parent[i][0];
    }
    for (int d = 1; d < MAXD; d++)
        for (int i = 1; i <= n; i++)
        {
            parent[i][d] = parent[parent[i][d - 1]][d - 1];
        }

    while (q--)
    {
        int a, d;
        cin >> a >> d;
        cout << jump(a, d) << '\n';
    }
}