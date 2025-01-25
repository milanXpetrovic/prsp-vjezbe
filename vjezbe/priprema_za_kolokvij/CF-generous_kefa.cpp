#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int x, y;
    cin>>x>>y;

    string balloons;
    cin>>balloons;

    sort(balloons.begin(), balloons.end());

    int counter=1;
    for (int i=1; i<x; i++) {
        if (balloons[i-1] == balloons[i])
            counter++;
        else
            counter=1;

        if (counter > y) {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";

    return 0;
}