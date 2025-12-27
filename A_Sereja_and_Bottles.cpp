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

int find_parent(int a,vector<int> &parent)
{
    if(parent[a]==a) return a;
    return parent[a]=find_parent(parent[a]);
}

void union_(int a,int b,vector<int> &parent,vector<int> &size)
{
    a=find_parent(a,parent);
    b=find_parent(b,parent);

    if(a!=b)
    {
        parent[a]=b;
        size[b]+=1;
    }
}

void solve()
{
    int n,cnt=0;
    cin>>n;
    vector<int> parent(n),size(n,1)

    for(int i=0;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        u--,v--;

        union_(u,v);
    }

    for(int i=0;i<n;i++)
    {
        if(parent[i]!=i) cnt++;
    }

    if(cnt==n) cout<<n<<'\n';
    else cout<<cnt<<'\n';
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