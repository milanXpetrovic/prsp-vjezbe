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
    string en = "abcdefghijklmnopqrstuvwxyz";
    string n;
    int count = 0;
    cin >> n;
    if (n.length() < en.length())
    {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < n.length(); i++)
    {
        if (n[i] == en[count] || n[i] < en[count])
        {
            if (n[i] < en[count])
            {
                n[i] = en[count];
            }
            count++;
        }
    }
    if (count == en.length())
        cout << n;
    else
        cout << -1;
    return 0;
}