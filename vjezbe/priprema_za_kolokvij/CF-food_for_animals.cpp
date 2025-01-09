#include <iostream>
#include <vector>
using namespace std;

int main() {
    //freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x;
    cin>>x;

    for (int i=0; i<x; i++) {
        vector<int> testCase(5);

        for (int j=0; j<5; j++) {
            cin>>testCase[j];
        }

        int xtraDogFood = max(0, testCase[3]-testCase[0]);
        int xtraCatFood = max(0, testCase[4]-testCase[1]);

        if (xtraDogFood + xtraCatFood > testCase[2])
            cout<<"NO";
        else
            cout<<"YES";
        cout<<endl;
    }
	return 0;
}