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

int n,m;
const int N=2e5+10;
vector<int> dp(N,0),pre(N,0);

int rec(int rem)
{
    if(rem==0) return 1;
    if(rem<0) return 0;
    if(dp[rem]!=-1) return dp[rem];

    int ans=0;

    for(int i=2;i<=rem;i++)
    {
        ans+=rec(rem-i);
    }
    ans%=100;
    return dp[rem]=ans;
}

void solve()
{
    int sum=1;
    dp[0]=1;
    pre[0]=1;
    pre[1]=1;
    for(int i=2;i<N;i++)
    {
        dp[i]+=pre[i-2];
        pre[i]=pre[i-1]+dp[i];
        pre[i]%=100;
    }
    cin>>n>>m;
    //debug(dp[3],dp[4]);
    cout<<dp[n+m]<<'\n';
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