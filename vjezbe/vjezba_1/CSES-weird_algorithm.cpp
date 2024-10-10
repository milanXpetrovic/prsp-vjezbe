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
using namespace std;
int main() {
    long long n;
    cin>>n;
    while(n>0){
        if(n==1){
            cout<<n<<"";
            break;
        }
        if(n%2!=0){
             cout<<n<<" ";
             n=n*3+1;
        }
        else{
            cout<<n<<" ";
            n=n/2;
        }
    }
}
