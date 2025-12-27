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
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

ll sum(ll l, ll r)
{
    l %= M; r %= M;
    ll a = r * (r + 1) / 2 % M;
    ll b = l * (l - 1) / 2 % M;
    return (a - b + M) % M;
}

void solve()
{
    ll n,m,ans=0;
    cin>>n>>m;
    n%=M;
    m%=M;
    ans=(n*m)%M;
    ll l = 1;
while (l <= min(n,m))
{
    ll q = n / l;
    ll r = n / q;
    r = min(r, m);

    ans -= q * (sum(l, r) % M);
    ans %= M;

    l = r + 1;
}


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
