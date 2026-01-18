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
const int N = 100005;
const ll infinity = LLONG_MAX;
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1}; //Right, Down, Left, Up, Diagonals
int dy[] = {0, -1, 0, 1, 1, -1, 1, -1};
inline ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }

#define rall(v) v.rbegin(), v.rend()
#define all(v) v.begin(), v.end()
#define print(x) cout << x << '\n';
#define yes(x) cout << ((x) ? "Yes\n" : "No\n");

vector<int> adj[N];
int memo[N];

int can_win(int u)
{
    cerr<<u<<'\n';
    if(memo[u]!=-1) return memo[u];
    if(adj[u].size()==0) return memo[u]=0;
    int ok=1;

    for(auto x : adj[u])
    {
        ok=ok and can_win(x);
    }

    return memo[u]=!ok;
}

void solve() 
{
    int n,m,x;cin>>n>>m>>x;
    
    for(int i=0;i<=n;i++)
    {
        memo[i]=-1;
        adj[i].clear();
    }
    for(int i=0;i<m;i++)
    {
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
    }

    yes(can_win(x))

    for(int i=1;i<=n;i++) cerr<<memo[i]<<' ';

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}