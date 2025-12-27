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

ld dist(ld x1,ld y1,ld x2,ld y2)
{
    ld a=(x1-x2);
    ld b=(y1-y2);
    return sqrtl(a*a+b*b);
}

void solve()
{
    ld x1,x2,y1,y2,d,c,a,b,res,l;
    cin>>x1>>y1>>x2>>y2>>l;

    d=dist(x1,y1,x2,y2);
    c=d/2;
    a=l/2;
    //a^2=b^2-c^2;
    b=a*a-c*c;
    b=sqrtl(b);

    cout<<fixed<<setprecision(10)<<M_PI*a*b<<'\n';
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