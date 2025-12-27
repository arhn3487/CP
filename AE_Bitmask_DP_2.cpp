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

int n;

int rec(int ind,int taken,vector<vector<int>> &v,vector<int> &dp)
{
    if(ind==n) return 0;
    if(~dp[taken]) return dp[taken];

    int res=0;

    for(int i=0;i<n;i++)
    {
        if(!(taken>>i & 1))
            res=max(res,v[ind][i]+rec(ind+1,taken|1<<i,v,dp));
    }

    return dp[taken]=res%M;
}

void solve()
{
    cin>>n;
    vector<vector<int>> v(n,vector<int>(n));
    vector<int> dp(1<<n,-1);

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>v[i][j];
    
    cout<<rec(0,0,v,dp)<<'\n';
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
        cout<<"Case "<<i<<": ";
        solve();
    }
}