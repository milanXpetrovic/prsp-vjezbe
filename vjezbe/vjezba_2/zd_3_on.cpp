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
    int temp = 0;
    for (int i=0; i<numbers.size(); i++) {
        temp += numbers[i];

        if (temp > zbroj)
            zbroj = temp;

        if (temp < 0)
            temp = 0;
    }

    cout<<zbroj;
    return 0;
}
