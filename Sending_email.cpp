#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll N =200005;
ll n,s,p;
vector<pair<ll,ll>> adj[N];

void dijkstra()
{
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,s});
    vector<ll> dist(n,N);
    dist[s]=0;

    while(!pq.empty())
    {
        ll parent_node=pq.top().second;
        ll parent_weight=pq.top().first;
        pq.pop();

        if(parent_weight>dist[parent_node]) continue;

        for(auto it : adj[parent_node])
        {
            //cout<<"arafat"<<endl;
            ll child_node=it.first;
            ll child_weight=it.second;

            if(dist[parent_node]+child_weight<dist[child_node])
            {
                dist[child_node]=dist[parent_node]+child_weight;
                //cout<<dist[child_node]<<endl;
                pq.push({dist[child_node],child_node});
            }
        }
        //cout<<"a"<<endl;
    }
        if(dist[p]!=N) cout<<dist[p]<<endl;
        else cout<<"unreachable"<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    for(int i=1;i<=t;i++)
    {
        ll m,u,v,w;
        for(ll i=0;i<N;i++) adj[i].clear();
        cin>>n>>m>>s>>p;

        for(ll i=0;i<m;i++)
        {
            cin>>u>>v>>w;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        cout<<"Case #"<<i<<": ";
        dijkstra();
    }
}