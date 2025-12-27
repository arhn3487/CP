#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
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

int h,w,T;
pair<int,int> start,goal;
char grid[10][10];

bool is_valid(int i,int j)
{
    return i>=0 && j>=0 && i<h &&  j<w;
}

bool dijkstra(int t)
{
    vector<vector<ll>> cost(h,vector<ll>(w,infinity));
    priority_queue<tuple<ll,int,int>, vector<tuple<ll,int,int>>,greater<>> pq;
    pq.emplace(0,start.first,start.second);
    cost[start.first][start.second]=0;

    while(!pq.empty())
    {
        auto [val,x,y]=pq.top();
        pq.pop();

        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i],ny=y+dy[i];
            if(is_valid(nx,ny))
            {
                int cs=(grid[nx][ny]=='#') ? t : 1;
                if(cost[x][y]+cs<cost[nx][ny])
                {
                    cost[nx][ny]=cost[x][y]+cs;
                    pq.emplace(cost[nx][ny],nx,ny);
                }

            }
        }
    }

    return cost[goal.first][goal.second]<=T;
}

void solve()
{
    int res=0;
    cin>>h>>w>>T;

    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cin>>grid[i][j];

            if(grid[i][j]=='S') start={i,j};
            else if(grid[i][j]=='G') goal={i,j};
        }
    }

    int lo=0,hi=T,ans=0;

    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        if(dijkstra(mid))
        {
            ans=mid;
            lo=mid+1;
        }
        else hi=mid-1;
    }

    cout<<ans<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    // int t=1;
    // cin>>t;

    // for(int i=1;i<=t;i++)
    // {
    //     //cout<<"Case "<<i<<": ";
    //     solve();
    // }
}
