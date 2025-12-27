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
vector<vector<int>> comp,dp;

int cal(int men,int women)
{
    if(men>=n) return 1;
    if(~dp[men][women]) return dp[men][women];

    int res=0;

    for(int i=0;i<n;i++)
        if(((women>>i) & 1)==0 && comp[men][i])
            res=(res+cal(men+1,women | 1<<i))%M;
    
    return dp[men][women]=res;
}

void solve()
{
    cin>>n;
    comp.resize(n,vector<int>(n));
    dp.assign(n,vector<int>(1<<n,-1));

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>comp[i][j];

    cout<<cal(0,0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    ///cin>>t;

    for(int i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<": ";
        solve();
    }
}