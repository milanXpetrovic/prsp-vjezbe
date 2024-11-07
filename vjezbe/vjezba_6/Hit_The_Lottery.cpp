    #include <iostream>
     
    using namespace std;
    int counter=0;
    int money(int m)
    {
        long long int n=m;
        if(n<=0){return counter;}
        else if(n>=100){counter+=(n/100);money(n%100);}
        else if(n>=20 && n<100){counter++;money(n-20);}
        else if(n>=10 && n<20){counter++;money(n-10);}
        else if(n>=5 && n<10){counter++;money(n-5);}
        else if(n>=1 && n<5){counter++;money(n-1);}
     
    }
    int main()
    {
        int n;
        cin>>n;
        cout<<money(n);
        return 0;
    }
