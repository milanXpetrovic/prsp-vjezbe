#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    /*freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);*/

    string n;
    cin >> n;
    string temp = "";
    vector<string> nums;
    for (auto i : n)
    {
        // cout << i;
        if (i != '+')
            temp += i;
        else
        {
            nums.push_back(temp);
            temp = "";
        }
    }
    nums.push_back(temp);
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i];
        if (i != nums.size() - 1)
            cout << "+";
    }
}