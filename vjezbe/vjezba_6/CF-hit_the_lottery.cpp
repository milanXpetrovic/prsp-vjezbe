#include <iostream>
#include <vector>
using namespace std;

int main(){
    // freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> bills = {100, 20, 10, 5, 1};
    int am, counter=0;
    cin>>am;

    while (am - 100 >= 0 && am) {counter++; am -= 100;}
    while (am - 20 >= 0 && am) {counter++; am -= 20;}
    while (am - 10 >= 0 && am) {counter++; am -= 10;}
    while (am - 5 >= 0 && am) {counter++; am -= 5;}
    while (am - 1 >= 0 && am) {counter++; am -= 1;}

    cout<<counter;

    return 0;
}