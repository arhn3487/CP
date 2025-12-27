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
#define print(x) cout<<x<<'\n';
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

void solve()
{
    string p, s;
    cin >> p >> s;

    int i = 0, j = 0;
    int n = p.size(), m = s.size();

    while (i < n && j < m)
    {
        if (p[i] != s[j]) {
            NO
            return;
        }

        char ch = p[i];
        int cnt_p = 0, cnt_s = 0;


        while (i < n && p[i] == ch) cnt_p++, i++;

        while (j < m && s[j] == ch) cnt_s++, j++;

        if (cnt_s < cnt_p || cnt_s > 2 * cnt_p) {
            NO
            return;
        }
    }

    if (i == n && j == m) YES
    else NO
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    cin>>t;

    for(int i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<": ";
        solve();
    }
}