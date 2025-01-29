#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> get_subsets_sums(const vector<ll>& arr) {
    int n = arr.size();
    vector<ll> sums;
    for (int i = 0; i < (1 << n); i++) {
        ll sum = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) sum += arr[j];
        }
        sums.push_back(sum);
    }
    return sums;
}

ll meet_in_the_middle(int n, ll x, const vector<ll>& arr) {
    vector<ll> left_half(arr.begin(), arr.begin() + n / 2);
    vector<ll> right_half(arr.begin() + n / 2, arr.end());

    vector<ll> left_sums = get_subsets_sums(left_half);
    vector<ll> right_sums = get_subsets_sums(right_half);

    sort(right_sums.begin(), right_sums.end());

    ll count = 0;
    for (ll s : left_sums) {
        auto lo = lower_bound(right_sums.begin(), right_sums.end(), x - s);
        auto hi = upper_bound(right_sums.begin(), right_sums.end(), x - s);
        count += (hi - lo); 
    }

    return count;
}

int main() {
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << meet_in_the_middle(n, x, arr) << endl;
    return 0;
}
