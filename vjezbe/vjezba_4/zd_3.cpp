// alias gpp='g++ -o ./solution'
// alias gpp='g++ -o ./solution solution.cpp'

#include <iostream>
#include <vector>
#include <algorithm>
// #include <bits/stdc++.h>

using namespace std;

typedef long long ll;


struct Aktivnost{
    int pocetak, kraj;
};

bool compare(const Aktivnost &a, const Aktivnost &b) {
    return a.kraj < b.kraj;
}

int main(){
    freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
  
    int n;
    cin>>n;
    vector<Aktivnost> aktivnosti(n);

    for(int i=0;i<n;i++){
        cin>>aktivnosti[i].pocetak>>aktivnosti[i].kraj;
    }

    sort(aktivnosti.begin(),aktivnosti.end(),compare);

    vector<Aktivnost> odabrane_aktivnosti;

    odabrane_aktivnosti.push_back(aktivnosti[0]);
    int zadnjaZavrsena = odabrane_aktivnosti[0].kraj;

    for(int i =1;i<n;i++){
        if(aktivnosti[i].pocetak >=zadnjaZavrsena){
            odabrane_aktivnosti.push_back(aktivnosti[i]);
            zadnjaZavrsena = aktivnosti[i].kraj;
        }
    }

    for(const auto &aktivnosti: odabrane_aktivnosti){
        cout<<aktivnosti.pocetak << " "<< aktivnosti.kraj<< endl;

    }
    return 0;
}   