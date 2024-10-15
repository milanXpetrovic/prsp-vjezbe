#include <iostream>
// #include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Rjesenje zadatka
    int x;
    cin >> x;
 
    for (int i=0; i<x; i++) {
        string word;
        cin >> word;
 
        if (word.length() > 10)
            cout<< word[0] << word.length()-2 << word[word.length()-1] <<endl;
        else
            cout <<word <<endl;
    }
 
	return 0;
}
