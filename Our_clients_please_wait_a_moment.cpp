#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define debug(x...)
#endif
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
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

#define int ll

vector<ll> dijkstra(int n,int source,vector<vector<ll>> &cost)
{
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,source});
    vector<ll> dist(n+1,infinity);
    dist[source]=0;

    while(!pq.empty())
    {
        auto [d,u]=pq.top();pq.pop();
        if(d>dist[u]) continue;

        for(int v=1;v<=n;v++)
        {
            if(u==v) continue;
            int nd=d+cost[u][v];
            if(nd<dist[v])
            {
                dist[v]=nd;
                pq.push({nd,v});
            }
        }
    }
    return dist;
}

void solve()
{
    ll n,a,b,c,ans=infinity;cin>>n>>a>>b>>c;
    ll arr[n+1][n+1];

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>arr[i][j];
        }
    }

    ///cerr<<"A";

    vector<vector<ll>> car(n+1,vector<ll>(n+1)),train(n+1,vector<ll>(n+1));

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            //cerr<<i<<' '<<j<<'\n';
            car[i][j]=arr[i][j]*a;
            train[i][j]=arr[i][j]*b+c;
            car[j][i]=car[i][j];
            train[j][i]=train[i][j];
        }
    }

    //cerr<<"B";

    //cerr<<"ARAFT\n";

    vector<ll> dis1=dijkstra(n,1,car);
    vector<ll> dis2=dijkstra(n,n,train);

    for(int i=1;i<=n;i++)
    {
        ans=min(ans,dis1[i]+dis2[i]);
    }

    cout<<ans<<'\n';
}

int32_t main()
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
