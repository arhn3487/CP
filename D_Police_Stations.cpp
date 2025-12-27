#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 300005;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,k,d,a,u,v;
    cin>>n>>k>>d;

    queue<ll> p;
    vector<ll> station(N,0),ans;
    vector<pair<ll,ll>> edg;
    vector<ll> g[N];

    for(int i=0;i<k;i++)
    {
        cin>>a;
        p.push(a);
        station[a]=a;
    }

    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        edg.push_back({u,v});
    }

    while(!p.empty())
    {
        int parent = p.front();
        p.pop();

        for(auto it : g[parent])
        {
            if(!station[it])
            {
                station[it]=station[parent];
                p.push(it);
            }
        }
    }

    for(ll i =0;i<n-1;i++)
    {
        if(station[edg[i].first]!=station[edg[i].second]) ans.push_back(i+1);
    }

    cout<<ans.size()<<endl;

    for(auto num : ans) cout<<num<<" ";
}