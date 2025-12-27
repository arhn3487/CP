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
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

vector<int> res,col;
vector<vector<int>> adj;

map<int,int> dfs(int parent,ll &sum,int &max_freq)
{
    int mx_freq=1;
    map<int,int> mp;
    mp[col[node]]++;

    for(auto child : adj[node])
    {
        pair<map<int,int>,int> child_freq=dfs(child,);

    }
}

void solve()
{
    int n;cin>>n;
    col.resize(n);
    res.resize(n);
    adj.resize(n);

    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
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