#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define debug(x...)
#endif
using namespace std;

#define int long long

int get_best(int fixed, int target) {
    int res = 0;
    for (int i = 0; i < 40; i++) {
        int bit = (1LL << i);
        if (fixed & bit) continue;
        int c1 = (res | bit), c2 = (res | (1LL << (i + 1))), c3 = (res | bit | (1LL << (i + 1))), c4 = (res == 0) ? bit : res;
        int a = abs(c1 - target), b = abs(c2 - target), c = abs(c3 - target), d = abs(c4 - target);
        int k = min({a, b, c, d});
        if ((a == k) && (res&fixed==0)) res = c1;
        else if ((b == k) && (res&fixed==0)) res = c2;
        else if ((c == k) && (res&fixed==0)) res = c3;
        else res = c4;
    }
    return res;
}

void solve() {
    int x, y; cin >> x >> y;
    
    int q1 = get_best(x, y);
    int p2 = get_best(y, x);

    if (abs(q1 - y) <= abs(p2 - x)) {
        cout << x << ' ' << q1 << '\n';
    } else {
        cout << p2 << ' ' << y << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}