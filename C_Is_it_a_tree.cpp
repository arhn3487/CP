#include<bits/stdc++.h>
#include "D:/debug.h"
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}
vector<vector<int>> graph;
vector<bool> vis(false);
int p=0;
int total=0;

void dfss(int node,int parent)
{
    vis[node]=true;
    total++;
    for(auto x : graph[node])
    {
        if(!vis[x])dfss(x,node);
        else if(x!=parent) p=1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,u,v;
    cin>>n>>m;
    graph.resize(n+1);
    vis.resize(n+1,false);

    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfss(1,-1);

    if(!p && total==n) cout<<"YES\n";
    else cout<<"NO\n";
}