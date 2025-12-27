#include<bits/stdc++.h>
//#include "D:/debug.h"
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

vector<vector<pair<int,int>>> g;
vector<int> val;
vector<bool> vis;
int state;
ll sum;

void dfs(int start,int finish,int node)
{
    bool f=true;
    vis[node]=true;
    //cout<<start<<" "<<finish<<" "<<node<<'\n';
    state^=1;
    if(state) sum+=val[node];
    if(g[node].size()==0) return;

    while(start<=finish)
    {
        f=false;
        if(state==0) 
        {
            if(!vis[g[node][finish].first])
            dfs(0,g[g[node][finish].first].size()-1,g[node][finish].first);
            finish--;
        }
        else
        {
            if(!vis[g[node][start].first])
            dfs(0,g[g[node][start].first].size()-1,g[node][start].first);
            start++;
        }
    }
    //if(f) dfs(0,g[g[node][start].first].size()-1,g[node][start].first);
}

void solve()
{
    int n;
    cin>>n;
    state=1,sum=0;
    val.resize(n);
    g.clear();
    g.resize(n);
    vis.assign(n,false);

    for(int i=0;i<n;i++) cin>>val[i];

    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].push_back({v,val[v]});
        g[v].push_back({u,val[u]});
    }

    for(int i=0;i<n;i++)
    {
        sort(g[i].begin(),g[i].end(),[&](pair<int,int> &a,pair<int,int>&b){
            return a.second<b.second;
        });
    }

    dfs(0,g[0].size()-1,0);
    cout<<sum<<'\n';
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