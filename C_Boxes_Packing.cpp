#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,a,extra;
    cin>>n;
    map<ll,ll> mp;

    for(ll i=0;i<n;i++)
    {
        cin>>a;
        mp[a]++;
    }

    auto it = mp.begin();
    extra=it->second;
    it++;

    while(it!=mp.end())
    {
        if(extra<it->second) extra=it->second;
        it++;
    }

    cout<<extra<<endl;
}