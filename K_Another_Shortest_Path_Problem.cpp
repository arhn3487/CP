#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

const int M=1e9+7;
const int N=1e5+10;
const int infinity = INT_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
//inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}


vector<vector<int>> graph;
 
bool floydwarshall(int n) 
{   
    for(int k=0;k<n;k++) 
        for(int i=0;i<n;i++) 
            for(int j=0;j<n;j++) 
                if(graph[i][k]<INT_MAX && graph[k][j]<INT_MAX) 
                    graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]); 

    for(int i=0;i<n;i++) 
        if(graph[i][i]<0) 
            return true; 

    return false; 
}  

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n,q,u,v,w;
        cin>>n>>q;

        graph.assign(n,vector<int>(n,infinity));

        for(int i=0;i<n;i++)
        {
            cin>>u>>v>>w;
            u--,v--;
            graph[u][v]=min(graph[u][v],w);
            graph[v][u]=min(graph[v][u],w);
            if(u==v) graph[u][v]=graph[v][u]=0;
        }
        floydwarshall(n);

        while(q--)
        {
            cin>>u>>v;
            u--,v--;
            if(graph[u][v]==infinity) cout<<-1<<endl;
            cout<<graph[u][v]<<endl;
        }
    }
}