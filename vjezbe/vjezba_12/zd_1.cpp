#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int trie[1000005][26];
bool isEnd[1000005];
int dp[5005];
int trieNodeCount = 0;

void insertWord(const string& word) {
    int node = 0;
    for (char ch : word) {
        int idx = ch - 'a';
        if (!trie[node][idx]) {
            trie[node][idx] = ++trieNodeCount;
        }
        node = trie[node][idx];
    }
    isEnd[node] = true;
}

int searchFrom(int x, const string& s) {
    int node = 0, result = 0;
    for (int i = x; i < s.size(); i++) {
        int idx = s[i] - 'a';
        if (!trie[node][idx]) return result;
        node = trie[node][idx];
        if (isEnd[node]) {
            result = (result + dp[i + 1]) % MOD;
        }
    }
    return result;
}

void solve() {
    string s;
    int k;
    cin >> s >> k;

    for (int i = 0; i < k; i++) {
        string word;
        cin >> word;
        insertWord(word);
    }

    dp[s.size()] = 1;
    for (int i = s.size() - 1; i >= 0; i--) {
        dp[i] = searchFrom(i, s);
    }

    cout << dp[0] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
