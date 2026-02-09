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
#define yes(x) cout << ((x) ? "Fennec\n" : "Snuke\n");

vector<vector<int>> adj;
int n;

vector<int> bfs(int start)
{
    queue<int> q;
    q.push(start);
    vector<bool> vis(n+1,false);
    vector<int> dist(n+1,-1);
    vis[start]=true;
    dist[start]=0;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(auto x : adj[u])
        {
            if(vis[x]) continue;
            dist[x]=dist[u]+1;
            q.push(x);
            vis[x]=true;
        }
    }

    return dist;
}

void solve() 
{
    int safe=0,fr=0,sn=0;
    cin>>n;
    adj.resize(n+1);
    
    for(int i=1;i<n;i++)
    {
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> d1=bfs(1);
    vector<int>dn=bfs(n);
    debug(d1);
    debug(dn);

    for(int i=1;i<=n;i++)
    {
        if(d1[i]<=dn[i]) fr++;
        else sn++;
    }

    yes(fr>sn)
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