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
    int n,k=0;cin>>n;
    vector<array<int,3>> v(n);

    for(int i=0;i<n;i++)
    {
        cin>>v[i][0];
        v[i][1]=i;
        v[i][2]=-1;
    }

    sort(all(v));

    for(int i=0;i<n;i++)
    {
        v[i][2]=k;
        k=k^1;
    }

    vector<int> res(n);

    for(int i=0;i<n;i++)
    {
        res[v[i][1]]=v[i][2];
    }

    for(int i=1;i<n;i++)
    {
        if(res[i]==res[i-1])
        {
            yes(0)
            return;
        }
    }

    debug(res);

    yes(1)
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