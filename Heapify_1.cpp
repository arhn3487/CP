#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define debug(x...)
#endif
using namespace std;

#define ll long long
#define ld long double
#define int long long
const int M = 1e9 + 7;
const int N = 2e5+10;
const ll infinity = LLONG_MAX;
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1}; //Right, Down, Left, Up, Diagonals
int dy[] = {0, -1, 0, 1, 1, -1, 1, -1};
inline ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }

#define rall(v) v.rbegin(), v.rend()
#define all(v) v.begin(), v.end()
#define print(x) cout << x << '\n';
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

int spf[N]; 
 
void Spf() { 
    for(int i=2;i<=N;i++) spf[i]=i;  
     
    for(int i=2;i*i<N;i++) 
        if(spf[i]==i) 
            for(int j=i*i;j<N;j+=i) 
                if(spf[j]==j) spf[j]=i; 
} 


void solvee() 
{
    int n;cin>>n;
    vector<int> v(n+1);
    map<int,int> mp;

    for(int i=1;i<=n;i++) 
    {
        cin>>v[i];
        mp[v[i]]= spf[i];
    }

    sort(all(v));

    for(int i=1;i<=n;i++)
    {
        if(mp[v[i]]==spf[v[i]]) continue;
        int k=log2(i);
        if(mp[v[i]]==1 and (k==(1LL<<k))) continue;
        yes(0)
        return;
    }

    yes(1)

}

void solve() {
    int n; cin >> n;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];

    for(int i=1;i<=n;i++){
        int cur = i, want = a[i];

        while(cur % 2 == 0) cur /= 2;
        while(want % 2 == 0) want /= 2;

        if(cur != want){
            yes(0);
            return;
        }
    }
    yes(1);
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Spf();
    spf[1]=1;

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}