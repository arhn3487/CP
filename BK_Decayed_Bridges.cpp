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

vector<int> sz,par;
int n,m,cur;
vector<array<int,2>> edge;

int find_par(int u)
{
    if(u==par[u]) return u;
    return par[u]=find_par(par[u]);
}

bool add_edge(int u,int v)
{
    int a=find_par(u),b=find_par(v);
    if(a==b) return false;
    par[a]=b;
    sz[b]+=sz[a];
    return true;
}

void solve()
{
    cin>>n>>m;
    par.resize(n);
    sz.resize(n);
    vector<int> ans(m);

    for(int i=0;i<n;i++)
    {
        par[i]=i;
        sz[i]=1;
    }

    edge.resize(m);
    
    for(int i=0;i<m;i++)
    {
        int u,v;cin>>u>>v;
        u--,v--;
        edge[i]={u,v};
    }

    //reverse(all(edge));

    cur=(n-1)*n/2;

    for(int i=m-1;i>=0;i--)
    {
        ans[i]=cur;
        int u=edge[i][0],v=edge[i][1];
        int x=sz[find_par(u)],y=sz[find_par(v)];
        if(add_edge(u,v)) 
        {
            cur-=(x*y);
        }
    }

    for(auto x : ans) cout<<x<<'\n';
    cout<<'\n';
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