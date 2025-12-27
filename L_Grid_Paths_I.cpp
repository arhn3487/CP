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
//#define int long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

char grid[1005][1005];
vector<vector<int>> dp(1005,vector<int>(1005,-1));
int n;

int rec(int i,int j)
{
    if(dp[i][j]!=-1) return dp[i][j];
    if(i==n-1 && j==n-1) return dp[i][j]=1;
    if(i==n || j==n) return 0;

    int a=(i+1<n && grid[i+1][j]!='*') ? rec(i+1,j) : 0;
    int b=(j+1<n && grid[i][j+1]!='*') ? rec(i,j+1) : 0;
    return dp[i][j]=(a+b)%M;
    
}

void solve()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>grid[i][j];
        }
    }

    if(grid[0][0]=='*')
    {
        print(0)
        return;
    }

    cout<<rec(0,0)<<'\n';
}

int32_t main()
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