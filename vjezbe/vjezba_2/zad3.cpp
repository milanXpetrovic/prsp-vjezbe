// alias gpp='g++ -o ./solution'
// alias gpp='g++ -o ./solution solution.cpp'
 
#include <iostream>
//s#include <bits/stdc++.h>
#include<vector>
#include<climits>
 
using namespace std;
 
typedef long long ll;
 
int main()
{
    freopen("ulaz1.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
   
    vector<int> numbers(n);
    for(int i=0; i<n; i++)
    {
        cin>>numbers[i];
    }
    int maxSum = INT_MIN;
    int temp_sum = 0;
   for(int i=0; i<n; i++)
   {
       temp_sum += numbers[i];
       if(temp_sum>maxSum){
               maxSum = temp_sum;
           }
       if(temp_sum<0){
           temp_sum=0;
       }
       }


   cout<<maxSum<<endl;
 
 
 
 
 
 
 
 
 
 
    // Rjesenje zadatka
 
 
 
 
 
}