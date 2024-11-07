    // alias gpp='g++ -o ./solution'
    // alias gpp='g++ -o ./solution solution.cpp'
     
    #include <iostream>
    #include <vector>
    #include <algorithm>  
    // #include <bits/stdc++.h>
     
    using namespace std;
     
    typedef long long ll;
     
    int main(){
        //freopen("ulaz.txt", "r", stdin);
        ios::sync_with_stdio(0);
        cin.tie(0);
     
        vector<int> coins({1,5,10,20,100});
        reverse(coins.begin(), coins.end());
        int money;
        cin>>money;
        
        int count = 0;
        for(int i=0;i<coins.size();i++)
        {    count += money / coins[i];
        money %= coins[i];
     
    }
    cout<<count;
    }