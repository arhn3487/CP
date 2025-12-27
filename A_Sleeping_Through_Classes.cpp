#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define debug(x...)
#endif
using namespace std;

#define int long long
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define print(x) cout<<x<<'\n';
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

void solve(){
    int n, k, cnt = 0;
    string s;
    cin >> n >> k >> s;
    int block_end = -1;
    for(int i = 0; i < n; i++){
        if(s[i] == '1') block_end = i + k;
        else if(i > block_end) cnt++;
    }
    cout << cnt << '\n';
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--) solve();
}
