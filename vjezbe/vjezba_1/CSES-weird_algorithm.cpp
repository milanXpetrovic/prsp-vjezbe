#include <iostream>
// #include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Rjesenje zadatka
    ll n;
    cin >> n;
 
    while (n != 1) {
        if (!(n%2)) {
            cout <<n <<" ";
            n /= 2;
        } else {
            cout <<n <<" ";
            n = n*3+1;
        }
    };
 
    if (n==1) {
        cout <<n;
    }

    return 0;
}
