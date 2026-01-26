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
    int n,q;cin>>n>>q;

    vector<int> a(n),b(n);

    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;

    a[n-1]=max(a[n-1],b[n-1]);

    for(int i=n-2;i>=0;i--)
    {
        a[i]=max({a[i],a[i+1],b[i]});
    }

    for(int i=1;i<n;i++) a[i]+=a[i-1];

    debug(a);

    while(q--)
    {
        int l,r;
        cin>>l>>r;

        cout<<a[r-1]-((l==1) ? 0 : a[l-2])<<' ';
    }
    cout<<'\n';
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