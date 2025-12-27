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
const ll M=1e9+7;
const ll infinity = LLONG_MAX;
ll dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
ll dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define prll(x) cout<<x<<'\n';
#define yes(x) cout << ((x) ? "Yes\n" : "No\n");



void solve()
{
    ll nijer_modde=0,add_remove=0,n;
    cin>>n;

    while(n--)
    {
        ll z,o,tz,to;
        cin>>z>>o>>tz>>to;
        add_remove=add_remove+abs(z-tz)+abs(o-to);
        if(to<o) add_remove+=2*min(tz,z);
    }

    cout<<add_remove/2+nijer_modde<<'\n';

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t=1;
    cin>>t;

    for(ll i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<": ";
        solve();
    }
}