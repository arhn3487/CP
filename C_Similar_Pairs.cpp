#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,even=0,odd=0,flag=0;
        cin>>n;

        int arr[n];

        for(int i=0;i<n;i++) 
        {
            cin>>arr[i];
            if(arr[i]%2) odd++;
            else even++;
        }

        if(!(odd%2))
        {
            cout<<"YES"<<endl;
            continue;;
        }
        
        sort(arr,arr+n);

        for(int i=0;i<n-1;i++)
        {
            if(abs(arr[i]-arr[i+1])==1) flag=1;
        }

        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}