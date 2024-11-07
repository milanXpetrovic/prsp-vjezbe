#include <iostream>
#include <vector>

using namespace std;

int countWays(int x) {
    if (x==1 || x==2)
        return x;

    int a=1, b=2, c;

    for (int i=3; i<=x; i++) {
        c = a+b;
        a = b;
        b = c;
    }

    return c;
}

int main(){
    // freopen("ulaz3.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Rjesenje zadatka
    int x;
    cin>>x;

    cout<<countWays(x);
    return 0;
}
