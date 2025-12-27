#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
ll n;
vector<vector<pair<ll,ll>>> graph;

void dijestra()
{
    vector<ll> dist(n+1,infinity);
    dist[1]=0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,1});

    while(!pq.empty())
    {
        ll parent_node=pq.top().second;
        ll parent_weight=pq.top().first;
        pq.pop();

        if(parent_weight>dist[parent_node]) continue;

        for(auto child : graph[parent_node])
        {
            ll child_node=child.first;
            ll child_weight=child.second;

            if(child_weight+parent_weight<dist[child_node])
            {
                dist[child_node]=child_weight+parent_weight;
                pq.push({dist[child_node],child_node});
            }
        }
    }

    if(dist[n]==infinity) cout<<"Impossible"<<endl;
    else cout<<dist[n]<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    for(ll test=1;test<=t;test++)
    {
        ll m,u,v,w;
        cin>>n>>m;
        graph = vector<vector<pair<ll,ll>>>(n+1);

        for(ll i=0;i<m;i++)
        {
            cin>>u>>v>>w;
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }

        cout<<"Case "<<test<<": ";
        dijestra();
        for(ll i=0;i<=n;i++) graph[i].clear();
    }
}