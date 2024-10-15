// alias gpp='g++ -o ./solution'
// alias gpp='g++ -o ./solution solution.cpp'

#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
using namespace std;

typedef long long ll;

int main()
{
    freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x[8] = {1, 2, 5, 10, 20, 50, 100, 200};
    vector<int> a = {};
    // Rjesenje zadatka
    int n;
    cin >> n;

    while (n > 0)
    {
        for (int i = 7; i >= 0; i--)
        {
            if (x[i] <= n)
            {
                a.push_back(x[i]);
                n -= x[i];
                break;
                cout << n;
            }
        }
    }
    for (auto i : a)
    {
        cout << i << " ";
    }
}