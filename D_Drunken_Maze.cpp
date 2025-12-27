#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int n,m;
vector<vector<char>> g;
vector<vector<bool>> vis;
vector<vector<int>> dis;

void bfs(int i,int j) 
{ 
    vis[i][j]=1; 
    queue<vector<int>> q; 
    q.push({i,j,0,0,0,0}); 
     
    while(!q.empty()) 
    { 
        //if(vis[hx][hy]) return; 
        auto v = q.front(); 
        q.pop(); 
        int x=v[0],y=v[1]; 
         
        for(int a=0;a<4;a++) 
        { 
            int new_x=x+dx[a]; 
            int new_y=y+dy[a]; 
            if(!vis[new_x][new_y] && new_x>=0 && new_x<n && new_y>=0 && new_y<m && g[new_x][new_y]!='#') 
            { 
                //cout<<new_x<<" "<<new_y<<endl;
                vis[new_x][new_y]=true; 
                //q.push({new_x,new_y}); 
                dis[new_x][new_y]=dis[x][y]+1; 
                if(a==0 ) q.push({new_x,new_y,v[2]+1,0,0,0}); //right
                else if(a==1) q.push({new_x,new_y,0,v[3]+1,0,0}); //down
                else if(a==2 ) q.push({new_x,new_y,0,0,v[4]+1,0}); //left
                else if(a==3) q.push({new_x,new_y,0,0,0,v[5]+1}); //up
                else q.push({new_x,new_y,0,0,0,0}); 
                // if(a==0) q.top()[2]++;
                // if(a==1) q.top()[3]++;
                // if(a==2) q.top()[4]++;
                // if(a==3) q.top()[5]++;

                //cout<<v[2]<<" "<<v[3]<<" "<<v[4]<<" "<<v[5]<<endl;

                if(v[2]==2 || v[3]==2 || v[4]==2 || v[5]==2)
                {
                    dis[new_x][new_y]+=2;
                    q.pop();
                    q.push({new_x,new_y,0,0,0,0}); 
                }
            } 
        } 
    } 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int sx,sy,ex,ey;

    cin>>n>>m;
    g.resize(n,vector<char>(m));
    vis.assign(n,vector<bool>(m,false));
    dis.assign(n,vector<int>(m,INT_MAX));

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            
            {
                cin>>g[i][j];
                if(g[i][j]=='S')
                {
                    sx=i;
                    sy=j;
                }
                else if(g[i][j]=='T')
                {
                    ex=i;
                    ey=j;
                }
            }

    dis[sx][sy]=0;
    bfs(sx,sy);

    if(dis[ex][ey]!=INT_MAX) cout<<dis[ex][ey]<<endl;
    else cout<<-1<<endl;
}
