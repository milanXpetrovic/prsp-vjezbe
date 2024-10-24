// alias gpp='g++ -o ./solution'
// alias gpp='g++ -o ./solution solution.cpp'

#include <iostream>
#include <vector>
#include <set>
 #include <bits/stdc++.h>

using namespace std;

bool mitm(vector<int> &nums, set<int>sums,int targetSum){

   for (int i = 0; i < sums; i++)
    {
        int sum = 0;

        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                sum += l[j];
            }
        }
        sums.insert(sum);
        if(sum==targetSum){
            found = true;
            break;
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
    vector<int> l_right = (l.begin()+l.size/2,l.end());
    vector<int> l_left = (l.begin(), l.begin()+l.size()/2);
    set<int> leftSum;
    set<int> rightSum;

    mitm(l_right,leftSum,k);
    mitm(l_left,rightSum,k);

    for(int leftSum : leftSums){
        if l_right.count(k-leftSum){
            cout<<"YES";
        }
        else{
            cout<<-1;
        }
    }
    return 0;
}
