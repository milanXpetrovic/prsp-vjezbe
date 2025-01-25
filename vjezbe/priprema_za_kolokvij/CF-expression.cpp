#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    //freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b,c;
    cin>>a>>b>>c;

    int result1 = a+b*c;
    int result2 = a*(b+c);
    int result3 = a*b*c;
    int result4 = (a+b)*c;
    int result5 = a+b+c;

    cout << max({result1, result2, result3, result4, result5});
    return 0;
}