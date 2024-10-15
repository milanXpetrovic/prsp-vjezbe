#include <iostream>
#include <ctime>
// #include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i=0; i<3; i++) {
        time_t now1 = time(0);

        for (int j=0; j<n; j++) {
            int randNum = -9 + (rand() % (9+9+1)); // (9-(-9)+1)
        }

        time_t now2 = time(0);
        cout <<now2 - now1 <<endl;
    }

    return 0;
}
