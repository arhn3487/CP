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

ll n,m,s,t; 
vector<vector<pair<ll, ll>>> graph; 
 
//It doesn't work for nagative cycle 
void dijkstra(ll source) { 
    ll mx = 0, cnt = 0; 
    vector<ll> distance(n, infinity),parent(n+1,-1); 
    distance[source] = 0; 
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq; 
    pq.push({0, source}); 
 
    while (!pq.empty()) { 
        ll parent_node = pq.top().second; 
        ll parent_weight = pq.top().first; 
        pq.pop(); 
 
        if (parent_weight > distance[parent_node]) continue; 
 
        for (auto child : graph[parent_node]) { 
            ll child_node = child.first; 
            ll child_weight = child.second; 
 
            if (child_weight + parent_weight < distance[child_node]) { 
                distance[child_node] = child_weight + parent_weight; 
                pq.push({distance[child_node], child_node}); 
                parent[child_node]=parent_node;
            } 
        } 
    } 

    while(s!=t)
    {
        t=parent[t];
        cnt++;
    }

    cout<<cnt<<'\n';
} 

void solve()
{
    int m;cin>>n>>m>>s>>t;
    graph.resize(n);
    s--,t--;
    for(int i=0;i<m;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        u--,v--;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }

    dijkstra(s);
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