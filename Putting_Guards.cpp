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
    int n,m,ans=0;cin>>n>>m;
    vector<vector<int>> grid(n+10,vector<int>(m+10,0));

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char ch;cin>>ch;
            grid[i][j]=ch-'0';
        }
    }

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            int cnt=0;

            if(grid[i][j]==1) cnt++;
            if(grid[i][j+1]==1) cnt++;
            if(grid[i+1][j]==1) cnt++;
            if(grid[i+1][j+1]==1) cnt++;

            if(cnt==1 || cnt==3 || (cnt==2 && ((grid[i][j]==1 && grid[i+1][j+1]==1) || (grid[i][j+1]==1 && grid[i+1][j]==1)))) ans++;
        }
    }

    print(ans)
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