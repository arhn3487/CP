#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

#ifndef ONLINE_JUDGE
    #include "D:/debug.h"
#else
    #define dbg(x...)
    #define dbgc(x...)
#endif

const int MOD = 1e9 + 7;
const ll INF = LLONG_MAX;
const int MAXN = 500005;

int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, -1, 0, 1, 1, -1, 1, -1};

#define rall(v) v.rbegin(), v.rend()
#define all(v) v.begin(), v.end()
#define print(x) cout << x << endl
#define yes(x) cout << ((x) ? "YES" : "NO") << endl

inline ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }

vector<ll> seg, lazy;
vector<set<int>> level_positions;
vector<int> dragon_level;

void propagate(int node, int range_i, int range_j) {
    if (lazy[node] != 0) {
        seg[node] += lazy[node];
        if (range_i != range_j) {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int i, int j, int val, int node, int range_i, int range_j) {
    propagate(node, range_i, range_j);
    if (range_i > j || range_j < i) return;
    if (range_i >= i && range_j <= j) {
        lazy[node] += val;
        propagate(node, range_i, range_j);
        return;
    }
    int mid = (range_i + range_j) / 2;
    update(i, j, val, 2*node, range_i, mid);
    update(i, j, val, 2*node+1, mid+1, range_j);
    seg[node] = max(seg[2*node], seg[2*node+1]);
}

ll query(int i, int j, int node, int range_i, int range_j) {
    propagate(node, range_i, range_j);
    if (range_i > j || range_j < i) return 0;
    if (range_i >= i && range_j <= j) return seg[node];
    int mid = (range_i + range_j) / 2;
    return max(query(i, j, 2*node, range_i, mid), query(i, j, 2*node+1, mid+1, range_j));
}

void solve() {
    int n, q;
    cin >> n >> q;
    
    seg.assign(4 * n, 0);
    lazy.assign(4 * n, 0);
    level_positions.resize(500005);
    dragon_level.assign(n + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        level_positions[0].insert(i);
    }
    
    while (q--) {
        int op, l, r;
        cin >> op >> l >> r;
        
        if (op == 1) {
            int x;
            cin >> x;
            
            auto it = level_positions[x].lower_bound(l);
            vector<int> to_update;
            
            while (it != level_positions[x].end() && *it <= r) {
                to_update.push_back(*it);
                it++;
            }
            
            for (int pos : to_update) {
                level_positions[x].erase(pos);
                level_positions[x + 1].insert(pos);
                dragon_level[pos] = x + 1;
                update(pos, pos, -x, 1, 1, n);
                update(pos, pos, x + 1, 1, 1, n);
            }
            
        } else {
            cout << query(l, r, 1, 1, n) << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}