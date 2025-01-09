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
 
    if (!(x%2) && x!=2)
        cout<<"YES";
    else
        cout<<"NO";
 
	return 0;
}
