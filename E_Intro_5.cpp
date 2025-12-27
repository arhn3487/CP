#include<bits/stdc++.h>
//#include "D:/debug.h"
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

int mx=INT_MIN;

vector<int> dp;
vector<bool> vis;

int dfs(int ind,vector<vector<int>> &graph)
{
    vis[ind]=true;
    if(graph[ind].empty()) return 0;
    if(dp[ind]!=-1) return dp[ind];
    dp[ind]=0;
    for(auto x : graph[ind])
    {
        dp[ind]=max(dp[ind],1+dfs(x,graph));
    }
    mx=max(mx,dp[ind]);
    return dp[ind];
}

void solve()
{
    int n,m,u,v;
    cin>>n>>m;
    vector<vector<int>> graph(n+1);
    dp.assign(n+1,-1);
    vis.assign(n+1,false);

    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        graph[u].push_back(v);
    }

    for(int i=1;i<=n;i++) if(!vis[i]) dfs(i,graph);

    // for(auto x : dp) cout<<x<<' ';
    // cout<<'\n';

    cout<<mx<<'\n';
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