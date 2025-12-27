#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,a,total=0;
    cin>>n;
    map<ll,ll> mp;

    for(ll i=0;i<n;i++)
    {
        cin>>a;
        mp[a]++;
    }

    ll mx= mp.rbegin()->first-mp.begin()->first,t;

    /*for(auto num : mp)
    {
        ll need=mx+num.first;
        if(mp.count(need))
        {
            total+=min(mp[need],num.second);
            4 4 4 4
        }
    }*/
    t=mp.begin()->second;
    if(mp.size()==1) cout<<0<<" "<<t*(t-1)/2<<endl;
    else cout<<mx<<" "<<mp.rbegin()->second*mp.begin()->second<<endl; 
}