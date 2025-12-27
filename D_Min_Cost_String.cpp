#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int M = 1e9 + 7;
const ll infinity = LLONG_MAX;
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1}; // Directions
int dy[] = {0, -1, 0, 1, 1, -1, 1, -1};
inline ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }

vector<int> adj[26];
int vis[26] = {0};
string ans = "";

void dfs(int x, int &n) {
    if (!n) return;
    vis[x] = true;

    for (auto u : adj[x]) {
        if (!n) return;
        char ch = 'a' + u;
        ans += ch;
        n--;
        if (!n) return;
        if (!vis[u]) dfs(u, n);
        if (x == u) continue;
        if (!n) return;
        ch = 'a' + x;
        ans += ch;
        n--;
        if (!n) return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    int p = n;

    if (n == 1) {
        cout << "a\n";
        return 0;
    }

    for (int i = 0; i < k; i++)
    {
        for (int j = i; j < k; j++) adj[i].push_back(j);
    }

    ans = "a";
    n--;
    dfs(0, n);
    string res = "";
    while ((int)res.length() < p) {
        res += ans.substr(1);
    }

    cout << res.substr(0, p) << "\n";
    //cout << ans.substr(0, p);
}
