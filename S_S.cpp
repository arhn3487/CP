#include<bits/stdc++.h>
using namespace std;

#define ll long long

auto dijkstra(int start,vector<vector<pair<int,int>>> &g,int n)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<ll> dist(n,INT_MAX);
    dist[start]=0;
    pq.push({0,start});

    while(!pq.empty())
    {
        auto [cost,node]=pq.top();
        pq.pop();

        for(auto [child,c] : g[node])
        {
            if(c+cost>dist[child]) continue;
            dist[child]=c+cost;
            pq.push({dist[child],child});
        }
    }

    return dist;
}


int main()
{
    ll n,m,t,ans=0;
    cin>>n>>m>>t;

    vector<vector<pair<int,int>>> graph(n+1),r_graph(n+1);
    vector<int> a(n);

    for(auto &x : a) cin>>x;

    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        a--,b--;
        graph[a].push_back({b,c});
        r_graph[b].push_back({a,c});
    }

    vector<ll> form=dijkstra(0,graph,n);
    vector<ll> to=dijkstra(0,r_graph,n);

    // for(auto  x: form) cout<<x<<' ';
    // cout<<'\n';

    for(int i=0;i<n;i++)
    {
        ll cost=form[i]+to[i];
        ll stay=t-cost;

        ans=max(ans,stay*a[i]);
    }

    cout<<ans<<'\n';
}