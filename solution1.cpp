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

void solve()
{
    ll n,k,x;
    cin>>k>>x;

    ll total=(1<<(k+1));
    ll a=x,b=total-x;
    vector<ll> v;

    //debug(a,b);

    while(a!=b)
    {
        if(a<b)
        {
            ll tmp=a;
            a*=2;
            b-=tmp;
            v.push_back(1);
        }
        else
        {
            ll tmp=b;
            b*=2;
            a-=tmp;
            v.push_back(2);
        }
        //debug(a,b);
    }

    cout<<v.size()<<'\n';

    reverse(all(v));
    for(auto x : v) cout<<x<<' ';
    cout<<'\n';
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