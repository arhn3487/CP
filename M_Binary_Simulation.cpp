#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

vector<ll> seg, lazy;

void propagate(int node, int range_i, int range_j) {
    if (lazy[node] != 0) {
        seg[node] += (range_j - range_i + 1) * lazy[node];
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
    seg[node] = seg[2*node] + seg[2*node+1];
}

ll query(int i, int j, int node, int range_i, int range_j) {
    propagate(node, range_i, range_j);
    if (range_i > j || range_j < i) return 0;
    if (range_i >= i && range_j <= j) return seg[node];
    int mid = (range_i + range_j) / 2;
    return query(i, j, 2*node, range_i, mid) + query(i, j, 2*node+1, mid+1, range_j);
}

void solve() {
    int n, q;
    cin >> n >> q;
    seg.assign(4*n, 0);
    lazy.assign(4*n, 0);

    while (q--) {
        int a, x, y, z;
        cin >> a;
        if (a == 0) {
            cin >> x >> y >> z;
            update(x, y, z, 1, 0, n-1);
        } else {
            cin >> x >> y;
            ll res = query(x, y, 1, 0, n-1);
            print(res);
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
        cout << "Case " << i << ":\n";
        solve();
    }
    return 0;
}