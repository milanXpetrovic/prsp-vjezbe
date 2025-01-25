#include <iostream>
using namespace std;

int main() {
    //freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x;
    cin>>x;

    for (int i=0; i<x; i++) {
        int n, m, k, startX=1, startY=1, burles=0;
        cin>>n>>m>>k;

        while (startX != n) {
            startX++;
            burles += startY;
        }
        while (startY != m) {
            startY++;
            burles += startX;
        }

        if (burles==k)
            cout<<"YES";
        else
            cout<<"NO";
        cout<<endl;
    }
	return 0;
}