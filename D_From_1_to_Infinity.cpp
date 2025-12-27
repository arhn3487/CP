#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define P(x) cout<<x<<'\n';
#define yes(x) cout << ((x) ? "Yes\n" : "No\n");

// Function to count the frequency of a specific digit d in numbers from 1 to n
ll countDigit(ll n, int d) {
    ll count = 0;
    ll i = 1;
    while (i <= n) {
        ll divider = i * 10;
        count += (n / divider) * i;
        ll remainder = n % divider;
        if (d == 0) {
            // For digit 0, we need to avoid leading zeros
            if (n / divider > 0) {
                count += min(max(remainder - (i - 1), 0LL), i);
            }
        } else {
            count += min(max(remainder - (d * i - 1), 0LL), i);
        }
        i *= 10;
    }
    return count;
}

void solve() {
    ll n,sum=0; cin >> n;
    for (int d = 0; d <= 9; d++) {
        ll freq = countDigit(n, d);
       // cout << freq << " ";
        sum+=(d*freq);
    }
    
    cout<<sum << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    cin>>t;

    for(int i=1;i<=t;i++) {
        //cout<<"Case "<<i<<": ";
        solve();
    }
}