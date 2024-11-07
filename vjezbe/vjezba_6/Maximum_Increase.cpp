

    #include <iostream>
     
    using namespace std;
     
    int main()
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)cin>>arr[i];
     
        int crtMax=arr[0];
        int counter=1;
        int maxCounter=1;
     
        for(int i=1; i<n; i++)
        {
            crtMax=arr[i-1];
            if(crtMax<arr[i])counter++;
                else counter=1;
            if(counter>maxCounter)maxCounter=counter;
            //cout<<crtMax<<" "<<counter<<" ";
     
        }
        cout<<maxCounter;
     
        return 0;
    }
