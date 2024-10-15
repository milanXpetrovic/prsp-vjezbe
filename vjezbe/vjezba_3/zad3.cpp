// alias gpp='g++ -o ./solution'
// alias gpp='g++ -o ./solution solution.cpp'

#include <iostream>
// #include <bits/stdc++.h>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

bool compare(vector<int> a, vector<int> b)
{
    int x = a[1] - a[0];
    int y = b[1] - b[0];
    if (x == y)
        return a[0] < b[0];
    return x < y;
}

int main()
{
    freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Rjesenje zadatka
    vector<vector<int>> x = {};
    int n;
    cin >> n;
    int mali = 0;
    int veliki = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a;
        cin >> b;
        mali = min(mali, a);
        veliki = max(veliki, b);
        vector<int> temp;
        temp.push_back(a);
        temp.push_back(b);
        x.push_back(temp);
    }
    sort(x.begin(), x.end(), compare);

    int y;
    int nakon = 0;

    for (auto i : x)
    {
        if (i[0] < nakon)
            continue;
        nakon = i[1];
        cout << i[0] << " ";
        cout << i[1] << " ";
        y = i[1];
        cout << endl;
        if (i[1] >= veliki)
            break;
    }
}