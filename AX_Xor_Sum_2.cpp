#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;

    long long ans = 0;
    int r = 0;
    int xor_sum = 0, sum = 0;

    for(int l = 0; l < n; ++l) {
        while(r < n && (xor_sum ^ a[r]) == (sum + a[r])) {
            xor_sum ^= a[r];
            sum += a[r];
            ++r;
        }
        ans += (r - l);

        xor_sum ^= a[l];
        sum -= a[l];
    }

    cout << ans << '\n';
}
