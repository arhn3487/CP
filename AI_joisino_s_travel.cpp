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

vector<vector<ll>> g(205,vector<ll>(205,INT_MAX));
vector<int> v;
int n,m,r;

void solve()
{
    ll mn=infinity;
    for(int i=0;i<205;i++) g[i][i]=0;

    cin>>n>>m>>r;
    for(int i=0;i<r;i++)
    {
        int a;cin>>a;
        a--;
        v.push_back(a);
    }

    for(int i=0;i<m;i++)
    {
        ll a,b,c; cin>>a>>b>>c;
        a--,b--;
        g[a][b]=c;g[b][a]=c;
    }


    sort(all(v));

    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(g[i][j]>g[i][k]+g[k][j]) g[i][j]=g[i][k]+g[k][j];
            }
        }
    }

    do
    {
        ll cost=0;

        for(int i=1;i<r;i++) cost+=g[v[i-1]][v[i]];

        mn=min(mn,cost);
    } while (next_permutation(all(v)));

    cout<<mn<<'\n';
    
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