#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

void solve()
{
    ll k;
    cin>>k;
    //2,3,5,7
    ll n2=k/2,n3=k/3,n5=k/5,n7=k/7,n23=k/6,n25=k/10,n27=k/14,n35=k/15,n37=k/21,n57=k/35,n235=k/30,n257=k/70,n237=k/42,n357=k/105,n2357=k/210;

    cout<<k-(n2+n3+n5+n7-n23-n25-n27-n35-n37-n57+n235+n257+n237+n357-n2357)<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    //cin>>t;

    for(int i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<": ";
        solve();
    }
}