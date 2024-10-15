#include <iostream>
#include <vector>
#include <limits.h>
// #include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    vector<int> numbers;
    while (cin >> n) {
        numbers.push_back(n);
    }

    int zbroj = INT_MIN;
    for (int i=0; i<numbers.size(); i++) {
        int temp = 0;

        for (int j=i; j<numbers.size(); j++) {
            temp += numbers[j];

            if (temp > zbroj) {
                zbroj = temp;
            }
        }
    }

    cout<<zbroj;
    return 0;
}
