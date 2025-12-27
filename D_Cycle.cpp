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

const int N=2e5+3;
int n,m;

vector<int> g[N];
vector<ll> dist(N,infinity);

queue<ll> q;

void bfs()
{
    // //q.push(start);
    // dist[start]=0;

    while(!q.empty())
    {
        ll u=q.front();
        q.pop();

        if(u==0)
        {
            cout<<dist[0]+1<<'\n';
            return;
        }

        for(auto &v : g[u])
        {
            if(dist[u]+1<dist[v])
            {
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }

    cout<<"-1\n";
}

void solve()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        u--,v--;
        if(u==0)
        {
            q.push(v);
            dist[v]=0;
        }
        else{
            g[u].push_back(v);
            //g[v].push_back(u);
        }

    }

    bfs();
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
