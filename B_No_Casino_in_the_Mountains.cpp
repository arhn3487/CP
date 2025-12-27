#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    int res = 0;
    int i = 0;
    while (i <= n - k) {
        bool valid = true;
        for (int j = i; j < i + k; ++j) {
            if (a[j] != 0) {
                valid = false;
                break;
            }
        }
        if (valid) {
            res++;
            i += k; 
        }
        i++;
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