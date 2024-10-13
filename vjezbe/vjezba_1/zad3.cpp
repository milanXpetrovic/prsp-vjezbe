// CF - way too long 
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
    

    return 0;
}