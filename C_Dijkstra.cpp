#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 1e5 + 5;
ll n;
vector<pair<ll, ll>> adj[N];

vector<ll> dijkstra(int src)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, src});
    vector<ll> dist(n + 1,N);
    dist[1]=0;
   
    while (!pq.empty())
    {
        ll parent_node=pq.top().second;
        ll parent_weight=pq.top().first;
        pq.pop();

        for (auto it : adj[parent_node])
        {
            ll child_node = it.first;
            ll child_weight = it.second;

            //cout<<child_node<<" "<<child_weight<<" "<<dis<<" "<<node<<endl;
            if (parent_weight + child_weight < dist[child_node])
            {
                dist[child_node] = parent_weight + child_weight;
                pq.push({dist[child_node], child_node});
            }
        }
    }
    return dist;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll m, a, u, v, w, flag = 1;
    for (ll i = 0; i < N; i++)
        adj[i].clear();
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<ll> dst = dijkstra(1);

    for(auto nu : dst) cout<<nu<<" ";
}
