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
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");
#define int long long
const int N=2e5+3;
int depth[N],ans[N];
vector<int> g[N];

int dfs1(int node,int par)
{
    int mx=0;
    for(auto x : g[node])
    {
        if(x!=par) mx=max(1+dfs1(x,node),mx);
    }
    return depth[node]=mx;
}

void dfs2(int node,int par,int par_ans)
{
    vector<int> pre_max,suf_max;

    for(auto x : g[node])
    {
        if(x!=par)
        {
            pre_max.push_back(depth[x]);
            suf_max.push_back(depth[x]);
        }
    }

    for(int i=1;i<pre_max.size();i++)
    {
        pre_max[i]=max(pre_max[i-1],pre_max[i]);
    }

    for(int i=suf_max.size()-2;i>=0;i--)
    {
        suf_max[i]=max(suf_max[i],suf_max[i+1]);
    }

    int cnt=0;

    for(auto x : g[node])
    {
        if(x==par) continue;
        int op1=(cnt==0) ? -1 : pre_max[cnt-1];
        int op2=(cnt==(suf_max.size()-1)) ? INT_MIN : suf_max[cnt+1];
        int par_ans_tmp=1+max(par_ans,max(op1,op2));
        //debug(par_ans,op1,op2);
        dfs2(x,node,par_ans_tmp);
        cnt++;
    }
    //debug(node,pre_max,suf_max,par_ans);
    ans[node] = 1 + max(par_ans, (pre_max.empty() ? -1 : pre_max.back()));
    
    //ans[node]= 1+max(par_ans,depth[node]-1);
}



void solve()
{
    int n;cin>>n;

    for(int i=1;i<n;i++)
    {
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs1(1,0);
    dfs2(1,-1,INT_MIN);

    //debug(depth[1],depth[2]);

    for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
    cout<<'\n';
}


int32_t main()
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