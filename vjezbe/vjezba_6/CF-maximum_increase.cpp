#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findLargestSubarray(vector<int> elements, int arraySize) {
    int maxSize = 1, currentSize = 1;

    for (int i=1; i<arraySize; i++) {
        if (elements[i-1] < elements[i]) {
            currentSize++;
        } else {
            currentSize = 1;
        }

        maxSize = max(currentSize, maxSize);
    }

    return maxSize;
}

int main(){
    //freopen("ulaz3.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Rjesenje zadatka
    int x, y;
    vector<int> elements;
    cin>>x;

    for (int i=0; i<x; i++) {
        cin>>y;
        elements.push_back(y);
    }

    cout<<findLargestSubarray(elements, x);
    return 0;
}