// alias gpp='g++ -o ./solution'
// alias gpp='g++ -o ./solution solution.cpp'

#include <iostream>
#include <unordered_map>
// #include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    //freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    unordered_map<char, string>konverzija = {
        {'A',"00"},
        {'B',"01"},
        {'C',"10"},
        {'D',"11"}
    };

    string input;
    cin>>input;
    string output="";

    for(auto c:input){
        output += konverzija[c];
    }
    cout<<output;
    return 0;
}