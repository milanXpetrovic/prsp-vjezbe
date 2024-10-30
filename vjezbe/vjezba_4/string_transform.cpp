// alias gpp='g++ -o ./solution'
// alias gpp='g++ -o ./solution solution.cpp'

#include <iostream>
// #include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    freopen("ulaz_string.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin>>s;
    //aacceeggiikkmmooqqssuuwwyy
    string needed = "abcdefghijklmnopqrstuvwxyz";
    char current = 'a';  

    for (int i = 0; i < s.length(); i++) {
        if (s[i] <= current) {
            s[i] = current;
            current++;
        }
        if (current > 'z') {
            break;
        }
    }
    if (current > 'z') {
        cout << s << endl;
    } else {
        cout << "-1" << endl;  
    }

}