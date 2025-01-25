#include <iostream>
#include <vector>
using namespace std;

int main() {
    //freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, y;

    cin>>x;
    vector<int> pedal(x);
    for (int i=0; i<x; i++) {
        cin>>pedal[i];
    }

    cin>>y;
    vector<int> rearWheel(y);
    for (int i=0; i<y; i++) {
        cin>>rearWheel[i];
    }

    int maxRatio=0, counter;
    for (int i=0; i<y; i++) {
        for (int j=0; j<x; j++) {
            int omjer = rearWheel[i] / pedal[j];

            if (pedal[j] * omjer == rearWheel[i]) {
                if (omjer > maxRatio) {
                    maxRatio = omjer;
                    counter=1;
                }
                else if (omjer == maxRatio)
                    counter++;
            }
        }
    }

    cout<<counter;
    return 0;
}