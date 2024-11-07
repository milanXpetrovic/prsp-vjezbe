#include <iostream>
#include <vector>

using namespace std;

int fib(int a){
    if(a<1) return -1;
    if(a==1 || a==2)  return 1;

    return fib(a-2)+fib(a-1);
}


int fib_din_v1(int a){
    vector<int> fib_numbers;

    for(int i = 0; i<a;i++){
        if(i==0 || i==1)  fib_numbers.push_back(1);
        else fib_numbers.push_back(fib_numbers[i-2]+fib_numbers[i-1]);
    }
    return fib_numbers[a-1];
}

int fib_din_v2(int a){
    int x=0;
    int y=1;
    int z;
    for(int i = 1;i<a;i++){
        z= x+y;
        x = y;
        y=z;
    }
    return z;
}
int main()
{
    int a;
    cin>>a;
    cout<<fib(a)<<endl;
    cout<<fib_din_v1(a)<<endl;
    cout<<fib_din_v2(a)<<endl;
    return 0;
}
