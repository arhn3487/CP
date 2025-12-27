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
#define YES cout<<"Yes\n";
#define NO cout<<"No\n";

ll dist(ll x1,ll y1,ll x2,ll y2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

void solve()
{
    int n,x1,x2,y1,y2,mx=0;cin>>n>>x1>>y1>>x2>>y2;
    ll sum=0;
    vector<int>v(n);

    for(auto &x : v) cin>>x,sum+=x,mx=max(x,mx);

    ll d=dist(x1,y1,x2,y2);
    ll l=max(2*mx-sum,0LL),h=sum;
    l*=l,h*=h;

    //debug(d,l,h);

    if(sum*sum<d) NO
    else if(d>=l && d<=h) YES
    else NO
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