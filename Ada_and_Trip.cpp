#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
ll n;
unordered_map<vector<pair<ll,ll>>> graph;

void dijestra(ll source)
{
    //cout<<"arafat"<<endl;
    ll mx=0,cnt=0;
    vector<ll> distance(n,infinity);
    distance[source]=0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>> ,greater<pair<ll,ll>>> pq;
    pq.push({0,source});

    while(!pq.empty())
    {
        ll parent_node=pq.top().second;
        ll parent_weight=pq.top().first;
        pq.pop();

        if(parent_weight>distance[parent_node]) continue;

        for(auto child : graph[parent_node])
        {
            ll child_node=child.first;
            ll child_weight=child.second;

            if(child_weight+parent_weight<distance[child_node])
            {
                distance[child_node]=child_weight+parent_weight;
                pq.push({distance[child_node],child_node});
                mx=max(mx,distance[child_node]);
            }
        }
    }

    for(ll i=0;i<n;i++)
    {
        if(distance[i]==mx) cnt++;
    }

    cout<<mx<<" "<<cnt<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    

    
        ll m,q,u,v,w;
        cin>>n>>m>>q;
        graph=vector<vector<pair<ll,ll>>>(n);

        for(ll i=0;i<m;i++)
        {
            cin>>u>>v>>w;
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }

        //cout<<"arafat"<<endl;

        while(q--)
        {
            cin>>u;
            dijestra(u);
        }
    
}