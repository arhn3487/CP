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

ll cut1(ll w,ll h)
{
    ll u=(w+2)/3,l=w/3;
    //cout<<u<<'';
    return h*(u-l);
}

ll cut2(ll w,ll h)
{
    ll res=infinity;
    for(int i=1;i<=w/2;i++)
    {
        ll a=i*h;
        ll rem=(w-i)*h;
        ll b=(h/2)*(w-i);
        ll c=rem-b;
        ll mx=max({a,b,c});
        ll mn=min({a,b,c});

        res=min(res,mx-mn);
        //cout<<t1<<" "<<h/2<<' '<<w-i<<"  "<<t2<<" "<<mnn<<'\n';
    }
    return res;
}



void solve()
{
    ll h,w;
    cin>>h>>w;
    if(h%3==0 || w%3==0)
    {
        cout<<0<<'\n';
        return;
    }
    ll mn=cut1(w,h);
    //debug(mn);
    mn=min(mn,cut1(h,w));
    //debug(mn);
    mn=min(mn,cut2(h,w));
    //debug(mn);
    mn=min(mn,cut2(w,h));

    cout<<mn<<'\n';
    //cout<<(h%3)*(w%3)<<'\n';
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
