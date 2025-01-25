#include <iostream>
#include <vector>
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
        int m;
        cin >> m;
        // int arr[m];
        vector<vector<int>> a;
        vector<int> tempVec;
        for (int j = 0; j < m; j++)
        {
            int temp;
            cin >> temp;
            if (temp != 0)
            {
                tempVec.push_back(temp);
            }
            if ((!tempVec.empty() && temp == 0) || (!tempVec.empty() && j == m - 1))
            {
                a.push_back(tempVec);
                tempVec = {};
            }
        }
        if (a.size() < 2)
            cout << a.size() << endl;
        else
            cout << 2 << endl;
    }
}
