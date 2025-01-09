#include <iostream>
#include <vector>
using namespace std;
int main()
{
    /*freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);

    cin.tie(0);*/
    // UNSOLVED!
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        vector<int> x;
        int deepest = 0;
        for (int j = 0; j < a; j++)
        {
            int temp;
            cin >> temp;
            x.push_back(0);
            int deepest_temp = deepest;
            for (int k = j; k >= max(0, max(j - temp + 1, deepest)); k--)
            {
                x[k] = 1;
                if (deepest_temp >= j - temp + 1)
                    deepest_temp = j + 1;
            }
            deepest = deepest_temp;
        }
        for (auto l : x)
        {
            cout << l << " ";
        }
        // cout << "-" << deepest;
        cout << endl;
    }
}