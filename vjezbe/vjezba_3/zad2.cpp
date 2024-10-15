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

    // Rjesenje zadatka
    string n;
    vector<string> x = {};
    cin >> n;

    for (auto i : n)
    {
        string a;
        switch (i)
        {
        case 'A':
            a = "00";
            break;

        case 'B':
            a = "01";
            break;
        case 'C':
            a = "10";
            break;
        case 'D':
            a = "11";
            break;

        default:
            break;
        }
        x.push_back(a);
    }
    for (auto i : x)
    {
        cout << i;
    }
}