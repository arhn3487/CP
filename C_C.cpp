#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define debug(x...)
#endif
using namespace std;

#define ll long long
#define ld long double
#define int long long
const int M=1e9+7;
const int N=1e6+5;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

void solve()
{
    ll x,y;cin>>x>>y;
    pair<ll,ll> res,res1;

    for(int i=1;i*i<=y;i++)
    {
        if(y%i==0)
        {
            res=make_pair(i,y/i);
        }
    }
    debug(res);
    int mx=2*(res.first/2);
    debug(mx);

    if(x<=mx)
    {
        cout<<res.first<<' '<<res.second<<'\n';
        ll a=min(x/2,x-x/2),b=max(x/2,x-x/2);
        cout<<a<<' '<<b<<'\n';
        return;
    }

    int mn=2*(res.second+1);
    if(x<mn)
    {
        cout<<-1<<'\n';
        return;
    }

    if(res.first>2*x-1)
    {
        ll a=min(2*res.second+1,x-2*res.second-1),b=max(2*res.second+1,x-2*res.second-1);
        cout<<a<<' '<<b<<'\n';
        return;
    }

    // cout<<res.first<<' '<<res.second<<'\n';
    // cout<<res1.first<<' '<<res1.second<<'\n';

    // debug(res1,res);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    cin>>t;

    for(int i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<": ";
        solve();
    }
}