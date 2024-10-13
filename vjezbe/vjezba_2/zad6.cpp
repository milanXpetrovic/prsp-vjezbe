// alias gpp='g++ -o ./solution'
// alias gpp='g++ -o ./solution solution.cpp'
 
#include <iostream>
#include<vector>
#include<climits>
 
using namespace std;
 
typedef long long ll;
 
int main()
{
    //freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string seq;
    cin>>seq;
    int longest = 1;
    int maxL = 1;
    for(int i=1; i<seq.length(); i++)
    {
        char prev = seq[i-1];
        char next= seq[i];
        if(prev==next)
        {
            maxL+=1;
            longest= max(maxL,longest);
        }else{
            maxL=1;
        }
    }
    cout<<longest;
 
 
}