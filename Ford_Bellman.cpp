#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
ll n;
vector<vector<ll>> graph;

void bellmanFord()
{
    vector<ll> distance(n+1,30000);
    distance[1]=0;

    for(ll i=0;i<n-1;i++)
    {
        for(auto edge : graph)
        {
            ll source=edge[0];
            ll destination=edge[1];
            ll weight=edge[2];

            if(distance[source]!=30000 && distance[source]+weight<distance[destination]) distance[destination]=distance[source]+weight;
        }
    }

    for(int i=1;i<=n;i++) cout<<distance[i]<<" ";
    cout<<endl;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll m,u,v,w;
    cin>>n>>m;

    for(ll i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        graph.push_back({u,v,w});
    }

    bellmanFord();
}