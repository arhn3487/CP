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

#define ld long double

ld cal(array<ld,2> a,array<ld,2> b,array<ld,2> c)
{
    ld ans=a[0]*b[1]+b[0]*c[1]+c[0]*a[1]-a[1]*b[0]-b[1]*c[0]-c[1]*a[0];
    ans=abs(ans)*0.5;
    return ans;
}

void solve()
{
    array<ld,2> a,b,c,i,j,g,h,d,e;
    cin>>a[0]>>a[1]>>b[0]>>b[1]>>c[0]>>c[1]>>i[0]>>i[1]>>j[0]>>j[1];//abcij
    g[0]=3*i[0]-a[0]-b[0];
    g[1]=3*i[1]-a[1]-b[1];

    h[0]=3*j[0]-a[0]-c[0];
    h[1]=3*j[1]-a[1]-c[1];

    d[0]=g[0]+c[0]-a[0];
    d[1]=g[1]+c[1]-a[1];

    e[0]=g[0]+c[0]-b[0];
    e[1]=g[1]+c[1]-b[1];

    //debug(d,e,g,h);

    ld ans=cal(a,b,g)+cal(c,d,e);

    cout<<fixed<<setprecision(9)<<ans<<'\n';
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