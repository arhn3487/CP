#include<bits/stdc++.h>
using namespace std;

vector<long long> mx_profit,mn_profit,a;
vector<vector<long long>> adj;

void dfs(long long node,long long parent)
{
    if(parent!=-1)
    {
        mx_profit[node]=max(a[node],a[node]-mn_profit[parent]);
        mn_profit[node]=min(a[node],a[node]-mx_profit[parent]);
    }
    else
    {
        mx_profit[node]=a[node];
        mn_profit[node]=a[node];
    }

    for(auto child : adj[node])
    {
        if(child!=parent)
        {
            dfs(child,node);
        }
    }
}

void solve()
{
    long long n;
    cin>>n;
    a.resize(n);
    mx_profit.assign(n,0);
    mn_profit.assign(n,0);
    adj.clear();
    adj.resize(n);
    

    for(auto &x : a) cin>>x;

    for(long long i=0;i<n-1;i++)
    {
        long long u,v;
        cin>>u>>v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0,-1);

    for(auto x : mx_profit)
    {
        cout<<x<<" ";
    }
    cout<<'\n';

}

int main()
{
    long long t;
    cin>>t;

    while(t--)
    {
        solve();
    }
}