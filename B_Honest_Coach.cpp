#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,mn=INT_MAX;
        cin>>n;

        int arr[n];

        for(int i=0;i<n;i++) cin>>arr[i];

        sort(arr,arr+n);

        for(int i=0;i<n-1;i++)
        {
            int j=i+1;
            mn=min(abs(arr[i]-arr[j]),mn);
        }

        cout<<mn<<endl;
    }
}