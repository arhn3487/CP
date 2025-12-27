#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    if (n == 1) {
        cout << "1\n";
        return;
    }
    
    int res = 1;
    int last = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] > last + 1) {
            res++;
            last = a[i];
        }
    }
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}