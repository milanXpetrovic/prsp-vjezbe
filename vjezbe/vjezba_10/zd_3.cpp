#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> mp;
string mp2[100005];
int k = 0, n;

void generateSequences(string s) {
    if (s.size() == n - 1) {
        mp[s] = ++k;
        mp2[k] = s;
        return;
    }
    generateSequences(s + '0');
    generateSequences(s + '1');
}

void solve() {
    cin >> n;
    
    if (n == 1) {
        cout << "01" << endl;
        return;
    }

    generateSequences("");

    int t = (1 << (n - 1));  // (2^(n-1))
    vector<pair<int, char>> adj[100005];

    for (int i = 1; i <= t; ++i) {
        string x = mp2[i].substr(1, n - 2);
        adj[i].push_back({mp[x + "0"], '0'});
        adj[i].push_back({mp[x + "1"], '1'});
    }

    string path;
    stack<pair<int, char>> st;
    st.push({1, '#'});

    while (!st.empty()) {
        auto [i, c] = st.top();
        if (adj[i].empty()) {
            if (c != '#') path += c;
            st.pop();
        } else {
            auto [j, c2] = adj[i].back();
            adj[i].pop_back();
            st.push({j, c2});
        }
    }

    path += mp2[1];
    cout << path << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    return 0;
}
