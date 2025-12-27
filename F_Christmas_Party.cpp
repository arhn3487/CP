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

ll fac[N],inv[N];

ll bin_exp(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1LL) ans=ans*a%M;
        a*=a;
        a%=M;
        b>>=1;
    }

    return ans;
}


void solve()
{
    ll n,s=1,ans=0;cin>>n;

    for(int i=0;i<=n;i++)
    {
        //ans+=inv[i]*s%M;
        ans = (ans + (inv[i] * s ) + M) % M;

        if(s==1) s=-1;
        else s=1;
    }

    

    cout<<ans*fac[n]%M;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    //cin>>t;

    fac[0]=1;
    fac[1]=1;

    for(int i=2;i<N;i++) fac[i]=fac[i-1]*i%M;
    inv[N-1]=bin_exp(fac[N-1],M-2);

    for(int i=N-2;i>=0;i--) inv[i]=(i+1)*inv[i+1]%M;

    for(int i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<": ";
        solve();
    }
}