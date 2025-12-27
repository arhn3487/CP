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
        ll n,flag=0;
        cin>>n;
        vector<ll> v(n);

        for(ll i=0;i<n;i++) cin>>v[i];
        sort(v.begin(),v.end());

        ll f=v[0],s=v[0];

        for(ll i=1;i<n;i++)
        {
            if(v[i]%f!=0)
            {
                s=v[i];
                break;
            }
        }

        for(ll i=0;i<n;i++)
        {
            if(v[i]%f!=0 && v[i]%s!=0) 
            {
                flag=1;
            }
        }

        if(flag) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
}