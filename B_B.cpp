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
    ll x,y;
    cin>>x>>y;
    
    if(x&1LL || y&1LL)
    {
        cout<<-1<<'\n';
        return;
    }

    for(int i=0;i<x/2;i++) cout<<'a';
    for(int i=0;i<y;i++) cout<<'b';
    for(int i=0;i<x/2;i++) cout<<'a';
    cout<<'\n';

    for(int i=0;i<y/2;i++) cout<<'b';
    for(int i=0;i<x;i++) cout<<'a';
    for(int i=0;i<y/2;i++) cout<<'b';
    cout<<'\n';
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