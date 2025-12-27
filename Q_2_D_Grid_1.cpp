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

int n,m;
vector<vector<ll>> dp;
vector<string> v;

ll rec(int i,int j)
{
    //cerr<<"ARAFAT "<<i<<" "<<j<<'\n';
    if(i==n-1 && j==m-1) return 1;
    if(i>=n || j>=m) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    ll sum=0;
    if(j+1<m && v[i][j+1]!='#') sum=(sum+rec(i,j+1))%M;
    if(i+1<n && v[i+1][j]!='#') sum=(sum+rec(i+1,j))%M;
    return dp[i][j]=sum;
}

void solve()
{
    cin>>n>>m;
    v.resize(n);
    dp.assign(n,vector<ll>(m,-1));

    for(auto &x : v) cin>>x;

    rec(0,0);

    cout<<dp[0][0]<<'\n';
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
