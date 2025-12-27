#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(), v.end()
#define print(x) cout << x << '\n';
#define YES cout << "YES\n";
#define NO cout << "NO\n";

const int MAXN = 1e5 + 5;
const int SQRTN = 350;  // Approximate sqrt(100000)

int arr[MAXN], freq[MAXN], answer[MAXN], distinct_count;
struct Query {
    int l, r, idx;
    bool operator<(const Query &q) const {
        if (l / SQRTN == q.l / SQRTN)
            return r < q.r;
        return (l / SQRTN) < (q.l / SQRTN);
    }
};

void add(int pos) {
    freq[arr[pos]]++;
    if (freq[arr[pos]] == 1)
        distinct_count++;
}

void remove(int pos) {
    if (freq[arr[pos]] == 1)
        distinct_count--;
    freq[arr[pos]]--;
}

void mo_algorithm(vector<Query> &queries) {
    sort(all(queries));  // Sort queries using Mo's order
    int l = 0, r = -1;
    distinct_count = 0;
    memset(freq, 0, sizeof(freq));

    for (auto q : queries) {
        while (r < q.r) add(++r);
        while (l > q.l) add(--l);
        while (r > q.r) remove(r--);
        while (l < q.l) remove(l++);
        answer[q.idx] = distinct_count;
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<Query> queries(q);
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        queries[i] = {l - 1, r - 1, i};
    }

    mo_algorithm(queries);

    for (int i = 0; i < q; i++) print(answer[i]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ":\n";
        solve();
    }
}
