#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        ll n,s=0;
        cin>>n;
        
        ll arr[n];

        for(int i=0;i<n;i++) 
        {
            cin>>arr[i];
            if(i<n-1) s=max(s,arr[i]);
        }

        s+=arr[n-1];

        cout<<s<<endl;
    }
}