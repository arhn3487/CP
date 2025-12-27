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

void solve()
{
    ld ab,ad,a;
    cin>>ab>>ad>>a;
    a=a*M_PI/180;
    ld bds=ab*ab+ad*ad-2*ab*ad*cos(a);
    ld bd=sqrtl(bds);
    ld bc=2*bd;
    ld val=ab*(sin(a)/bd);
    val=max((ld)-1.0,min((ld)1.0,val));
    ld d=asin(val);
    ld b=M_PI-d-a;
    ld acs=ab*ab+bc*bc-2*ab*bc*cos(b);
    cout<<fixed<<setprecision(9)<<acs+ab*ab<<'\n';
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