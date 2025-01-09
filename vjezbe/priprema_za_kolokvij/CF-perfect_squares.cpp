#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int main() {
    //freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, y, maxNotPerfSquare=INT_MIN;
    cin>>x;

    for (int i=0; i<x; i++) {
        cin>>y;
        int numb = int(sqrt(y));

        if (numb*numb != y) {
            if (y > maxNotPerfSquare)
                maxNotPerfSquare = y;
        }
    }

    cout<<maxNotPerfSquare;
    return 0;
}