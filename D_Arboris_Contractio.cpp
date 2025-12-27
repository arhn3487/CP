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
#define yes(x) cout << ((x) ? "Yes\n" : "No\n");

vector<int> leaf;

int dfs(int node,int p,vector<int> g[])
{
    if(g[node].size()==1) return 1;
    int tl=0;

    for(auto x : g[node])
    {
        if(x!=p)
            tl+=dfs(x,node,g);
    }

    leaf[node]=tl;
    return 0;
}

void solve()
{
    int n,sum=0,mx=0;cin>>n;
    vector<int> g[n];
    vector<bool> is_leaf(n,false);
    vector<int> leaf_count(n,0);
    leaf.assign(n,0);

    for(int i=1;i<n;i++)
    {
        int a,b;cin>>a>>b;
        a--,b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i=0;i<n;i++)
    {
        if(g[i].size()==1) is_leaf[i]=true;
        sum+=is_leaf[i];
    }

    for(int i=0;i<n;i++)
    {
        int tmp=0;
        for(auto x : g[i])
        {
            if(is_leaf[x]) tmp++;
        }

        leaf_count[i]=tmp;
        mx=max(leaf_count[i],mx);
    }

    if(n==2)
    {
        cout<<0<<'\n';
        return;
    }

    //debug(sum,mx);

    cout<<sum-mx<<'\n';

    //dfs(0,-1,g);

    // for(auto x : leaf)
    // {
    //     sum+=x;
    //     mx=max(mx,x);
    // }

    // cout<<sum-mx<<'\n';
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