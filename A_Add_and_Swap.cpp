#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, m = 0;
    cin >> n >> k;
    vector<int> v(n), res;

    for (int i = 0; i < n; i++) cin >> v[i];

    while (m < 500000) {
        bool inc = true;
        for (int i = 0; i < n - 1; i++) {
            if (v[i] > v[i + 1]) {
                // Perform the operation
                int temp = v[i];
                v[i] = v[i + 1] + k;
                v[i + 1] = temp;
                res.push_back(i + 1);
                m++;
                inc = false;
            }
        }
        if (inc) break; // Stop if the array is non-decreasing
    }

    // Check if the array is non-decreasing
    bool non_decreasing = true;
    for (int i = 0; i < n - 1; i++) {
        if (v[i] > v[i + 1]) {
            non_decreasing = false;
            break;
        }
    }

    if (non_decreasing) {
        cout << "Yes\n" << m << "\n";
        for (auto x : res) cout << x << " ";
        cout << endl;
    } else {
        cout << "No\n";
    }

    return 0;
}
