#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<int> bitCount(30, 0);

    for (int num : a) {
        for (int bit = 0; bit < 30; ++bit) {
            if (num & (1 << bit)) {
                bitCount[bit]++;
            }
        }
    }

    int maxSum = 0;

    for (int k = 0; k < n; ++k) {
        int sum = 0;
        for (int bit = 0; bit < 30; ++bit) {
            int cnt1 = bitCount[bit];
            int cnt0 = n - cnt1;
            if (a[k] & (1 << bit)) {
                sum += cnt0 * (1 << bit);
            } else {
                sum += cnt1 * (1 << bit);
            }
        }
        maxSum = max(maxSum, sum);
    }

    cout << maxSum << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
