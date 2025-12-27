#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

int n,m,k;
vector<ll> dist;
vector<vector<pair<ll,ll>>> grp;

void dijkstra(ll src)
{
    dist[src]=0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,src});

    while(!pq.empty())
    {
        ll node=pq.top().second;
        ll wt=pq.top().first;
        pq.pop();

        for(auto [child,child_wt] : grp[node])
        {
            if(dist[child]>wt+child_wt)
            {
                dist[child]=wt+child_wt;
                pq.push({dist[child],child});
            }
        }
    }
}

void solve()
{
    cin>>n>>m>>k;
    grp.resize(n+1);
    dist.assign(n+1,infinity);

    for(int i=0;i<m;i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        grp[u].push_back({v,w});
        grp[v].push_back({u,w});
    }

    dijkstra(1);

    ll ans=0;
    while(k--)
    {
        ll s,x;
        cin>>s>>x;

        if(dist[s]<=x)
        {
            ans++;
        }
        else 
        {
            dist[s]=x;
            grp[1].push_back({s,x});
            grp[s].push_back({1,x});
            dist.assign(n+1,infinity);
            dijkstra(1);
        }
    }
    cout<<ans<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    //cin>>t;

    for(int i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<": ";
        solve();
    }
}