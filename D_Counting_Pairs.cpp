#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(), v.end()

void solve() {
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> v(n);
    ll total = 0;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        total += v[i];
    }

    sort(all(v));
    ll res = 0;

    for (int i = 0; i < n; i++) {
        ll remaining_sum = total - v[i];
        ll l =  remaining_sum-x; // Minimum valid pair value
        ll r = remaining_sum-y; // Maximum valid pair value

        auto low = lower_bound(v.begin()+i, v.end() + i, l); // Find first valid pair
        auto high = upper_bound(v.begin(), v.end() + i, r); // Find last valid pair

        if(*high-*low>0)res += (high - low);

        cout<<*low<<" "<<*high<<" "<<l<<" "<<r<<endl;
    }

    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
