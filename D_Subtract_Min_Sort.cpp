#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define YES cout << "YES\n";
#define NO cout << "NO\n";

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);

    for (ll i = 0; i < n; i++) cin >> a[i];

    ll mn = 0;  
    for (ll i = 0; i < n; i++) {
        if (a[i] < mn) {  
            NO return;
        }
        a[i] -= mn;  
        mn = a[i];   
    }
    YES
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
