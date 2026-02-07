#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int N;
    if (!(cin >> N)) return;

    // We track the range of values that the CURRENT player is dealing with.
    // At the start, Takahashi is at [1, 1].
    int left = 1, right = 1;

    while (true) {
        // --- Takahashi's Turn ---
        // He wants to move to a state where Aoki is forced to go over N.
        // If he moves from [left, right], the new range is [left*2, right*2 + 1].
        left = left * 2;
        right = right * 2 + 1;

        if (N < left) {
            // Takahashi was forced to move to a number > N. Takahashi loses.
            cout << "Aoki" << endl;
            return;
        }
        if (N <= right) {
            // Takahashi can pick a number in the range [left, N] such that
            // every move Aoki makes will result in a number > N.
            cout << "Takahashi" << endl;
            return;
        }

        // --- Aoki's Turn ---
        left = left * 2;
        right = right * 2 + 1;

        if (N < left) {
            // Aoki was forced to move to a number > N. Aoki loses.
            cout << "Takahashi" << endl;
            return;
        }
        if (N <= right) {
            // Aoki can pick a number that forces Takahashi to go over N.
            cout << "Aoki" << endl;
            return;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}