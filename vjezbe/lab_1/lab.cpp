#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        long long n;
        cin >> n;
        long long paran = 0, neparan = 0;
        for (int i = 0; i < n; i++)
        {

            long long x;
            cin >> x;
            if (x % 2 == 0)
            {
                paran += x;
            }
            else
                neparan += x;
        }
        if (paran > neparan)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}