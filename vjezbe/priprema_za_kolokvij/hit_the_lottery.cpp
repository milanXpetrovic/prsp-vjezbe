// alias gpp='g++ -o ./solution'
// alias gpp='g++ -o ./solution solution.cpp'

#include <iostream>
// #include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int getBillNum(int n)
{
    int x[] = {100, 20, 10, 5, 1};
    if (n <= 0)
        return 0;
    for (int i : x)
    {
        if (n >= i)
        {
            return n / i + getBillNum(n % i);
        }
    }

    return 0;
}

int main()
{
    freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Rjesenje zadatka
    int n;
    cin >> n;
    int a = getBillNum(n);
    cout << a;
}