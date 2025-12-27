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
const int N=2e5+5;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

vector<int> adj[N];
int sz[N];
int n;

void dfs(int u,int p)
{
    sz[u]=1;
    for(auto x : adj[u])
    {
        if(x==p) continue;
        dfs(x,u);
        sz[u]+=sz[x];
    }
}

int get(int u,int p)
{
    for(auto x : adj[u])
    {
        if(x!=p && 2*sz[x]>n) return get(x,u);
    }
    return u;
}

void solve()
{
    cin>>n;

    for(int i=1;i<n;i++)
    {
        int a,b;cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0,0);
    //cerr<<"ARAFAT\n";
    cout<<get(0,0)+1<<'\n';
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