#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
int dx[]={2,2,-2,-2,1,1,-1,-1};
int dy[]={1,-1,1,-1,2,-2,2,-2};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}
int a,b,c,d;

void bfs()
{
    queue<pair<pair<int,int>,int>> q;
    q.push({{a,b},1});
    int level=0;
    int vis[8][8]={};
    vis[a][b]=1;

    while(!q.empty())
    {
        int parent_x = q.front().first.first;
        int parent_y=q.front().first.second;
        int parent_level=q.front().second;
        q.pop();
        
        //cout<<parent_x<<" "<<parent_y<<endl;
        
        for(int i=0;i<8;i++)
        {
            int child_x=parent_x+dx[i];
            int child_y=parent_y+dy[i];
            

            if(child_x>=0 && child_y>=0 && child_x<8 && child_y<8 && !vis[child_x][child_y])
            {
                q.push({{child_x,child_y},parent_level+1});
                vis[child_x][child_y]=1;
                if(child_x==c && child_y==d)
                {
                    cout<<parent_level<<endl;
                    return;
                }
            }
        }
    }
}

int main()
{
   int t;
   cin>>t;

    while(t--)
    {
        char x,y;
        cin>>x>>y;
        a=x-'a';
        b=y-'1';
        //cout<<x<<" "<<y<<"\n";
        cin>>x>>y;
        c=x-'a';
        d=y-'1';
        //cout<<x<<" "<<y<<"\n";
        
        //cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
        
        //cout<<"arafat\n";
        if(a==c && b==d) cout<<0<<endl;
        else bfs();
    }
}