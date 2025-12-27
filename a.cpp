#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define debug(x...)
#endif
using namespace std;

#define ll long long
#define ld long double
#define int long long
const int M=1e9+7;
const int N=1e6+5;
const ll infinity = LLONG_MAX;
int dx[]={1,-1,0,0,0,0};
int dy[]={0,0,1,-1,0,0};
int dz[]={0,0,0,0,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

char grid[50][50][50];
bool vis[50][50][50];
pair<int,int> ans[50][50][50];

int X,Y,Z,cnt;
vector<array<int,3>> tmp; 

bool valid(int a,int b,int c)
{
    return (a>=0 && b>=0 && c>=0 && a<Z && b<X && c<Y && grid[a][b][c]=='.' && !vis[a][b][c]);
}

void dfs(int a,int b,int c)//zxy
{
    cnt++;
    vis[a][b][c]=true;
    debug(a,b,c);
    for(int i=0;i<6;i++)
    {
        int aa=a+dz[i],bb=b+dx[i],cc=c+dy[i];
        if(valid(aa,bb,cc))
        {
            dfs(aa,bb,cc);
        }
    }

    //ans[a][b][c]=cnt;
    tmp.push_back({a,b,c});
}

void solve()
{
    ll ans2=0;
    cin>>X>>Y>>Z;
    for(int i=0;i<50;i++)
    {
        for(int j=0;j<50;j++)
        {
            for(int k=0;k<50;k++)
            {
                ans[i][j][k]={-1,0};
                vis[i][j][k]=false;
            }
        }
    }

   for(int i=0;i<Z;i++)
   {
        for(int j=0;j<X;j++)
        {
            for(int k=0;k<Y;k++)
            {
                cin>>grid[i][j][k];
            }
        }
   }
   int com=0;
   for(int i=0;i<Z;i++)
   {
        for(int j=0;j<X;j++)
        {
            for(int k=0;k<Y;k++)
            {
                if(!vis[i][j][k] && grid[i][j][k]=='.') 
                {
                    cnt=0;
                    dfs(i,j,k);
                    //cerr<<cnt<<'\n';
                    for(auto [xx,yy,zz] : tmp) ans[xx][yy][zz]={com,cnt};
                    com++;
                    tmp.clear();
                }
            }
        }
   }
   cerr<<"ARAFAT\n";

   for(int i=0;i<Z;i++)
   {
        for(int j=0;j<X;j++)
        {
            for(int k=0;k<Y;k++)
            {
                cerr<<setw(4)<<ans[i][j][k].second;
            }
            cerr<<'\n';
        }
        cerr<<'\n';
   }
   cerr<<"\n\n";
   for(int i=0;i<X;i++)
   {
        for(int j=0;j<Y;j++)
        {
            ll t=0;
            set<int> cc;
            for(int k=0;k<Z;k++)
            {
                cerr<<ans[k][i][j].second;
                if(cc.find(ans[k][i][j].first) == cc.end())
                {cc.insert(ans[k][i][j].first);
                t+=ans[k][i][j].second;}
                while(k+1<Z && ans[k+1][i][j]==ans[k][i][j])
                {
                    k++;
                    //debug(k);
                }
            }
            ans2=max(ans2,t);
            //cerr<<'\n';
        }
        //cerr<<'\n';
   }

   print(ans2)
}

int32_t main()
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