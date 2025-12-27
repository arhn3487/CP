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

vector<ll> v=
{
11,
101,
1001,
10001,
100001,
1000001,
10000001,
100000001,
1000000001,
10000000001,
100000000001,
1000000000001,
10000000000001,
100000000000001,
1000000000000001,
10000000000000001,
100000000000000001
};

void solve()
{
    ll n;cin>>n;
    vector<ll> vec;
    ll p=10;
    for(int i=1;i<=18;i++)
    {
        ll tgt=p+1;
        if(n%tgt==0) vec.push_back(n/tgt);
        p*=10;
        //cout<<p<<'\n';
    }

    sort(all(vec));
    cout<<vec.size()<<'\n';
    if(vec.size())
    {
        for(auto x : vec) cout<<x<<' ';
        cout<<'\n';
    }
    
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