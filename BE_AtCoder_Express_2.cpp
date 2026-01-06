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
#define int long long
const int M=1e9+7;
const int N=1e6+5;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

int pre[505][505],grid[505][505];

void solve()
{
    int n,m,q;cin>>n>>m>>q;

    
    for(int j=0;j<m;j++)
    {
        int x,y;cin>>x>>y;
        grid[x][y]++;
    }
    

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+grid[i][j];
        }
    }

    for(int i=0;i<q;i++)
    {
        int x,y;cin>>x>>y;
        int ans=pre[y][y]-pre[x-1][y]-pre[y][x-1]+pre[x-1][x-1];
        cout<<ans<<'\n';
    }
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