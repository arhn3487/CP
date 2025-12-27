#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
//#include "D:/debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define ll long long
const ll M=1e9+7;
const ll infinity = LLONG_MAX;
ll dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
ll dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define prll(x) cout<<x<<'\n';
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

vector<ll> g[15];
vector<ll> dist(15,0);
ll n,m;

void dfs(ll s)
{
    if(dist[s]) return;
    dist[s]=1;
}

void solve()
{
    cin>>n>>m;

    for(ll i=0;i<m;i++)
    {
        ll u,v;cin>>u>>v;
        //u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(ll i=1;i<=n;i++)
    {
        ll cnt=0;
        dist.assign(15,0);
        dist[i]=1;
        for(auto x : g[i]) dist[x]=1;
        for(auto fd : g[i])
        {
            //dist[fd]=1;
            //cout<<fd<<'\n';
            for(auto x : g[fd])
            {
                
                if(dist[x]==0)
                {
                    //cout<<x<<' ';
                    dist[x]=1;
                    cnt++;
                }
            }

            //cout<<'\n';
            
        }
        //cout<<"ses\n";

        cout<<cnt<<'\n';
    }

    ///dfs(0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t=1;
    //cin>>t;

    for(ll i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<": ";
        solve();
    }
}