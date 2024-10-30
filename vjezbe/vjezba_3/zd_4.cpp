#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    string s;
    cin >> s;

    sort(s.begin(), s.end());

    set<string> unique_permutations;

    do {
        unique_permutations.insert(s);
    } while (next_permutation(s.begin(), s.end()));

    cout << unique_permutations.size() << endl;

    for (const auto& perm : unique_permutations) {
        cout << perm << endl;
    }

    return 0;
}
