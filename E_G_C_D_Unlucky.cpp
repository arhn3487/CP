#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define ll long long
const ll M=1e9+7;
const ll infinity = LLONG_MAX;
ll dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
ll dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define prll(x) cout<<x<<'\n';
#define yes(x) cout << ((x) ? "Yes\n" : "No\n");


void solve()
{
    ll n;cin>>n;
    vector<ll> a(n),s(n),p(n);

    for(auto &x : p) cin>>x;
    for(auto &x : s) cin>>x;

    for(ll i=0;i<n;i++) a[i]=lcm(s[i],p[i]);

    //cout<<a[0]<<'\n';

    ll g=a[0];

    for(ll i=0;i<n;i++)
    {
        g=__gcd(a[i],g);
        //cout<<g<<'\n';
        if(g!=p[i])
        {
            yes(0)
            return;
        }
    }

    g=a[n-1];

    for(ll i=n-1;i>=0;i--)
    {
        g=__gcd(g,a[i]);
        //cout<<g<<'\n';
        if(g!=s[i])
        {
            yes(0)
            return;
        }
    }

    yes(1)
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t=1;
    cin>>t;

    for(ll i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<": ";
        solve();
    }
}