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
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

void solve()
{
    ll n,mx=0;
    cin>>n;
    vector<ll> v(n);

    for(ll i=0;i<n;i++) cin>>v[i];

    for(ll i=0;i<n;i++)
    {
        ll left=0,right=0;
        if(i==1) left=v[0];
        if(i==n-2) right=v[n-1];
        mx=max(mx, v[i] - (left + right));
    }

    prll(mx)
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