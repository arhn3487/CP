#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long t;
    cin >> n >> t;
    long long a[100005];
    for (int i = 0; i < n; i++) cin >> a[i];

    long long max_future_price = a[n - 1];
    long long max_profit = -1;
    int count = 0;

    // Traverse from right to left to calculate profit for each buy position
    for (int i = n - 2; i >= 0; i--) {
        long long profit = max_future_price - a[i];
        if (profit > max_profit) {
            max_profit = profit;
            count = 1;
        } else if (profit == max_profit) {
            count++;
        }
        if (a[i] > max_future_price) {
            max_future_price = a[i];
        }
    }

    cout << count << "\n";
    return 0;
}
