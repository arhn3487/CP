#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        freq[arr[i]]++;
    }

    int score = 0;

    for (auto &[num, count] : freq) {
        if (freq[num] > 0) {
            int cc = k - num;

            if (freq.find(cc) != freq.end() && freq[cc] > 0) {
                if (num == cc) {
                    score += freq[num] / 2;
                    freq[num] %= 2;
                } else {
                    int pairs = min(freq[num], freq[cc]);
                    score += pairs;
                    freq[num] -= pairs;
                    freq[cc] -= pairs;
                }
            }
        }
    }

    cout << score << '\n';
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
