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

const int N=1e6+7;
ll fib[N];

ll bin_exp(ll base,ll pow)
{
    ll res=1;base%=M;
    while(pow)
    {
        if(pow&1LL) res=(res*base)%M;
        base=(base*base)%M;
        pow=pow>>1;
    }

    return res;
}

void solve()
{
    ll n,den;cin>>n;
    if(n&1LL){
        print(0)
        return;
    }
    n/=2;
    den=(fib[n]*fib[n])%M;
    den=bin_exp(den,M-2);
    ll den2=(fib[n-1]*fib[n+1])%M;
    //den2=bin_exp(den2,M-2);
    den2=bin_exp(den2,M-2);
    ll res=((fib[2*n]*den)%M-(fib[2*n]*den2)%M+M)%M;
    print(res)
    debug(den,den2);
}




int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fib[0]=1;fib[1]=1;
    for(int i=2;i<N;i++) fib[i]=(fib[i-1]*i)%M;
    for(int i=0;i<10;i++) cerr<<fib[i]<<' ';
    cerr<<'\n';

    int t=1;
    //cin>>t;

    for(int i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<": ";
        solve();
    }
}