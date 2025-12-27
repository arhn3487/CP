#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define debug(x...)
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

#define int ll


ll n; 
vector<vector<array<ll,3>>> graph; 
vector<ll> res;
 
//It doesn't work for nagative cycle 
void dijkstra(ll source) { 
    ll mx = 0, cnt = 0; 
    vector<ll> distance(n, infinity),parent_edge(n,-1); 
    distance[source] = 0; 
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq; 
    pq.push({0, source}); 
    //debug(source);
 
    while (!pq.empty()) { 
        ll parent_node = pq.top().second; 
        ll parent_weight = pq.top().first; 
        pq.pop(); 
        //debug('a');
 
        if (parent_weight > distance[parent_node]) continue; 
        //debug('b');
 
        for (auto child : graph[parent_node]) { 
            ll child_node = child[0]; 
            ll child_weight = child[1]; 
  
            if (child_weight + parent_weight < distance[child_node]) { 
                distance[child_node] = child_weight + parent_weight; 
                pq.push({distance[child_node], child_node}); 
                parent_edge[child_node]=child[2];
                // debug(parent_edge);
                // debug(child[2]);
            } 
        } 
    } 

    //debug(parent_edge,n);
    for(int i=1;i<n;i++) cout<<parent_edge[i]<<' ';
} 



void solve()
{
    int m;cin>>n>>m;
    graph.resize(n);
    //KruskalMST mst(n);

    for(int i=0;i<m;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        u--,v--;
        graph[u].push_back({v,w,i+1});
        graph[v].push_back({u,w,i+1});
        //mst.add_edge(u,v,w,i+1);
    }

    //debug("ATA");

    //mst.get_mst_weight();
    dijkstra(0);

    //for(int i=0;i<n-1;i++) cout<<res[i]<<' ';
}

int32_t main()
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