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
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

int n,m;
map<int,int> mp;

int rec(int k)
{
    if(mp.count(k)) return mp[k];
    int a=k/2,b=k-a;
    if(a==m or b==m) return 1;
    int ans1=INT_MAX,ans2=INT_MAX;
    if(a>=m) ans1=1+rec(a);
    if(b>=m) ans2=1+rec(b);
    return mp[k]=min(ans1,ans2);
}

void solve()
{
    cin>>n>>m;
    mp.clear();
    if(n==m) cout<<0<<'\n';
    else
    {
        int ans=rec(n);
        if(ans>=INT_MAX) cout<<-1<<'\n';
        else cout<<ans<<'\n';
        debug(ans,INT_MAX);
    }
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