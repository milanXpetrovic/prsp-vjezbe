#include <iostream>
// #include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        int randNum = -9 + (rand() % (9+9+1));   // (9-(-9)+1)
        cout <<randNum <<" ";
    }

    return 0;
}
