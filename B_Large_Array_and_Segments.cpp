#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);

int main() {
    fastio();
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        ll x;
        cin >> n >> k >> x;
        
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        vector<ll> prefix_sum(2 * n + 1, 0);
        for (int i = 1; i <= 2 * n; i++) {
            prefix_sum[i] = prefix_sum[i - 1] + a[(i - 1) % n];
        }
        
        ll count = 0;
        deque<int> dq;
        
        for (int l = 1; l <= n * k; l++) {
            int idx = (l - 1) % n + 1;
            while (!dq.empty() && prefix_sum[dq.back()] >= prefix_sum[l - 1]) {
                dq.pop_back();
            }
            dq.push_back(l - 1);
            
            int low = l, high = min(n * k, l + n * 2 - 1), res = l - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                while (!dq.empty() && dq.front() < l - 1) {
                    dq.pop_front();
                }
                if (prefix_sum[mid] - prefix_sum[dq.front()] >= x) {
                    res = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            count += (res >= l);
        }
        
        cout << count << "\n";
    }
    
    return 0;
}
