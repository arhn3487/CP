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
    int n,a,b,lo=0,hi=1e9+7;
    cin>>n>>a>>b;
    int diff=a-b;
    vector<int> v(n);

    for(auto &x : v) cin>>x;

    while (lo<=hi)
    {
        int mid=(lo+hi)/2,ext=0;
        for(auto x : v)
        {
            if(b*mid>=x) continue;
            x-=b*mid;
            ext+=ceil(x*1.0/diff);
        }

        if(ext>mid) lo=mid+1;
        else hi=mid-1;
    }

    print(lo)
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    
    for (int i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}