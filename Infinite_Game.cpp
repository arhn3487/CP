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

void solve()
{
    ld r,x1,x2,y;
    cin>>r>>x1>>x2>>y;
    if(x1>x2) swap(x1,x2);

    ld theta1=2*acos(min(x1,r)/r),theta2=2*acos(min(x2,r)/r);
    ld ar1=0.5*theta1*r*r-0.5*r*r*sin(theta1),ar2=0.5*theta2*r*r-0.5*r*r*sin(theta2);
    ld tom=ar1-ar2;
    ld odti=M_PI*r*r-tom;
    ld sam=2*y*(x2-x1)-tom;
    sam/=2;

    cout<<fixed<<setprecision(3);
    cout<<odti<<' '<<sam<<' '<<sam<<' '<<tom<<'\n';

    debug(odti,sam,tom);
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