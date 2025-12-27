#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

void solve() {
    int l1, b1, l2, b2, l3, b3;
    cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;

    auto check = [&](int l1, int b1, int l2, int b2, int l3, int b3) {
        if (l1 == l2 && l2 == l3) {
            if (b1 + b2 + b3 == l1) return true;
        }
        if (b1 == b2 && b2 == b3) {
            if (l1 + l2 + l3 == b1) return true;
        }
        if (l1 == l2) {
            if (b1 + b2 == b3 && l3 + l1 == b3) return true;
        }
        if (l1 == l3) {
            if (b1 + b3 == b2 && l2 + l1 == b2) return true;
        }
        if (l2 == l3) {
            if (b2 + b3 == b1 && l1 + l2 == b1) return true;
        }
        if (b1 == b2) {
            if (l1 + l2 == l3 && b3 + b1 == l3) return true;
        }
        if (b1 == b3) {
            if (l1 + l3 == l2 && b2 + b1 == l2) return true;
        }
        if (b2 == b3) {
            if (l2 + l3 == l1 && b1 + b2 == l1) return true;
        }
        if (l1 == l2 + l3) {
            if (b2 == b3 && b1 + b2 == l1) return true;
        }
        if (l2 == l1 + l3) {
            if (b1 == b3 && b2 + b1 == l2) return true;
        }
        if (l3 == l1 + l2) {
            if (b1 == b2 && b3 + b1 == l3) return true;
        }
        if (b1 == b2 + b3) {
            if (l2 == l3 && l1 + l2 == b1) return true;
        }
        if (b2 == b1 + b3) {
            if (l1 == l3 && l2 + l1 == b2) return true;
        }
        if (b3 == b1 + b2) {
            if (l1 == l2 && l3 + l1 == b3) return true;
        }
        return false;
    };

    if (check(l1, b1, l2, b2, l3, b3) ||
        check(l1, b1, l3, b3, l2, b2) ||
        check(l2, b2, l1, b1, l3, b3) ||
        check(l2, b2, l3, b3, l1, b1) ||
        check(l3, b3, l1, b1, l2, b2) ||
        check(l3, b3, l2, b2, l1, b1)) {
        YES
    } else {
        NO
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        solve();
    }
}