// alias gpp='g++ -o ./solution'
// alias gpp='g++ -o ./solution solution.cpp'

#include <iostream>
// #include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Rjesenje zadatka
    string a = "hello";
    string yes = "YES";
    string no = "NO";
    string n;
    int br = 0;
    cin >> n;

    for (auto i : n)
    {
        if (i == a[br])
            br++;
    }
    if (br == a.length())
        cout << yes;
    else
        cout << no;

    return 0;
}