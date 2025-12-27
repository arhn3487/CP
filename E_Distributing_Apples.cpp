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
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

ll bin_exp(ll base, ll exp, ll mod=M) { 
    ll result = 1; 
    base %= mod; 
    while (exp > 0) { 
        if (exp & 1) result = (result * base) % mod; 
        base = (base * base) % mod; 
        exp >>= 1; 
    } 
    return result; 
} 

const int N=3e6;
ll fac[N];


ll ncr(ll n,ll r)
{
    ll den=fac[r]*fac[n-r];
    den=bin_exp(den,M-2);
    return fac[n]*den%M;
}

void solve()
{
    ll n,m,ans=0;
    cin>>n>>m;
    
    //if(n<m) m=n;
    ans= ncr(n+m-1,n-1);
    

    cout<<ans<<'\n';
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

    for(int i=2;i<N;i++) fac[i]=(fac[i-1]*i)%M;
    

    for(int i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<": ";
        solve();
    }
}