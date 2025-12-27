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
int dx[]={1,0,-1,0,1,1,-1,-1};
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

ll bin_exp(ll base, ll exp) { 
    ll result = 1; 
    //base %= mod; 
    while (exp > 0) { 
        if (exp & 1) result = (result * base); 
        base = (base * base); 
        exp >>= 1; 
    } 
    return result; 
} 

ll deal_cost(ll x) {
    if (x == 0) return 3; 
    return bin_exp(3,x+1)+1LL*x*bin_exp(3, x-1);
}

void solve()
{
    ll n;cin>>n;
    ll cost = 0;
    ll x = 0;
    while (n > 0) {
        ll d=n%3 ;            
        if (d) cost+=d*deal_cost(x);
        n/=3;
        x++;
    }
    cout<<cost<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    cin>>t;

    for(int i=1;i<=t;i++)
    {
        solve();
    }
}
