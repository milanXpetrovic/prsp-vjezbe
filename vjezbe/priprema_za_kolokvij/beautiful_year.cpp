#include <iostream>
using namespace std;

int main()
{
    /*freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);*/

    int n;
    cin >> n;

    while (true)
    {
        n++;
        string temp = to_string(n);
        if (temp[0] != temp[1] && temp[0] != temp[2] && temp[0] != temp[3] && temp[1] != temp[2] && temp[1] != temp[3] && temp[2] != temp[3])
            break;
    }
    cout << n;
}