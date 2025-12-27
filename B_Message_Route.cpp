#include<bits/stdc++.h>
#include "D:/debug.h"
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int n,m;
vector<vector<int>> graph;

void bfs()
{
    queue<int> q;
    q.push(1);
    int vis[n+1]={0};
    vis[1]=1;
    map<int,int> parent;

    while(!q.empty())
    {
        int node=q.front();
        q.pop();

        if(node==n)
        {
            vector<int> v;
            v.push_back(n);

            while(n!=0)
            {
                v.push_back(parent[n]);
                n=parent[n];
            }
            reverse(v.begin(),v.end());

            cout<<v.size()<<endl;
            for(auto x : v) cout<<x<<" ";
        }

        for(auto neighbour : graph[node])
        {
            if(!vis[neighbour])
            {
                vis[neighbour]=1;
                q.push(neighbour);
                parent[neighbour]=node;
            }
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    int u,v;

    graph.resize(n+1,vector<int>(m+1));

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) 
        {
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }
}