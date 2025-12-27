#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

vector<vector<pair<ll,ll>>> graph;
vector<ll> concert;
ll n,m,u,v,w;

void dijkstra() {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    for(int i=0;i<=n;i++) pq.push({concert[i],i});
    while (!pq.empty()) {
        ll parent_node = pq.top().second;
        ll parent_weight = pq.top().first;
        pq.pop();

        if (parent_weight > concert[parent_node]) continue;

        for (auto child : graph[parent_node]) {
            ll child_node = child.first;
            ll child_weight = child.second;

            if (child_weight + parent_weight < concert[child_node]) {
                concert[child_node] = child_weight + parent_weight;
                pq.push({concert[child_node], child_node});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    concert=vector<ll>(n+1);
    graph=vector<vector<pair<ll,ll>>> (n+1);

    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        graph[u].push_back({v,2*w});
        graph[v].push_back({u,2*w});
    }

    for(int i=1;i<=n;i++)
    {
        cin>>concert[i];
    }
    
    dijkstra();

    for(int i=1;i<=n;i++)
    {
        cout<<concert[i]<<" ";
    }
    cout<<endl;
    
}