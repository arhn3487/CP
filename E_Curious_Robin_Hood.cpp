#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define int long long
const int M=1e9+7;
//const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
//inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

vector<int> v, seg;

int build(int i, int j, int node) {
    if (i == j) return seg[node] = v[i];
    int mid = (i + j) / 2;

    int left = build(i, mid, 2 * node);
    int right = build(mid + 1, j, 2 * node + 1);

    return seg[node] = left + right;
}

int find(int qi, int qj, int range_i, int range_j, int node) {
    if (qi > range_j || qj < range_i) return 0;  
    if (qi <= range_i && range_j <= qj) return seg[node];

    int mid = (range_i + range_j) / 2;

    int left = find(qi, qj, range_i, mid, 2 * node);
    int right = find(qi, qj, mid + 1, range_j, 2 * node + 1);

    return left + right;
}

int update(int i, int j, int index, int val, int node) {
    if (i == j) return seg[node] += val;
    int mid = (i + j) / 2;
    if (index > mid) update(mid + 1, j, index, val, 2 * node + 1);
    else update(i, mid, index, val, 2 * node);
    
    return seg[node] = seg[2 * node] + seg[2 * node + 1];
}

void solve() {
    int n, q;
    cin >> n >> q;

    v.resize(n);
    seg.assign(4 * n, 0);

    for (auto &x : v) cin >> x;

    build(0, n - 1, 1);

    while (q--) {
        int a, b, c;
        cin >> a;
        if (a == 3) {
            cin >> b >> c;
            print(find(b, c, 0, n - 1, 1));  
        } else {
            cin >> b;
            if (a == 1) {
                print(v[b]);
                update(0, n - 1, b, -v[b], 1); 
                v[b]=0;
            } 
            else {
                cin >> c;
                update(0, n - 1, b, c, 1);  
                v[b] += c;  
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ":\n";
        solve();
    }
}
