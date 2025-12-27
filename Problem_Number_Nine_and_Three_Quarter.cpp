#pragma GCC optimize("O3")
#include<bits/stdc++.h>

#ifndef ONLINE_JUDGE
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

long double deg2rad(ld deg)
{
    ld res=M_PI/180;
    return deg*res;
}

void solvee()
{
    ld bh,cbh;
    cin>>bh>>cbh;
    cbh=deg2rad(cbh);
    ld eh=bh*sin(cbh/2);
    ld be=bh/cos(cbh/2);
    ld bc=2*bh*cos(cbh);
    ld bn=2*bh*cos(cbh/2);
    ld ne=bn-be;
    ld nbh=cbh/2;
    ld beh=(M_PI/2)-nbh;
    ld nei=beh;
    ld bd=bc/2;
    ld dnsq=bd*bd+bn*bn-2*bd*bn*cos(cbh/2);
    ld dn=sqrtl(dnsq);
    ld bnd=asin(bd*(sin(cbh/2)/dn));

    ld he=ne*sin(bnd)/sin(nei);

    cout<<fixed<<setprecision(6);
    cout<<eh+he<<'\n';

}

void solve() {
    ld r, angle;
    cin >> r >> angle;
    ld rad = deg2rad(angle);
    ld result = (r * sin(rad)) / (sin(rad)*sin(rad) + cos(rad));
    cout << fixed << setprecision(10) << result << '\n';
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