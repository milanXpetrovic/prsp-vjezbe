#include <iostream>
#include <vector>
using namespace std;

int main(){
    //freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x;
    cin>>x;

    for (int i=0; i<x; i++) {
        int n;
        cin>>n;
        vector<int> cake(n);
        vector<int> drenched(n, 0);

        for (int j=0; j<n; j++) {
            cin>>cake[j];
        }

        int remainingCream = 0;
        for (int j=n-1; j>=0; j--) {
            remainingCream = max(remainingCream, cake[j]);

            if (remainingCream) {
                drenched[j] = 1;
                remainingCream--;
            }
        }

        for (auto x : drenched) {
            cout<<x<<" ";
        }
        cout<<endl;
    }
	return 0;
}