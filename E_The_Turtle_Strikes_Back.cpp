#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
const ll INF = 1e18;

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    // ১-বেসড ইনডেক্সিং এর জন্য (n+2) সাইজ
    vector<vector<ll>> a(n + 2, vector<ll>(m + 2));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    // dpS: (1,1) থেকে (i,j) পর্যন্ত ম্যাক্সিমাম এনজয়মেন্ট
    vector<vector<ll>> dpS(n + 2, vector<ll>(m + 2, -INF));
    dpS[1][1] = a[1][1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) continue;
            dpS[i][j] = max(dpS[i - 1][j], dpS[i][j - 1]) + a[i][j];
        }
    }

    // dpT: (i,j) থেকে (n,m) পর্যন্ত ম্যাক্সিমাম এনজয়মেন্ট
    vector<vector<ll>> dpT(n + 2, vector<ll>(m + 2, -INF));
    dpT[n][m] = a[n][m];
    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            if (i == n && j == m) continue;
            dpT[i][j] = max(dpT[i + 1][j], dpT[i][j + 1]) + a[i][j];
        }
    }

    ll maxS = dpS[n][m];

    // ম্যাক্স এনজয়মেন্ট পাথ S বের করা
    vector<pair<int, int>> path;
    int r = n, c = m;
    while (r >= 1 && c >= 1) {
        path.push_back({r, c});
        if (r == 1 && c == 1) break;
        if (r > 1 && dpS[r][c] == dpS[r - 1][c] + a[r][c]) r--;
        else c--;
    }
    reverse(path.begin(), path.end());

    // রো এবং কলাম প্রিফিক্স ম্যাক্সিমাম (বাইডাইরেকশনাল চেক এর জন্য)
    vector<vector<ll>> row_max(n + 2, vector<ll>(m + 2, -INF));
    vector<vector<ll>> col_max(n + 2, vector<ll>(m + 2, -INF));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ll val = dpS[i][j] + dpT[i][j] - a[i][j];
            row_max[i][j] = max(row_max[i][j - 1], val);
            col_max[i][j] = max(col_max[i - 1][j], val);
        }
    }

    ll result = INF;
    // রাফায়েল পাথের ওপরের প্রতিটি সেল ব্লক করার ট্রাই করবে
    for (auto& sk : path) {
        int i = sk.first;
        int j = sk.second;

        // অপশন ১: অরিজিনাল পাথে থাকা
        ll opt1 = maxS - 2 * a[i][j];

        // অপশন ২: বাইপাস পাথ (i,j কে এড়িয়ে চলা)
        ll dp_k = -INF;
        if (i < n && j > 1) dp_k = max(dp_k, row_max[i + 1][j - 1]);
        if (j < m && i > 1) dp_k = max(dp_k, col_max[i - 1][j + 1]);

        // মিকেলাঞ্জেলো নিবে ম্যাক্সিমাম, রাফায়েল করবে মিনিমাইজ
        result = min(result, max(opt1, dp_k));
    }

    cout << result << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}