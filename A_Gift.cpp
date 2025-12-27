#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define ll long long
const ll INF = 1e18;

struct Edge {
    int u, v;
    int g, s;
};

int parent[205];

int find(int u) {
    if (parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

bool unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;
    parent[v] = u;
    return true;
}

bool cmp_g(const Edge &a, const Edge &b) {
    return a.g < b.g;
}

bool cmp_s(const Edge &a, const Edge &b) {
    return a.s < b.s;
}

void solve() {
    int n, m, G, S;
    cin >> n >> m >> G >> S;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].g >> edges[i].s;
        edges[i].u--;
        edges[i].v--;
    }

    sort(edges.begin(), edges.end(), cmp_g);

    ll ans = INF;
    vector<Edge> current_edges;

    for (int i = 0; i < m; ++i) {
        current_edges.push_back(edges[i]);
        sort(current_edges.begin(), current_edges.end(), cmp_s);

        // Kruskal to find MST minimizing silver
        for (int j = 0; j < n; ++j) parent[j] = j;
        int count = 0;
        int max_s = 0;
        for (auto &e : current_edges) {
            if (unite(e.u, e.v)) {
                count++;
                max_s = max(max_s, e.s);
                if (count == n - 1) break;
            }
        }

        if (count == n - 1) {
            ll cost = 1LL * edges[i].g * G + 1LL * max_s * S;
            ans = min(ans, cost);
        }
    }

    if (ans == INF) cout << -1 << '\n';
    else cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
