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

vector<pair<int,int>> v;
vector<int> c;
int n,g,ans=INT_MAX; 
map<pair<ll,ll>,ll> dp;

void rec(int ind,ll sum,int cnt=0)
{
    if(sum>=g)
    {
        ans=min(ans,cnt);
        return;
    }

    pair<ll,ll> state={ind,sum};
    if(dp.count(state) && dp[state]<=cnt) return;
    dp[state]=cnt;
    //debug(sum,ind);
    if(ind==n) return;
    for(int i=0;i<=v[ind].first;i++)
    {
        if(i!=v[ind].first) rec(ind+1,sum+i*(ind+1)*100,cnt+i);
        else rec(ind+1,sum+i*(ind+1)*100+v[ind].second,cnt+i);
    }
}


void solve()
{
    cin>>n>>g;
    v.resize(n);
    c.resize(n);

    for(auto &[x,y] : v) cin>>x>>y;

    //for(auto &x : c) cin>>x;
    rec(0,0);

    cout<<ans<<'\n';
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