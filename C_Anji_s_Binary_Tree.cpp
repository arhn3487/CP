#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

string str;
int ans;

void dfs(int node,vector<pair<int,int>> &grp,int op)
{
    if(node==0) return;
   // cout<<node<<endl;
    if(grp[node].first==0 && grp[node].second==0)
    {
        //cout<<node<<" "<<op<<'\n';
        ans=min(ans,op);
        return;
    }
    if(str[node]=='L')
    {
        dfs(grp[node].first,grp,op);
        dfs(grp[node].second,grp,op+1);
    }
    else if(str[node]=='R')
    {
        dfs(grp[node].first,grp,op+1);
        dfs(grp[node].second,grp,op);
    }
    else
    {
        dfs(grp[node].first,grp,op+1);
        dfs(grp[node].second,grp,op+1);
    }
}

void solve()
{
    int n,u,v;
    cin>>n>>str;
    str='#'+str;
    ans=INT_MAX;

    vector<pair<int,int>> adg(n+1);
    
    for(int i=1;i<=n;i++)
    {
        cin>>u>>v;
        adg[i].first=u;
        adg[i].second=v;
    }
    // for(auto x : adg)
    // {
    //    cout<<x.first<<" "<<x.second<<endl;
    // }

    dfs(1,adg,0);
    cout<<ans<<endl;
}

int main()
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