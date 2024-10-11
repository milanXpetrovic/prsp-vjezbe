#include <iostream>
// #include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Rjesenje zadatka
    long long n;
    cin >> n;
 
    if(n % 2 == 0 && n != 2) cout << "YES";
    else cout << "NO";
}
