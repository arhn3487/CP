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
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

vector<int> dist(300,INT_MAX);
vector<pair<int,int>> g[300];

void dijkstra(int start)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,start});
    dist[start]=0;

    while(!pq.empty())
    {
        auto [d,u] = pq.top(); // d = distance, u = node
        pq.pop();
        if(d > dist[u]) continue;

        for(auto [v,w] : g[u]) {
            if(dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
}

void solve()
{
    int a,b,x,y;
    cin>>a>>b>>x>>y;

    for(int i=0;i<99;i++)
    {
        g[i].push_back({i+1,y});
        g[i+1].push_back({i,y});
        g[100+i].push_back({100+i+1,y});
        g[100+i+1].push_back({100+i,y});
    }

    for(int i=0;i<100;i++)
    {
        g[i].push_back({100+i,x});
        g[100+i].push_back({i,x});

        if(i<99)
        {
            g[i+1].push_back({100+i,x});
            g[100+i].push_back({i+1,x});
        }
    }

    dijkstra(a-1);

    cout<<dist[100+b-1]<<'\n';
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