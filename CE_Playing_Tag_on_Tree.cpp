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

vector<int> bfs(int st)
{
    queue<int> q;
    q.push(st);
    vector<int> ans(adj.size(),-1);
    ans[st]=0;

    while (q.size())
    {
        int p=q.front();
        q.pop();

        for(auto x : adj[p])
        {
            if(ans[x]==-1)
            {
                q.push(x);
                ans[x]=ans[p]+1;
            }
        }
    }
    return ans;
}

void solve() 
{
    int n,u,v,ans=0;
    cin>>n>>u>>v;
    u--;v--;
    adj.resize(n);
    int m=n-1;

    for(int i=0;i<m;i++)
    {
        int a,b;cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> disu=bfs(u);
    vector<int>disv=bfs(v);

    for(int i=0;i<n;i++)
    {
        if(disu[i]<disv[i])
        {
            ans=max(ans,disv[i]-1);
        }
    }

    cout<<ans<<'\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}