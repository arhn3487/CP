#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
#define ll long long
vector<int> adj[N];
double path=0,ans=0;

void dfs(int node,int par,int len,double pro)
{
    int children=adj[node].size()-(par==-1 ? 0 :1);
    if(children==0)
    {
        ans+=pro*len;
        return;
    }

    for(auto child : adj[node])
    {
        if(child!=par) dfs(child,node,len+1,pro/children);
    }
}

int main()
{
    int n;
    cin>>n;

    for(int i=1;i<n;i++)
    {
        int u,v;cin>>u>>v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0,-1,0,1.0);

    

    cout<<fixed<<setprecision(15)<<ans<<'\n';
}
