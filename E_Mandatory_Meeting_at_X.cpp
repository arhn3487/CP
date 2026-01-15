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

int n,m,q,c;
vector<vector<int>> adj;

vector<int> bfs(int src)
{
    vector<int> dis(n,INT_MAX),vis(n,0);
    queue<int> q;
    q.push(src);
    dis[src]=0;
    vis[src]=1;

    while(!q.empty())
    {
        int par=q.front();
        q.pop();
        
        for(auto x : adj[par])
        {
            if(!vis[x])
            {
                dis[x]=1+dis[par];
                vis[x]=1;
                q.push(x);
            }
        }
    }

    return dis;
}

void solve()
{
    int x;
    cin>>n>>m>>x>>c;
    adj.resize(n);
    for(int i=0;i<m;i++)
    {
        int a,b;cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cin>>q;

    vector<int>bb=bfs(x-1);

    debug(bb);

    while (q--)
    {
        int a,b;cin>>a>>b;
        a--,b--;
        if(bb[b]==INT_MAX or bb[a]==INT_MAX)
        {
            cout<<-1<<'\n';
            continue;
        }
        cout<<(bb[b]+bb[a])*c<<'\n';
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
