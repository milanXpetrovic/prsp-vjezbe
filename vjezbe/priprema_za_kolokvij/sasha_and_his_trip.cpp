#include <iostream>
using namespace std;
int main()
{
    int n, v;
    cin >> n >> v;

    int ct = 0;
    int gas = 0;
    int city = 1;

    if (v >= n - 1)
    {
        ct = n - 1;
    }
    else
    {
        gas = v;
        ct = v;
        while ((n - city) > v)
        {
            city++;
            gas--;
            ct += city;
            gas = v;
        }
    }
    cout << ct << endl;
}