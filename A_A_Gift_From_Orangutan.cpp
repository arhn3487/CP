#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        ll n,mx=INT_MIN,mn=INT_MAX;
        cin>>n;

        vector<ll> v(n);

        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            mx=max(mx,v[i]);
            mn=min(mn,v[i]);
        }

        cout<<(n-1)*(mx-mn)<<endl;
    }
}