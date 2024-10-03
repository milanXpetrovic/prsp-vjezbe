#include <iostream>
#include <string>
using namespace std;

int main()
{

    int n;
    cin >> n;
    string words[n];
    for(int i =0;i<n;i++){
        cin>>words[i];}

    for(int i =0; i<n;i++){
        if(words[i].length()>10){
            int duzina = words[i].length();
            string ispis = words[i][0]+to_string(duzina-2)+words[i][duzina-1];
            cout<<ispis<<endl;
        }else cout<<words[i]<<endl;}





//    int n;
//    cin >> n;
//
//    if(n>=1 && n<=100)
//    {
//        if(n%2==0&&n!=2)
//        {
//            cout <<"YES";
//        }
//        else cout<<"NO";
//    }
    //    long long n;
//    cin >> n;
//    while(n>0)
//    {
//        if(n==1){
//            cout<< n<<" ";
//            break;
//        }
//        if(n%2==0)
//        {
//            cout<<n<<" ";
//            n = n/2;
//        }
//        else
//        {
//            cout<<n<<" ";
//            n = (n*3)+1;
//        }
//    }

    return 0;
}
