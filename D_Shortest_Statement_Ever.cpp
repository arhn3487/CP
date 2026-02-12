#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define debug(x...)
#endif
using namespace std;

#define ll long long
#define ld long double
#define int long long
const int M = 1e9 + 7;
const int N = 1e6 + 5;
const ll infinity = LLONG_MAX;
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1}; //Right, Down, Left, Up, Diagonals
int dy[] = {0, -1, 0, 1, 1, -1, 1, -1};
inline ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }

#define rall(v) v.rbegin(), v.rend()
#define all(v) v.begin(), v.end()
#define print(x) cout << x << '\n';
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

void solve() 
{
    int x,y;cin>>x>>y;
    int p1=x,q1=y,p2=x,q2=y;
    int ly=log2l(y),lx=log2l(x);

    if(x==0 && y==0) 
    {
        cout<<"0 0\n";
        return;
    }

    if((1ll<<lx)==x && (1LL<<ly)==y && x==y)
    {
        //100 4 4
        //011
        cout<<x<<' '<<x-1<<'\n';
        return;
    }

    if((1ll<<lx)==(x+1) && (1LL<<ly)==(y+1) && x==y)
    {
        //100 4 4
        //011
        cout<<x<<' '<<x-1<<'\n';
        return;
    }
    debug("ARAFAT");
    
    for(int i=0;i<60;i++)
    {
        int bit=(1LL<<i);
        if(((x&bit) && (y&bit))) q1=q1&(~bit);
    }
    for(int i=0;i<60;i++)
    {
        int bit=(1LL<<i);
        if(((x&bit) && (y&bit))) p1=p1&(~bit);
    }

    if(abs(x-p1)>abs(y-q1)) cout<<x<<' '<<q1<<'\n';
    else cout<<p1<<' '<<y<<'\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}