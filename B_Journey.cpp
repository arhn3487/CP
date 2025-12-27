#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int M = 1e9+7;

void solve() {
    ll n, a, b, c;
    cin >> n >> a >> b >> c;

    ll k = a + b + c;  
    ll point = n / k;
    ll rem = n % k; 
    if (rem == 0) {
        cout << 3 * point << '\n';
    } else if (rem <= a) {
        cout << 3 * point + 1 << '\n';
    } else if (rem <= a + b) {
        cout << 3 * point + 2 << '\n';
    } else {
        cout << 3 * point + 3 << '\n';
    }
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
