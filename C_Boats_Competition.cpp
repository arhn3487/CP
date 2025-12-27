#include<bits/stdc++.h>
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
        ll n,a,res=0;
        cin>>n;
        map<ll,ll> mp;

        for(ll i = 0;i<n;i++)
        {
            cin>>a;
            mp[a]++;
        }

        for(ll w=2;w<=2*n;w++)
        {
            ll total=0;

            for(auto p : mp)
            {
                ll other = w-p.first;
                if(other>=1 && mp.count(other))
                {
                    total+=min(mp[other],p.second);
                }
            }
            res=max(res,total/2);
        }
        cout<<res<<endl;
    }
}