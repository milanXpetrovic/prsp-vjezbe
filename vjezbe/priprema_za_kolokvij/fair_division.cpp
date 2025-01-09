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
        int x;
        cin >> x;
        int ones = 0, twos = 0;
        for (int j = 0; j < x; j++)
        {
            int temp;
            cin >> temp;
            if (temp == 1)
                ones++;
            else
                twos++;
        }
        if ((ones == 0 && twos % 2 == 0) || (ones % 2 == 0 && ones != 0))
            cout << "YES" << endl;
        else // if (ones % 2 == 1)
            cout << "NO" << endl;
    }
}