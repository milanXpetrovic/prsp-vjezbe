// alias gpp='g++ -o ./solution'
// alias gpp='g++ -o ./solution solution.cpp'

#include <iostream>
#include <vector>
// #include <bits/stdc++.h>

using namespace std;


bool findAll(const vector<int>& l, int k)
{
    int n = l.size();
    int totalSubsets = 1 << n;


    for (int i = 0; i < totalSubsets; i++)
    {
        vector<int> subset;
        int currSum = 0;

        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                subset.push_back(l[j]);
                currSum += l[j];
            }
        }

        if (currSum == k)
        {
            for (int num : subset)
            {
                cout << num << " ";
            }
            cout << endl;
            return true;
        }
    }
    return false;
}

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin>>k;
    int n;
    cin>>n;
    vector<int> l(n);
    for (int i = 0; i < n; i++)
    {
        cin >> l[i];
    }
    findAll(l,k);
    return 0;
}
