#include <bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const ll M = 1e9 + 7;
const ll infinity = LLONG_MAX;
ll dx[] = {1, 0, -1, 0, 1, 1, -1, -1}; // Right, Down, Left, Up, Right-Up, Right-Down, Left-Up, Left-Down
ll dy[] = {0, -1, 0, 1, 1, -1, 1, -1};
inline ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }

#define rall(v) v.rbegin(), v.rend()
#define all(v) v.begin(), v.end()
#define prll(x) cout << x << '\n';
#define YES cout << "YES\n";
#define NO cout << "NO\n";

set<vector<ll>> dp;

ll rec(vector<ll> &vec) {
    if (vec.size() == 1) return vec[0];
    if (dp.find(vec) != dp.end()) return LLONG_MIN;
    dp.insert(vec);

    ll mx = accumulate(all(vec), 0LL); 
    vector<ll> rev_vec = vec;
    reverse(all(rev_vec));
    mx = max(mx, rec(rev_vec));

    vector<ll> trans = vec; 
    for (int i = 0; i < trans.size() - 1; i++) { 
        trans[i] = trans[i + 1] - trans[i];
    }
    trans.pop_back();

    mx = max(mx, rec(trans));

    return mx;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);

    for (ll i = 0; i < n; i++) cin >> v[i];

    dp.clear();

    ll ans = rec(v);

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    cin >> t;

    for (ll i = 1; i <= t; i++) {
        // cout<<"Case "<<i<<": ";
        solve();
    }
}
