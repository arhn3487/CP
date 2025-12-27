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
#define yes(x) cout << ((x) ? "Yes\n" : "No\n");

void solve()
{
    int n,q;cin>>n>>q;
    ll sum=0;
    vector<pair<int,int>> adj[n],hadj[n];
    map<int,ll> mp[n];
    vector<int> colour(n);
    vector<bool> is_heavy(n,false);

    for(auto &x : colour) cin>>x;

    for(int i=1;i<n;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        u--,v--;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        if(colour[u]!=colour[v]) sum+=w;
    }

    for(int i=0;i<n;i++)
    {
        if(adj[i].size()>10000)
        {
            is_heavy[i]=true;
            for(auto [x,w] : adj[i])
            {
                // mp[x][colour[i]]+=w;
                // hadj[x].push_back({i,w});
                hadj[x].push_back({i, w});
                mp[i][colour[x]] += w;
            }
        }
    }

    while(q--)
    {
        int u,c;cin>>u>>c;
        u--;

        if(!is_heavy[u])
        {
            for(auto [v,w]: adj[u])
            {
               if(colour[u]!=colour[v]) sum-=w;
               if(colour[v]!=c) sum+=w;
            }
        }
        else
        {
            sum-=mp[u][c];
            sum+=mp[u][colour[u]];
        }

        for(auto [v,w] : hadj[u])
        {
            mp[v][colour[u]]-=w;
            mp[v][c]+=w;
        }

        colour[u]=c;

        cout<<sum<<'\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    cin>>t;

    for(int i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<": ";
        solve();
    }
}
