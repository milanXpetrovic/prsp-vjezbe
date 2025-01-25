// alias gpp='g++ -o ./solution'
// alias gpp='g++ -o ./solution solution.cpp'

#include <iostream>
// #include <bits/stdc++.h>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

typedef long long ll;

int main()
{
    freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Rjesenje zadatka
    int a, b;
    cin >> a >> b;
    int total;
    if (a < 2 || b < 2)
    {
        cout << max(b / 2, a / 2);
        return 0;
    }
    if (a % 2 != 0 || b % 2 != 0)
    {
        int a2 = a, b2 = b;
        if (a % 2 != 0)
            a2 = a - 1;
        if (b % 2 != 0)
            b2 = b - 1;
        total = a2 / 2 * b2;
        if (a % 2 != 0)
            total += b / 2;
        if (b % 2 != 0)
            total += a / 2;
    }
    else
    {
        total = a / 2 * b;
    }
    cout << total;
}