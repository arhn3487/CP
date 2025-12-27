#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

vector<vector<pair<int,int>>> graph;
vector<bool> vis;
int n,cost=0,total=0,dc=1;

void dfs(int src,int par)
{
    if(vis[src]) return;
    //cout<<par<<" "<<src<<" "<<cost<<endl;
    
    vis[src]=true;
    for(auto [v,w] : graph[src])
    {
        if(!vis[v] )
        {
            dc++;
            //cout<<src<<" "<<w<<endl;
            cost+=w;
            dfs(v,src);
        }
        else
        {
            if(v==1 && par!=1) 
            {
                
                cost+=w;
                //cout<<src<<"        "<<cost<<endl;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    graph.resize(n+1);
    vis.assign(n+1,false);
    int u,v,w;
    
    for(int i=0;i<n;i++)
    {
        cin>>u>>v>>w;
        total+=w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,0});
    }

    //vis[1]=true;
    dfs(1,0);
    //cout<<cost<<" "<<total<<endl;
    // if(dc==n)
    // {
    //     cout<<0<<endl;
    //     return 0;
    // }
    cout<<min(cost,total-cost)<<endl;
}