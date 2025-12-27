#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
ll n;
vector<vector<pair<ll,ll>>> graph;

void dijkstra(ll source)
{
    vector<ll> distance(n,infinity);
    distance[source]=0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,source});

    while(!pq.empty())
    {
        //cout<<"arafat"<<endl;
        ll parent_node=pq.top().second;
        ll parent_weight=pq.top().first;
        pq.pop();
        //cout<<parent_node<<" "<<parent_weight<<endl;

        if(distance[parent_node]<parent_weight) continue;

        for(auto child : graph[parent_node])
        {
            ll child_node=child.first;
            ll child_weight=child.second;

            if(max(child_weight,parent_weight)<distance[child_node])
            {
                distance[child_node]=max(child_weight,parent_weight);
                pq.push({distance[child_node],child_node});
            }
        }
    }
    for(ll dist : distance) 
    {
        if(dist!=infinity)cout<<dist<<endl;
        else cout<<"Impossible"<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    for(int test=1;test<=t;test++)
    {
        ll m,u,v,w,source;
        cin>>n>>m;
        graph=vector<vector<pair<ll,ll>>> (n);

        for(ll i=0;i<m;i++)
        {
            cin>>u>>v>>w;
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }
        cin>>source;

        cout<<"Case "<<test<<":"<<endl;
        dijkstra(source);
    }
}