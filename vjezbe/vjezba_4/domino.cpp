// alias gpp='g++ -o ./solution'
// alias gpp='g++ -o ./solution solution.cpp'

#include <iostream>
// #include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    //freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin>> n>>m;

    int povrsina = n*m;
    cout<<povrsina/2;
    return 0;
}