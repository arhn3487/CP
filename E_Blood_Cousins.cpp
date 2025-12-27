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

const int N=1e5+3;
map<int,int> mp[N];//depth,count
vector<int> adj[N];
vector<pair<int,int>> query[N];
int ans[N];
bool vis[N];

void dfs(int u)
{
    cout<<u<<endl;
    vis[u]=true;
    for(auto x : adj[u])
    {
        dfs(x);
        if(mp[u].size()>mp[x].size()) swap(mp[u],mp[x]);

        for(auto [height,cnt] : mp[x])
        {
            if(cnt)mp[u][height+1]+=cnt;
        }
    }

    mp[u][0]=1;

    for(auto [ind,h] : query[u])
    {
        ans[ind]=mp[u][h];
    }

    debug(u,mp[u]);
}

void solve()
{
    int n,m;cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;cin>>a;
        if(a) adj[--a].push_back(i);
    }

    cin>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;cin>>a>>b;
        a--;
        query[a].push_back({i,b});
    }

    for(int i=0;i<n;i++) debug(i,adj[i]);

    for(int i=0;i<n;i++)
    {
        if(!vis[i])dfs(i);
    }

    for(int i=0;i<n;i++)
    {
        debug(mp[i]);
    }

    //for(auto [v,h] : query) cout<<ans[v]<<' ';

    for(int i=0;i<m;i++) cout<<ans[i]<<' ';
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
