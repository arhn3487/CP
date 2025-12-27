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
ll fact[N];

ll bin_exp (ll a, ll b, ll c=M) { 
    ll res = 1; 
    while (b > 0) { 
        if (b % 2 == 1) { 
            res = (res * a) % c; // If b is odd, multiply res by a 
        } 
        a = (a * a) % c; // Square a 
        b /= 2; // Divide b by 2 
    } 
    return res; 
}

void solve()
{
    ll a,b;cin>>a>>b;
    //a++,b++;
    ll den=fact[b]*fact[a-b];
    den=den%M;
    ll ans=fact[a]*bin_exp(den,M-2);
    ans%=M;

    //debug(den,fact[b],fact[a-b]);
    cout<<ans<<'\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fact[0]=1;
    fact[1]=1;

    for(int i=2;i<N;i++) fact[i]=(fact[i-1]*i)%M;

    // for(int i=0;i<10;i++) cerr<<fact[i]<<' ';
    // cerr<<'\n';

    int t=1;
    cin>>t;

    for(int i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<": ";
        solve();
    }
}