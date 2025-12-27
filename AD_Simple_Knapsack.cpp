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
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");



void solve()
{
    int n,wt;
    cin>>n>>wt;
    ll v[n],w[n];
    vector<vector<ll>> dp(n+1,vector<ll>(wt+1,0));
    for(int i=0;i<n;i++)
    {
        cin>>w[i]>>v[i];
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=wt;j++)
        {
            if(w[i-1]>j)dp[i][j]= dp[i-1][j];
            else dp[i][j]=max(dp[i-1][j],v[i-1]+dp[i-1][j-w[i-1]]);
        }
    }

    cout<<dp[n][wt];

    //cout<<knapsack(0,wt,dp);
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
