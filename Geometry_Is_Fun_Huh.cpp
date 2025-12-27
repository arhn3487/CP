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
    ld r,c;cin>>r>>c;
    ld ctheta=(2*r*r-c*c)/(2*r*r);
    //ctheta=max((ld)-1.0,min((ld)1.0,ctheta));
    //ctheta*=(M_PI/180);
    ld pi=acosl(-1);
    ld theta=acosl(ctheta);
    debug(ctheta,theta);
    //theta/=2;
    theta*=(180.0L/pi);
    cout<<fixed<<setprecision(4)<<(180-theta)/2<<'\n';
}

void solvee()
{
    ld r,c;cin>>r>>c;
    ld ctheta=(2*r*r-c*c)/(2*r*r);
    ctheta=max((ld)-1.0,(ld)min((ld)1.0,ctheta));

    ld PI = acosl(-1.0L);
    ld theta = acosl(ctheta);
    theta *= (180.0L / PI);

    cout<<fixed<<setprecision(4)<<(180-theta)/2<<'\n';
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