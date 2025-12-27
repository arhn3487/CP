#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

vector<vector<int>> adj, adj_rev;
vector<bool> visited;
vector<int> order, component;

void dfs1(int v) {
    visited[v] = true;
    for (auto u : adj[v])
        if (!visited[u])
            dfs1(u);
    order.push_back(v);
}

void dfs2(int v, int cl) {
    component[v] = cl;
    for (auto u : adj_rev[v])
        if (component[u] == -1)
            dfs2(u, cl);
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    
    adj.assign(n, vector<int>());
    adj_rev.assign(n, vector<int>());
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj_rev[v].push_back(u);
    }
    
    visited.assign(n, false);
    order.clear();
    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs1(i);
    
    component.assign(n, -1);
    int cl = 0;
    for (int i = 0; i < n; i++) {
        int v = order[n-1-i];
        if (component[v] == -1)
            dfs2(v, cl++);
    }
    

    vector<int> size_scc(cl, 0);
    for (int i = 0; i < n; i++)
        size_scc[component[i]]++;
    
    vector<vector<int>> dag(cl);
    vector<int> indeg(cl, 0);
    vector<vector<bool>> has_edge(cl, vector<bool>(cl, false));
    
    for (int v = 0; v < n; v++) {
        for (int u : adj[v]) {
            int cv = component[v], cu = component[u];
            if (cv != cu && !has_edge[cv][cu]) {
                has_edge[cv][cu] = true;
                dag[cv].push_back(cu);
                indeg[cu]++;
            }
        }
    }
    
    vector<int> topo;
    queue<int> q;
    for (int i = 0; i < cl; i++)
        if (indeg[i] == 0)
            q.push(i);
            
    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (int v : dag[u]) {
            indeg[v]--;
            if (indeg[v] == 0)
                q.push(v);
        }
    }
    

    vector<vector<int>> dp(cl, vector<int>(k+1, 0));
    int ans = 0;
    
    for (int i = 0; i < cl; i++) {
        dp[i][1] = size_scc[i];
        ans = max(ans, dp[i][1]);
    }
    
    for (int u : topo) {
        for (int v : dag[u]) {
            for (int j = 1; j < k; j++) {
                if (dp[u][j] > 0) {
                    dp[v][j+1] = max(dp[v][j+1], dp[u][j] + size_scc[v]);
                    ans = max(ans, dp[v][j+1]);
                }
            }
        }
    }
    
    for (int iter = 0; iter < cl; iter++) {
        for (int u = 0; u < cl; u++) {
            for (int v : dag[u]) {
                for (int j = 1; j < k; j++) {
                    if (dp[u][j] > 0) {
                        dp[v][j+1] = max(dp[v][j+1], dp[u][j] + size_scc[v]);
                        ans = max(ans, dp[v][j+1]);
                    }
                }
            }
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
        //cout<<"Case "<<i<<": ";
        solve();
    }
}