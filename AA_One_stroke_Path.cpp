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

void solve()
{
    int n,m;cin>>n>>m;
    ll cnt=0;
    vector<vector<bool>> adj(n,vector<bool>(n,false));

    for(int i=0;i<m;i++)
    {
        int a,b;cin>>a>>b;
        a--,b--;
        adj[a][b]=adj[b][a]=true;
    }

    vector<int> v;
    for(int i=1;i<n;i++) v.push_back(i);

    do
    {
        bool ok=true;
        int prev=0;
        for(auto x : v)
        {
            if(!adj[prev][x])
            {
                ok=false;
                break;
            }
            prev=x;
        }
        if(ok) cnt++;
    }
    while(next_permutation(all(v)));

    cout<<cnt<<'\n';
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