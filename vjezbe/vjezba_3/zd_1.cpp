// alias gpp='g++ -o ./solution'
// alias gpp='g++ -o ./solution solution.cpp'

#include <iostream>
#include <vector>
// #include <bits/stdc++.h>

using namespace std;

void getSubset(int k,int n,vector<int> &subset,vector<vector<int>> &result){
    if(k==n){
        result.push_back(subset);
        return;
    }
    getSubset(k+1,n,subset,result);
    subset.push_back(k);
    getSubset(k+1,n,subset,result);
    subset.pop_back();
}


vector<vector<int>> search(int n)
{
    vector<vector<int>> result;
    vector<int> subset;
    getSubset(0,n,subset,result);
    return result;
}

typedef long long ll;

int main()
{

    int n;
    cin>>n;
    vector<vector<int>> allSubsets = search(n);

    for(auto& subset:allSubsets){
            cout<<"[ " ;
            for(int num : subset){
                cout<<num<<" ";
            }
            cout<<"]";
            cout<<endl;
    }

    return 0;
}
