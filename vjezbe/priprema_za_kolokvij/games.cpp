#include <iostream>
using namespace std;
int main()
{
    /*freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);*/

    int n;
    cin >> n;
    pair<int, int> arr[n] = {};
    int ct = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[i] = {a, b};
        // cout << arr[i].first << endl;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // cout << arr[i].first << " " << arr[i].second << "," << arr[j].first << " " << arr[j].second;
            if (arr[i].first == arr[j].second)
                ct++;
            if (arr[j].first == arr[i].second)
                ct++;
        }
    }
    cout << ct;
}