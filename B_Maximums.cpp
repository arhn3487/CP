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
const int MOD = 998244353;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

ll bin_exp (ll a, ll b, ll c) { 
    ll res = 1; 
    while (b > 0) { 
        if (b % 2 == 1) { 
            res = (res * a) % c; 
        } 
        a = (a * a) % c; 
        b /= 2; 
    } 
    return res; 
}

void solve()
{
    int n;cin>>n;
    vector<int> p(n),q(n);

    for(auto &x : p) cin>>x;
    for(auto &x : q) cin>>x;

    vector<ll> p2p(n),p2q(n);

    for(int i=0;i<n;i++)
    {
        p2p[i]=bin_exp(2,p[i],MOD);
        p2q[i]=bin_exp(2,q[i],MOD);
    }

    vector<ll> max_p(n), max_q(n);
    max_p[0] = p2p[0];
    for(int i=1;i<n;i++) {
        max_p[i] = max(max_p[i-1], p2p[i]);
    }
    max_q[0] = p2q[0];
    for(int i=1;i<n;i++) {
        max_q[i] = max(max_q[i-1], p2q[i]);
    }

    vector<ll> r(n);
    r[0] = (p2p[0] + p2q[0]) % MOD;
    for(int i=1;i<n;i++) {
        ll current_max = 0;
        for(int j=0;j<=i;j++) {
            current_max = max(current_max, (p2p[j] + p2q[i-j]) % MOD);
        }
        r[i] = current_max;
    }

    for(int i=0;i<n;i++) {
        cout << r[i] << " ";
    }
    cout << "\n";
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
        //cout<<"Case "<<i<<": ";
        solve();
    }
}