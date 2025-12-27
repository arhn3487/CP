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
const int M=1e9+7;
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
    ll n,k,ans=0;
    cin>>n>>k;
    ll x=0;
    vector<ll> v(n);
    vector<int> o(45,0),z(45,0);

    for(int i=0;i<n;i++)
    {
        cin>>v[i];

        for(int j=0;j<=40;j++)
        {
            if((1LL<<j)&v[i]) o[j]++;
            else z[j]++;
        }

        // for(int i=0;i<3;i++) cout<<o[i]<<' ';
        // cout<<'\n';
        // for(int i=0;i<3;i++) cout<<z[i]<<' ';
        // cout<<'\n';
        // cout<<'\n';
    }

    // for(int i=0;i<3;i++) cout<<o[i]<<' ';
    // cout<<'\n';
    // for(int i=0;i<3;i++) cout<<z[i]<<' ';
    // cout<<'\n';

    for(int i=40;i>=0;i--)
    {
        if(o[i]<z[i])
        {
            if((x|(1LL<<i))<=k)
            x =(x|(1LL<<i));
        }
    }

    for(auto p : v) ans+=(p^x);

    cout<<ans<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    //cin>>t;

    for(int i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<": ";
        solve();
    }
}