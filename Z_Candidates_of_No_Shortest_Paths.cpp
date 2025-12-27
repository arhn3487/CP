#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define ll long long
const int M = 1e9 + 7;
const ll infinity = LLONG_MAX;
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1}; // Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[] = {0, -1, 0, 1, 1, -1, 1, -1};
inline ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }

#define rall(v) v.rbegin(), v.rend()
#define all(v) v.begin(), v.end()
#define print(x) cout << x << '\n';
#define yes(x) cout << ((x) ? "Yes\n" : "No\n");

//int graph[100][100],dist[100][100];
vector<vector<ll>> graph(100,vector<ll>(100,infinity)),dist(100,vector<ll>(100,infinity));

int floydwarshall(int n)
{
    int cnt=0;
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] < INT_MAX && dist[k][j] < INT_MAX)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }

                
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(graph[i][j]<infinity && dist[i][j]<graph[i][j]) cnt++;
        }
    }

    return cnt;
}

void solve()
{
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        a--,b--;
        graph[a][b]=graph[b][a]=c;
        dist[a][b]=dist[b][a]=c;
    }

    cout<<floydwarshall(n)/2<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    //cin >> t;

    for (int i = 1; i <= t; i++)
    {
        // cout<<"Case "<<i<<": ";
        solve();
    }
}