#include <iostream>
#include<set>
using namespace std;

int main()
{
    int n;
    string yes="I become the guy.";
    string no="Oh, my keyboard!";
    cin>>n;
    int a;
    cin>>a;
    set<int> players;
    for(int i=0; i<a; i++)
    {
        int temp;
        cin>>temp;
        players.emplace(temp);

    }
    cin>>a;
    for(int i=0; i<a; i++)
    {
        int temp;
        cin>>temp;
        players.emplace(temp);
    }
    if(players.size()<n)
    {
        cout<<no;
    }
    else
    {
        cout<<yes;
    }
    return 0;
}
