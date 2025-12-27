#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define debug(x...)
#endif
using namespace std;

#define ll long long
#define ld long double
#define int long long
const int M=1e9+7;
const int N=1e6+5;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

int n,m,k;
vector<int> sz,par;
vector<vector<int>> fd,blc;

int find_par(int u)
{
    if(par[u]==u) return u;
    return par[u]=find_par(par[u]);
}

void _union(int u,int v)
{
    int a=find_par(u),b=find_par(v);
    //debug(a+1,b+1);
    if(a==b) return;
    if(sz[a]<sz[b]) swap(a,b);
    par[b]=a;
    sz[a]+=sz[b];
}

void solve()
{
    cin>>n>>m>>k;
    fd.resize(n);
    blc.resize(n);
    sz.resize(n);
    par.resize(n);

    for(int i=0;i<n;i++) par[i]=i,sz[i]=1;

    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        u--,v--;
        fd[u].push_back(v);
        fd[v].push_back(u);
        
        _union(u,v);
    }

    for(int i=0;i<k;i++)
    {
        int u,v;cin>>u>>v;
        u--,v--;
        blc[u].push_back(v);
        blc[v].push_back(u);
    }

    debug(sz);
    debug(par);

    for(int i=0;i<n;i++)
    {
        int a=find_par(i);
        int ans=sz[a]-fd[i].size()-1;

        for(auto x : blc[i])
        {
            int b=find_par(x);
            if(b==a) ans--;
        }

        cout<<ans<<' ';
    }
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