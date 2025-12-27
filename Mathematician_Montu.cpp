#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll count_gcd(ll n, ll m) {
    ll cnt = 0,k=0;
    for (ll i = m; i <= n; i+=m) {
        if (__gcd(n, i) == m) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        ll n, q;
        cin >> n >> q;

        vector<ll> queries(q);
        for (int i = 0; i < q; ++i) {
            cin >> queries[i];
        }

        cout << "Case " << tc << ": ";
        for (ll m : queries) {
            cout << count_gcd(n, m) << " ";
        }
        cout << endl;
    }

    return 0;
}
