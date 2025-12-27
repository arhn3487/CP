#include<bits/stdc++.h>
//#include "D:/debug.h"
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

int find_par(int a,vector<int> &par)
{
    if(par[a]==a) return a;
    return par[a]=find_par(par[a],par);
}

void marge(int a,int b,vector<int> &par,vector<int> &sz)
{
    a=find_par(a,par),b=find_par(b,par);

    if(a!=b)
    {
        if(sz[a]<sz[b]) swap(a,b);
        par[b]=a;
        sz[a]+=sz[b];
    }
}

void solve()
{
    int n,m1,m2;
    cin>>n>>m1>>m2;

    vector<int> par1(n+1),par2(n+1),sz1(n+1,1),sz2(n+1,1);

    for(int i=0;i<=n;i++)
    {
        par1[i]=i;
        par2[i]=i;
    }

    for(int i=0;i<m1;i++)
    {
        int u,v;
        cin>>u>>v;

        marge(u,v,par1,sz1);
    }
    for(int i=0;i<m2;i++)
    {
        int u,v;
        cin>>u>>v;

        marge(u,v,par2,sz2);
    }

    vector<pair<int,int>> ans;

    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int p=find_par(i,par1);
            int q=find_par(j,par1);
            int r=find_par(i,par2);
            int s=find_par(j,par2);

            if(p!=q && r!=s)
            {
                ans.push_back({i,j});
                marge(i,j,par1,sz1);
                marge(i,j,par2,sz2);
            }
        }
    }

    cout<<ans.size()<<'\n';
    for(auto p : ans) cout<<p.first<<' '<<p.second<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    //cin>>t;

    for(int i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<": ";
        solve();
    }
}