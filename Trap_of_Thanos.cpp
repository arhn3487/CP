#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define debug(x...)
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

#define ld long double

pair<ld,ld> md(pair<ld,ld> a,pair<ld,ld> b)
{
    return {(a.first+b.first)/2,(a.second+b.second)/2};
}

ld dist(pair<ld,ld> a,pair<ld,ld> b)
{
    ld x=a.first-b.first,y=a.second-b.second;
    x*=x;y*=y;
    return sqrtl(x+y);
}

void solve()
{
    ld ans;
    pair<ld,ld> a,b,c,mid;
    cin>>a.first>>a.second>>b.first>>b.second>>c.first>>c.second;
    char ch;cin>>ch;

    if(ch=='A') 
    {
        mid=md(b,c);
        ans=dist(mid,a);
    }
    else if(ch=='B') 
    {
        mid=md(a,c);
        ans=dist(mid,b);
    }
    else 
    {
        mid=md(a,b);
        ans=dist(mid,c);
    }

    cout<<fixed<<setprecision(3)<<ans<<'\n';
    
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
        cout<<"Case "<<i<<": ";
        solve();
    }
}