#include <iostream>

using namespace std;

int main()
{
    /*freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);*/

    int n;
    cin >> n;
    int ct = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if ((a + b + c) > 1)
        {
            ct++;
        }
    }
    cout << ct;
}