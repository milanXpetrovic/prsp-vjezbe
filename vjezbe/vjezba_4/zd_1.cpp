#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> coins({1, 2, 5, 10, 20, 50, 100, 200});
    reverse(coins.begin(), coins.end());
    int money;
    cin >> money;

    int count = 0;
    vector<int> used_coins;

    for (int i = 0; i < coins.size(); i++)
    {
        while (money >= coins[i])
        {
            used_coins.push_back(coins[i]);
            money -= coins[i];
            count++;
        }
    }
    cout << "Total coins used: " << count << endl;

    cout << "Coins used: ";
    for (int coin : used_coins)
    {
        cout << coin << " ";
    }
    cout << endl;
    return 0;
}
