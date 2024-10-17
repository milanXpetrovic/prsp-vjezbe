#include<iostream>
using namespace std;
typedef long long ll;

int main()
{
    // freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i=0; i<t; i++) {
        int n, sumM=0, sumB=0;
        cin >> n;

        for (int j=0; j<n; j++) {
            int a;
            cin >> a;

            if (!(a % 2))
                sumM += a;
            else
                sumB += a;
        }

        if (sumM > sumB)
            cout<<"YES";
        else
            cout<<"NO";
        cout<<endl;
    }

    return 0;
}
