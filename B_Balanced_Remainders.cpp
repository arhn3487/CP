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
        ll n,a;
        cin>>n;
        map<ll,ll> mp;
        vector<ll> v(n);

        for(ll i=0;i<n;i++)
        {
            cin>>a;
            mp[a%3]++;
        }
        
        for(auto m : mp)
        {
            cout<<m.first<<" "<<m.second<<endl;
        }

        ll res=abs(mp[0]-n/3)+abs(mp[1]-n/3)+abs(mp[2]-n/3)-1;
        if(res!=-1)cout<<res<<endl;
        else cout<<0<<endl;
    }
}