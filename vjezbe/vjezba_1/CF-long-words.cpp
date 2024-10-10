#include <iostream>
// #include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Rjesenje zadatka

}
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n; 
    
    vector<string> words(n);  
    
    for (int i = 0; i < n; i++) {
        cin >> words[i];  
    }
    
    for (int i = 0; i < n; i++) {
        if (words[i].length() > 10) {
            cout << words[i][0] << words[i].length() - 2 << words[i][words[i].length() - 1] << endl;
        } else {
           
            cout << words[i] << endl;
        }
    }
    
    return 0;
}
