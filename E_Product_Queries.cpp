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
    vector<bool> present(n+1,false);
    vector<int> dp(n+1,-1);

    for(int i=0;i<n;i++)
    {
        int a;cin>>a;
        present[a]=true;
    }

    for(int i=1;i<=n;i++)
    {
        if(present[i]) dp[i]=1;
        else
        {
            int a=infinity;
            for(int j=2;j*j<=i;j++)
            {
                if(i%j==0)
                {
                    debug(i,j);
                    if(dp[j]!=-1 && dp[i/j]!=-1) a=min(a,dp[j]+dp[i/j]);
                }
            }

            dp[i]=(a!=infinity) ? a : -1;
        }
    }

    for(int i=1;i<=n;i++) cout<<dp[i]<<' ';
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