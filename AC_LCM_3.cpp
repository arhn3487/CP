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
        ll n;
        cin>>n;
        vector<ll> v(n+1);

        for(ll i=1;i<=n;i++) v[i]=i;
        
        
        for(ll i=1,j=2;i<=n && j<=n;i+=2,j+=2)
        {
            swap(v[i],v[j]);
        }
        if(n%2) swap(v[1],v[n]);
        for(int i=1;i<=n;i++) cout<<v[i]<<" ";
        cout<<endl;
    }
}