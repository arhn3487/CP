#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define debug(x...)
#endif
using namespace std;

#define ll long long
#define ld long double
#define int long long
const int M = 1e9 + 7;
const int N = 1e6 + 5;
const ll infinity = LLONG_MAX;
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1}; //Right, Down, Left, Up, Diagonals
int dy[] = {0, -1, 0, 1, 1, -1, 1, -1};
inline ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }

#define rall(v) v.rbegin(), v.rend()
#define all(v) v.begin(), v.end()
#define print(x) cout << x << '\n';
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

vector<vector<int>> adj;
vector<int> col,vis;

void dfs(int u,int par,int c)
{
    col[u]=c;
    vis[u]=1;

    for(auto x: adj[u])
    {
        if(!vis[x]) dfs(x,u,c^1);
    }
}

void solve() 
{
    int n,m;cin>>n>>m;
    adj.clear();
    adj.resize(n);
    col.assign(n,-1);
    vis.assign(n,0);

    for(int i=0;i<m;i++)
    {
        int u,v;cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0,0,0);

    vector<int> s1,s2;

    for(int i=0;i<n;i++)
    {
        if(col[i]==0) s1.push_back(i+1);
        else s2.push_back(i+1);
    }

    if(s1.size()<s2.size())
    {
        cout<<s1.size()<<'\n';
        for(auto x : s1) cout<<x<<' ';
        cout<<'\n';
    }
    else
    {
        cout<<s2.size()<<'\n';
        for(auto x : s2) cout<<x<<' ';
        cout<<'\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}