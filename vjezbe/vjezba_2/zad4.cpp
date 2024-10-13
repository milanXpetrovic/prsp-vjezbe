#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <cstdlib>
#include <random>   


using namespace std;

typedef long long ll;

int main(){
    freopen("ulaz2.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    random_device rand; 
    mt19937 gen(rand()); 
    uniform_int_distribution<> distr(-10, 10); 

    cout << "Random numbers: ";
        for (int i = 0; i < n; ++i) {
        cout << distr(gen) << " "; 
    }

    cout << endl;
    
    return 0;

}