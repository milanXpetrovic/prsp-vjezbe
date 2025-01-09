#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(){
    //freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    for (int i=0; i<n; i++) {
        int m, sum=0;
        cin>>m;
        vector<int> candies(m);

        for (int j=0; j<m; j++) {
            cin>>candies[j];
            sum += candies[j];
        }

        if (sum % m)
            cout<<"-1";
        else {
                int counter=0;
                for (auto x : candies) {
                    if (x > sum/m) counter++;
                }
                cout<<counter;
            }
        cout<<endl;
    }
	return 0;
}