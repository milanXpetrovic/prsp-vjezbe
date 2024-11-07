#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMinPrice(vector<int> cijena) {
    int n = cijena.size();
    vector<int> dp(n+1, 0);

    for (int i=2; i<=n; i++) {
        dp[i] = min(dp[i-1] + cijena[i-1], dp[i-2] + cijena[i-2]);
    }

    return dp[n];
}

int main(){
    freopen("ulaz3.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Rjesenje zadatka
    vector<int> cijena;
    int x;

    while (cin>>x) {
        cijena.push_back(x);
    }

    cout<<findMinPrice(cijena);
    return 0;
}
