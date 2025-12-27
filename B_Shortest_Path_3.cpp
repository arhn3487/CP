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

const int N=2*1e5+5;

int n,m;
vector<ll> val(N,0),dist(N,LLONG_MAX);
vector<vector<pair<ll,ll>>> g(N);


void dijkstra(int start)
{
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({val[start],start});
    dist[start]=val[start];


    while(!pq.empty())
    {
        auto [d,u]=pq.top();
        pq.pop();

        if(d>dist[u]) continue;

        for(auto [v,cst] : g[u])
        {
            if(d+cst+val[v] < dist[v])
            {
                dist[v]=d+cst+val[v];
                pq.push({dist[v],v});
            }
        }
    }
}

void solve()
{
    cin>>n>>m;

    for(int i=0;i<n;i++) cin>>val[i];

    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    dijkstra(0);

    for(int i=1;i<n;i++) cout<<dist[i]<<' ';
    cout<<'\n';
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