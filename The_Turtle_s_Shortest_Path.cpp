#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll n;
const ll infinity = LLONG_MAX;
vector<vector<pair<ll,ll>>> graph;

ll dijsktra(ll source ,ll destination)
{
    vector<ll> distance(n+1,infinity);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,source});
    distance[source]=0;

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

            if(parent_weight+child_weight<distance[child_node])
            {
                distance[child_node]=parent_weight+child_weight;
                pq.push({distance[child_node],child_node});
            }
        }
    }

    return distance[destination];
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
        string source,destination,tmp_city;
        map<string,ll> mp;
        cin>>n;

        graph = vector<vector<pair<ll,ll>>> (n+1);
        for(ll i=1;i<=n;i++)
        {
            cin>>tmp_city;
            mp[tmp_city]=i;
            ll p,u,w;
            cin>>p;

            for(int j=0;j<p;j++)
            {
                cin>>u>>w;
                //graph[i].push_back({u,w});
                graph[u].push_back({i,w});
            }
        }

        ll q;
        cin>>q;

        while(q--)
        {
            cin>>source>>destination;
            ll result = dijsktra(mp[source],mp[destination]);
            cout<<result<<endl;
        }

    }
}