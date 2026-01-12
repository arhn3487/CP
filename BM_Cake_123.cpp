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
    ll x,y,z,k;cin>>x>>y>>z>>k;
    vector<ll> a(x),b(y),c(z),v(x*y),res;

    for(auto &i : a) cin>>i;
    for(auto &i : b) cin>>i;
    for(auto &i : c) cin>>i;

    // if(x>z)
    // {
    //     swap(x,z);
    //     swap(a,c);
    // }
    // if(y>z)
    // {
    //     swap(y,z);
    //     swap(b,c);
    // }

    int id=0;

    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            v[id++]=a[i]+b[j];
        }
    }

    sort(rall(v));
    debug(v);
    if(v.size()>k) v.resize(k);

    for(int i=0;i<v.size();i++)
    {
        for(auto xx : c) res.push_back(xx+v[i]);
    }
    debug(res);
    sort(rall(res));

    id=0;

    while(k--)
    {
        cout<<res[id]<<'\n';
        id++;
    }
    
}

int32_t main()
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