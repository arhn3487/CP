#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define YES cout << "YES\n";
#define NO cout << "NO\n";

vector<string> arr;
bool vis[55][55];
bool f;

bool pos(int a, int b) {
    if (a == 0 || b == 0) return true;
    if (arr[a - 1][b] == '1' || arr[a][b - 1] == '1') return true;
    return false;
}

void check(int a, int b) {
    bool rowValid = true, colValid = true;

    for (int i = b; i >= 0; i--) {
        if (arr[a][i] != '1') {
            rowValid = false;
            break;
        }
    }
    for (int i = a; i >= 0; i--) {
        if (arr[i][b] != '1') {
            colValid = false;
            break;
        }
    }
    if (!rowValid && !colValid) f = false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    arr.resize(n);
    memset(vis, false, sizeof(vis));
    f = true;

    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (arr[i][j] == '1' && !vis[i][j]) check(i, j);
            vis[i][j] = true;
        }
    }

    if (f) YES else NO
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
}
