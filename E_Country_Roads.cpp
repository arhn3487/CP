#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define debug(x...)
#endif
using namespace std;

#define ll long long
#define ld long double
#define int long long
const int M=1e9+7;
const int N=1e6+5;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");
ll n; 
vector<vector<pair<ll, ll>>> graph; 
 
void dijkstra(ll source) { 
    ll mx = 0, cnt = 0; 
    vector<ll> distance(n, infinity); 
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
 
            if (max(child_weight , parent_weight) < distance[child_node]) { 
                distance[child_node] = max(child_weight , parent_weight); 
                pq.push({distance[child_node], child_node}); 
            } 
        } 
    } 

    for(auto x : distance) if(x!=infinity) cout<<x<<'\n';
    else cout<<"Impossible\n";
    //cout<<'\n';
    debug(distance);
} 

void solve()
{
    int m;cin>>n>>m;
    graph.clear();
    graph.resize(n);

    for(int i=0;i<m;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        //u--,v--;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }

    int t;cin>>t;


    dijkstra(t);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    cin>>t;

    for(int i=1;i<=t;i++)
    {
        cout<<"Case "<<i<<":\n";
        solve();
    }
}