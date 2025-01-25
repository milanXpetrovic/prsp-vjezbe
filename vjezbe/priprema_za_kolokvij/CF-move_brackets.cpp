#include <iostream>
using namespace std;

int main() {
    //freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, n;
    string parentheses;
    cin>>x;

    for (int i=0; i<x; i++) {
        cin>>n;
        cin>>parentheses;
        int counter = 0, balance = 0;

        for (char str : parentheses) {
            if (str == '(')
                balance++;
            else
                balance--;

            if (balance < 0) {
                counter++;
                balance=0;
            }
        }

        cout<<balance<<endl;
    }
    return 0;
}