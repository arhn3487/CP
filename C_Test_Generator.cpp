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
const int N = 1e6 + 5;
const ll infinity = 1e15;
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1}; //Right, Down, Left, Up, Diagonals
int dy[] = {0, -1, 0, 1, 1, -1, 1, -1};
inline ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }

#define rall(v) v.rbegin(), v.rend()
#define all(v) v.begin(), v.end()
#define print(x) cout << x << '\n';
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

vector<int> kk;

void solve() 
{
    int s,m,n=0,block=0,f=1;
    cin>>s>>m;
    string ss=bitset<65> (s).to_string(),mm=bitset<65>(m).to_string();
    reverse(all(ss));
    reverse(all(mm));
    
    while(ss.back()=='0') ss.pop_back();
    while(mm.back()=='0') mm.pop_back();
    reverse(all(ss));
    reverse(all(mm));
    debug(ss,mm);
    block=mm.length();
    string pre=ss;

    while(1)
    {
        if(ss.empty()) break;
        int sz=0,milse=0;
        
        for(int i=0;i<mm.length() && ss.length();i++)
        {
            if(ss[i]=='1' && mm[i]=='0') break;
            else if(ss[i]=='1' && mm[i]=='1') milse=i+1;
            
        }
        int baki_ase=mm.length()-milse;
        debug(milse,baki_ase);
        // sz=ss.length()-sz;
        // if(!sz) break;
        // n+=(ss.length()-sz);
        // debug(sz,n);
        reverse(all(ss));
        while(ss.length() && milse--) ss.pop_back();
        n+=(1<<ss.length());
        while(ss.length() && ss.back()=='0') ss.pop_back();
        reverse(all(ss));

        if(pre==ss) 
        {
            f=0;
            break;
        }

        pre=ss;

        debug(ss,mm,n);
    }
    
    if(ss.size()) print(-1)
    else print(n)
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    kk.push_back(1);
    kk.push_back(2);

    for(int i=0;i<10;i++)
    {
        kk.push_back(kk.back()*kk.back());
    }

    debug(kk);

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}