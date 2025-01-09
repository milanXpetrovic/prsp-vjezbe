#include <iostream>
using namespace std;

int main()
{
    /*freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);*/

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        int ct = 0;
        if (a == b)
        {
            cout << ct << endl;
            continue;
        }
        ct = abs(a - b) / 10;
        if (abs(a - b) % 10 != 0)
        {
            ct++;
        }
        cout << ct << endl;
    }
}