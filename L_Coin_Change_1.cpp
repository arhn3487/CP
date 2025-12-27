#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = LLONG_MAX;

void solve() {
    ll n, x;
    cin >> n >> x;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++) cin >> v[i];
    
    // DP array, initialize with INF
    vector<ll> dp(x + 1, INF);
    dp[0] = 0; // Base case: 0 coins to make sum 0
    
    // Bottom-up DP to calculate minimum coins
    for (ll i = 0; i < n; i++) {
        for (ll j = v[i]; j <= x; j++) {
            if (dp[j - v[i]] != INF) {
                dp[j] = min(dp[j], dp[j - v[i]] + 1);
            }
        }
    }
    
    cout << (dp[x] == INF ? -1 : dp[x]) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    for (ll i = 1; i <= t; i++) {
        solve();
    }
}
