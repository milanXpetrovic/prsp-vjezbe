// alias gpp='g++ -o ./solution'
// alias gpp='g++ -o ./solution solution.cpp'

#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <climits>
#include <string>

using namespace std;

typedef long long ll;

int main()
{
    // freopen("ulaz.txt", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    
    // Rjesenje zadatka
    
    string dna;
    int maxSum = INT_MIN;

    cin >> dna;

    int n = dna.length();
    char tempChar = dna[0];
    int tempSum = 1;
    if(dna.length() > 1)
    {
        for(int i = 1; i < n; i++)
        {
            if(dna[i] == tempChar)
            {
                tempSum++;
            }
            else
            {
                tempSum = 1;
                tempChar = dna[i];
            }
            if(tempSum > maxSum) maxSum = tempSum;
        }
    }
    else
    {
        maxSum = 1;
    }
    cout << maxSum << endl;
}
