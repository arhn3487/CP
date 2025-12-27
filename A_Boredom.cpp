#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
int dx[] = {1,0,-1,0,1,1,-1,-1};
int dy[] = {0,-1,0,1,1,-1,1,-1};
ll lcm(ll a, ll b) {return (a * b) / __gcd(a, b);}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, a, mx = 0;
    cin >> n;
    vector<ll> dp(100005, 0); 
    vector<ll> dp2(100005, 0); 

    for(int i = 0; i < n; i++) {
        cin >> a;
        dp[a]++;
        mx = max(mx, a);
    }

    dp2[0] = 0;
    dp2[1] = dp[1];
    for(int x = 2; x <= mx; x++) { 
        dp2[x] = max(dp2[x-1], dp[x] * x + dp2[x-2]);
    }

    cout << dp2[mx] << endl; 
}