#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define ll long long
const int M = 1e9 + 7;
const ll infinity = LLONG_MAX;
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1}; // Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[] = {0, -1, 0, 1, 1, -1, 1, -1};
inline ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }

#define rall(v) v.rbegin(), v.rend()
#define all(v) v.begin(), v.end()
#define print(x) cout << x << '\n';
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

int n,w;
vector<vector<ll>> dp;
vector<int> val,wt;

ll knapsack(int ind,int rem)
{
    if(ind>=n) return 0;
    if(dp[ind][rem]!=-1) return dp[ind][rem];
    ll not_take=knapsack(ind+1,rem);
    ll take=0;
    if(rem>=wt[ind]) take=val[ind]+knapsack(ind+1,rem-wt[ind]);
    return dp[ind][rem]=max(take,not_take);
}


void solve()
{
    cin>>n>>w;
    val.resize(n);
    wt.resize(n);

    dp.assign(n,vector<ll>(w+1,-1));

    for(int i=0;i<n;i++)
    {
        cin>>wt[i]>>val[i];
    }

    cout<<knapsack(0,w);
    ///print(ans);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    //cin >> t;

    for (int i = 1; i <= t; i++)
    {
        // cout<<"Case "<<i<<": ";
        solve();
    }
}