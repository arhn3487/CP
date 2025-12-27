#include<bits/stdc++.h>
#include "D:/debug.h"
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}
int n,m;
pair<int,int> start,destination;

void bfs(vector<vector<char>> &graph,vector<vector<pair<int,int>>> &parent)
{
    queue<pair<int,int>> q;
    q.push(start);
    int vis[n][m]={0};
    vector<vector<char>> dir(n,vector<char>(m));

    while(!q.empty())
    {
        int parent_x=q.front().first;
        int parent_y=q.front().second;
        q.pop();
        cout<<"bal\n";

        for(int i=0;i<4;i++)
        {
            int child_x=parent_x+dx[i];
            int child_y=parent_y+dy[i];

            if(child_x>=0 && child_y>=0 && child_x<n && child_y<m && graph[child_x][child_y]=='.'  && !vis[child_x][child_y])
            {
                vis[child_x][child_y]=1;
                q.push({child_x,child_y});
                parent[child_x][child_y]={parent_x,parent_y};
                if(i==0) dir[child_x][child_y]='R';
                else if(i==1) dir[child_x][child_y]='D';
                else if(i==2) dir[child_x][child_y]='L';
                else if(i==3) dir[child_x][child_y]='U';
            }
        }
    }

    if(vis[destination.first][destination.second])
    {
        cout<<"ara\n";
        string str="";
        int a=destination.first,b=destination.second;
        int c=start.first,d=start.second;
        while(a!=c && b!=d)
        {
            str.push_back(dir[a][b]);
            a=parent[a][b].first;
            b=parent[a][b].second;
        }
        reverse(str.begin(),str.end());
        cout<<str<<endl;
    }
    else cout<<"No\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>>(m));
    vector<vector<char>> graph(n,vector<char>(m));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++) 
        {
            cin>>graph[i][j];
            if(graph[i][j]=='A') start={i,j};
            else if(graph[i][j]=='B') destination={i,j};
        }
    }
}