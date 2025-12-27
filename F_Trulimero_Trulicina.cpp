#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    
    int total = n * m;
    int freq = total / k; // Each number appears freq times
    
    vector<vector<int>> grid(n, vector<int>(m));
    vector<int> nums;

    // Prepare a sequence with each number from 1 to k appearing exactly freq times
    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j < freq; ++j) {
            nums.push_back(i);
        }
    }

    int idx = 0;

    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            // Left to right
            for (int j = 0; j < m; ++j) {
                grid[i][j] = nums[idx++];
            }
        } else {
            // Right to left
            for (int j = m - 1; j >= 0; --j) {
                grid[i][j] = nums[idx++];
            }
        }
    }

    // Output the grid
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
