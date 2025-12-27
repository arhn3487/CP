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
#define yes(x) cout << ((x) ? "Yes\n" : "No\n");

vector<vector<pair<int,int>>> adj;
vector<int> dis;
vector<int> vis;
bool ok=true;

bool dfs(int from)
{
    vis[from]=1;
    for(auto [x,d] : adj[from])
    {
        if(!vis[x])
        {
            dis[x]=dis[from]+d;
            dfs(x);
        }
        else
        {
            if(dis[x]!=dis[from]+d) ok= false;
        }
    }
    return true;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    
    adj.resize(n);
    dis.assign(n,0);
    vis.assign(n,0);

    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        adj[u].push_back({v,w});
        adj[v].push_back({u,-w});
    }

    for(int i=0;i<n;i++)
    {
        if(!dis[i]) dfs(i);
    }

    yes(ok)
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