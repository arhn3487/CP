#include<bits/stdc++.h>
#include "D:/debug.h"
using namespace std;

#define ll int
const ll infinity = INT_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

vector<vector<ll>> graph;

bool bellman_ford(int n,vector<int> &dist)
{
    for(int i =0;i<n-1;i++)
        for(auto &it : graph){
            int u=it[0],v=it[1],w=it[2];
            if(dist[u]!=infinity && dist[u]+w<dist[v]) dist[v]=dist[u]+w;
        }

    //detect negative cycle
    for(auto &it : graph){
        int u=it[0],v=it[1],w=it[2];
        if(dist[u]!=infinity && dist[u]+w<dist[v]) return true;
    }

    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    t=1;
    cin>>t;

    while(t--)
    {
        ll n,m,u,v,w;
        cin>>n>>m;
        graph.clear();

        for(int i=0;i<m;i++)
        {
            cin>>u>>v>>w;
            u--;
            v--;
            graph.push_back({u,v,w});
        }

        ll min_dis=infinity;
        bool flag=true;
        for(int i =0;i<n;i++)
        {
            vector<int> dis(n,infinity);
            dis[i]=0;
            bool negative_cycle=bellman_ford(n,dis);

            if(negative_cycle){
            cout<<"-inf\n";
            flag=false;
            break;
            }
            for(int j=0;j<n;j++)
                min_dis=min(min_dis,dis[j]);
        }

        if(flag)cout<<min_dis<<"\n";
    }
}