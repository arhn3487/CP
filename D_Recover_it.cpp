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
const int N = 2750131+10;
const ll infinity = LLONG_MAX;
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1}; //Right, Down, Left, Up, Diagonals
int dy[] = {0, -1, 0, 1, 1, -1, 1, -1};
inline ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }

#define rall(v) v.rbegin(), v.rend()
#define all(v) v.begin(), v.end()
#define print(x) cout << x << '\n';
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

int spf[N];
map<int,int> prime;

void solve() 
{
    for(int i=0;i<N;i++) spf[i]=i;
    int ind=1;
    for(int i=2;i<N;i++)
    {
        if(spf[i]==i)
        {
            prime[i]=ind;
            ind++;
            for(int j=i*i;j<N;j+=i) 
            if(spf[j]==j)spf[j]=i;
        }
    }
    int n;cin>>n;
    vector<int> v;
    multiset<int> ms;

    debug(prime[5]);

    for(int i=0;i<2*n;i++)
    {
        int a;cin>>a;
        ms.insert(a);
    }

    debug(*ms.rend());

    while (ms.size())
    {
        int k=*ms.rbegin();
        debug(k);
        if(k==spf[k])
        {
            ms.erase(ms.find(k));
            v.push_back(prime[k]);
            ms.erase(ms.find(prime[k]));
        }
        else
        {
            v.push_back(k);
            ms.erase(ms.find(k));
            ms.erase(ms.find(k/spf[k]));
        }

        debug(v);
        debug(ms);
    }
    
    for(auto x : v) cout<<x<<' ';
    cout<<'\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    
    for (int i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}