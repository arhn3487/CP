#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
ll n;
vector<vector<pair<ll,ll>>> graph;

void dijkstra(int start,int end)
{
    vector<ll> distance(n+1,infinity);
    distance[start]=0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,start});

    while(!pq.empty())
    {
        ll parent_node=pq.top().second;
        ll parent_weight=pq.top().first;
        pq.pop();

        if(distance[parent_node]<parent_weight) continue;

        for(auto child : graph[parent_node])
        {
            ll child_node=child.first;
            ll child_weight=child.second;

            if(child_weight+parent_weight<distance[child_node])
            {
                distance[child_node]=child_weight+parent_weight;
                pq.push({distance[child_node],child_node});
            }
        }
    }

    if(distance[end]==infinity) cout<<"NONE"<<endl;
    else cout<<distance[end]<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        ll m,start,end,u,v,w;
        cin>>n>>m>>start>>end;

        graph=vector<vector<pair<ll,ll>>>(n+1);

        for(ll i=0;i<m;i++)
        {
            cin>>u>>v>>w;
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }

        dijkstra(start,end);
    }
}