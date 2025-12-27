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

const int N=5e5+3;

vector<int> adj[N];
map<int,int> freq[N];
vector<pair<int,int>> query[N];
int ans[N];
string s;
int n,q;

void dfs(int node,int depth)
{
    freq[node][depth]=1<<(s[node]-'a');
    for(auto x : adj[node])
    {
        dfs(x,depth+1);
        if(freq[node].size()<freq[x].size()) swap(freq[node],freq[x]);

        for(auto [ind,fq] : freq[x]) freq[node][ind]=freq[node][ind]^fq;
    }

    for(auto [ind,h] : query[node])
    {
        int k=freq[node][h];
        if(k==0 || (k&(k-1))==0) ans[ind]=1;
    }
}

void solve()
{
    cin>>n>>q;
    for(int i=1;i<n;i++)
    {
        int a;cin>>a;a--;
        adj[a].push_back(i);
    }

    cin>>s;

    for(int i=0;i<q;i++)
    {
        int a,h;cin>>a>>h;a--;
        query[a].push_back({i,h});
    }

    dfs(0,1);

    for(int i=0;i<q;i++) yes(ans[i])
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
