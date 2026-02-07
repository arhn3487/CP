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
set<int> st;
vector<bool> vis;

void dfs(int u,int p)
{
    st.insert(u);
    if(vis[u]) return;
    vis[u]=true;
    for(auto x : adj[u])
    {
        if(x!=p)
        {
            dfs(x,u);
        }
    }
}

void solve() 
{
    int n,m,cnt=0;cin>>n>>m;
    adj.resize(n+1);
    vector<int> p(n+1);
    vis.assign(n+1,false);

    for(int i=1;i<=n;i++)
    {
        int a;cin>>a;
        p[i]=a;
    }


    for(int i=0;i<m;i++)
    {
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1;i<=n;i++)
    {
        if(!vis[i]) dfs(i,-1);
        debug(st);
        for(auto x : st)
        {
            if(st.find(p[x])!=st.end()) cnt++;
        }
        st.clear();
    }

    cout<<cnt<<'\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    
    for (int i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}