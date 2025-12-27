#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int n,m;
vector<vector<int>> graph;

void dijkstra()
{
    vector<vector<ll>> dist(n, vector<ll>(m, infinity));
    priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<pair<ll, pair<int, int>>>> pq;

    pq.push({graph[0][0],{0,0}});
    dist[0][0]=graph[0][0];

    while(!pq.empty())
    {
        int node_i=pq.top().second.first;
        int node_j=pq.top().second.second;
        int node_weight=pq.top().first;

        pq.pop();
        if(node_weight>dist[node_i][node_j]) continue;

        for(int i=0;i<4;i++)
        {
            int neighbour_i=node_i+dx[i];
            int neighbour_j=node_j+dy[i];

            if(neighbour_i>=0 && neighbour_j>=0 && neighbour_i<n && neighbour_j<m && graph[neighbour_i][neighbour_j]+node_weight<dist[neighbour_i][neighbour_j])
            {
                int neighbour_weight=graph[neighbour_i][neighbour_j];
                dist[neighbour_i][neighbour_j]=neighbour_weight+node_weight;
                pq.push({dist[neighbour_i][neighbour_j],{neighbour_i,neighbour_j}});
            }
        }
    }

    cout<<dist[n-1][m-1]<<endl;
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
        cin>>n>>m;
        graph=vector<vector<int>>(n,vector<int>(m));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>graph[i][j];
            }
        }

        dijkstra();
    }
}