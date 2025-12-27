#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        
        int arr[n+1];
        long long s=0;
        
        for(int i=0;i<=n;i++) cin>>arr[i];
        
        sort(arr,arr+n);

        // for(int i=0;i<=n;i++) cout<<arr[i]<<" ";
        // cout<<"\n";
        
        int swp=2*arr[n],mn=arr[n];
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]<=swp && arr[n]<arr[i])
            {
                swap(arr[i],arr[n]);
                swp=2*arr[n];
                //break;
            }
            // for(int i=0;i<=n;i++) cout<<arr[i]<<" ";
            // cout<<"\n";
        }

        // for(int i=0;i<=n;i++) cout<<arr[i]<<" ";
        // cout<<"\n";
        
        for(int i=0;i<n;i++) s+=arr[i];
        
        cout<<s<<endl;
    }
}
