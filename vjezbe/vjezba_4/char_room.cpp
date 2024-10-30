// alias gpp='g++ -o ./solution'
// alias gpp='g++ -o ./solution solution.cpp'

#include <iostream>
// #include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    // freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    string hello = "hello";
    int j = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == hello[j])
        {
            j++;
        }
        if (j == 5)
        {
            cout << "YES" << endl;
            break;
        }
    }
    if (j != 5)
    {
        cout << "NO" << endl;
    }

    return 0;
}