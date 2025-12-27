#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
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

int n,q;
const int N=1e5+3;
vector<ll> g[N];
vector<ll> dist(N,infinity);

void bfs(ll start)
{
    queue<ll> qu;
    qu.push(start);
    dist[start]=0;

    while(!qu.empty())
    {
        ll u=qu.front();
        qu.pop();

        for(auto x : g[u])
        {
            if(dist[x]>dist[u]+1)
            {
                qu.push(x);
                dist[x]=dist[u]+1;
            }
        }
    }
}
void solve()
{
    cin>>n>>q;

    for(int i=1;i<n;i++)
    {
        ll u,v;cin>>u>>v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bfs(0);

    // for(int i=0;i<n;i++) cout<<dist[i]<<' ';
    // cout<<'\n'; 

    while(q--)
    {
        ll u,v;cin>>u>>v;
        u--,v--;
        int par=dist[u]+dist[v];
        if(par%2) cout<<"Road\n";
        else cout<<"Town\n";
    }
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
