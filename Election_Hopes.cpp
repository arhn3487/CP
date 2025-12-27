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
        ll n,a,b,mx=0;
        cin>>n;
        //set<ll> s,v;
        vector<pair<ll,ll>> v;

        for(ll i=0;i<n;i++)
        {
            cin>>a>>b;
            v.push_back({a,b});
        }

        for(ll i=0;i<n-1;i++)
        {
            pair<ll,ll> p=v[i];
            for(int j=i+1;j<n;j++)
            {
                pair<ll,ll> q=v[j];
                mx=max(mx,p.first*q.second+p.second*q.first);
            }
        }

        cout<<mx<<endl;
    }
}