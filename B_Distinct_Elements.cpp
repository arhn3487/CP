#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<long long> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    vector<int> a(n);
    vector<int> last_occurrence(n + 1, -1);
    
    a[0] = 1;
    last_occurrence[1] = 0;
    int next_new = 2;
    
    for (int i = 1; i < n; i++) {
        long long delta = b[i] - b[i - 1];
        int last_occ = i - delta;
        
        if (last_occ >= 0 && last_occ < i) {
            a[i] = a[last_occ];
        } else {
            
            a[i] = next_new;
            next_new++;
            if (next_new > n) next_new = 1; 
        }
        last_occurrence[a[i]] = i;
    }
    
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}