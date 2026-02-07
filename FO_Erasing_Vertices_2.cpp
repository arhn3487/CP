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

void solve() 
{
    int n,m,ans=0,vis=0;cin>>n>>m;
    adj.resize(n+1);
    vector<int> a(n+1),total(n+1);
    vector<bool> vv(n+1,false);

    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=0;i<m;i++)
    {
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    for(int i=1;i<=n;i++)
    {
        int sum=0;
        for(auto x : adj[i]) sum+=a[x];
        pq.push({sum,i});
        total[i]=sum;
    }

    while(vis<n)
    {
        while (vv[pq.top().second]) pq.pop();
        ans=max(ans,pq.top().first);
        vv[pq.top().second]=true;
        int kk=pq.top().second;
        pq.pop();

        for(auto x : adj[kk])
        {
            total[x]-=a[kk];
            pq.push({total[x],x});
        }
        vis++;
    }
    print(ans)

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