#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int M = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n + 1, -1), rev(n + 1, -1), rev_v(n + 1, -1);
    map<int, int> mp, revmp;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bool f = false;


    for (int i = 1; i <= n; i++) {
        int x = arr[i - 1];
        mp[x]++;
        if (mp[x] > mp[v[i - 1]]) v[i] = x;
        else if (mp[x] < mp[v[i - 1]]) v[i] = v[i - 1];
        else {
            if (v[i - 1] == k) v[i] = k;
            else v[i] = x;
        }
        if (v[i] == k) f = true;
    }

    for (int i = n - 1; i >= 0; i--) {
        int x = arr[i];
        revmp[x]++;
        if (revmp[x] > revmp[rev_v[i + 1]]) rev_v[i] = x;
        else if (revmp[x] < revmp[rev_v[i + 1]]) rev_v[i] = rev_v[i + 1];
        else {
            if (rev_v[i + 1] == k) rev_v[i] = k;
            else rev_v[i] = x;
        }
        if (rev_v[i] == k) f = true;
    }

    if (v[n] == k || rev_v[0] == k) cout << 0 << '\n';
    else if (f) cout << 1 << '\n';
    else cout << 2 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
