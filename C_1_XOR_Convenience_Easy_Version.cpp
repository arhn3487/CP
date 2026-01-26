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
    int n;cin>>n;
    vector<bool>pre(n+1,false);
    vector<int> v(n+1,false);

    v[n]=1;
    vector<bool> kk(n+1,false);

    for(int i=n-1;i>=2;i--)
    {
        v[i]=1^i;
        kk[1^i]=true;
    }

    for(int i=2;i<=n;i++)
    {
        if(!kk[i]) 
        {
            v[1]=i;
        }
    }



    for(int i=1;i<=n;i++) cout<<v[i]<<' ';
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