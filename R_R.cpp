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
#define yes(x) cout << ((x) ? "Yes\n" : "No\n");

const int N=2e5+3;

ll inv_mod[N+1],fact[N+1];

ll mod_pow(ll a,ll b)
{
    ll res=1;

    while(b)
    {
        if(b&1) res=(res*a)%M;
        a=a*a%M;
        b/=2;
    }

    return res;
}

void solve()
{
    int w,h;cin>>w>>h;
    ll n=w+h-2,r=w-1;
    cout<<(fact[n]*inv_mod[r])%M*inv_mod[n-r]%M<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    //cin>>t;

    /*fact[0]=1,fact[1]=1;*/

    for(int i=2;i<=N;i++) fact[i]=fact[i-1]*i%M;

    inv_mod[N]=mod_pow(fact[N],M-2);

    for(int i=N-1;i>=0;i--) inv_mod[i]=(i+1)*inv_mod[i+1]%M;

    for(int i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<": ";
        solve();
    }
}