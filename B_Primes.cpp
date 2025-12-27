#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define ll long long
const int M = 1e6 + 9;
const ll infinity = LLONG_MAX;
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1}; // Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[] = {0, -1, 0, 1, 1, -1, 1, -1};
inline ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }

#define rall(v) v.rbegin(), v.rend()
#define all(v) v.begin(), v.end()
#define print(x) cout << x << '\n';
#define YES cout << "YES\n";
#define NO cout << "NO\n";

vector<bool> prime(M, true);
vector<int> v;

bool isPrime(int n) {
    // Handle base cases
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    // Check for factors from 5 to √n
    for (int i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0) {
    return false;
    }
    }
    return true;
}

// gcd function
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// lcm function
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

//bfs function use adjacent list


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    int n;
    cin >> n;
    if (n < 5)
        print(-1) else if (isPrime(n-2)) cout << 2 << ' ' << n - 2 << '\n';
    else
        print(-1)
}