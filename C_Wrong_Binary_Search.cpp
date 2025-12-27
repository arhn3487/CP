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
const int M = 1e9 + 7;
const ll infinity = LLONG_MAX;
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1}; // Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[] = {0, -1, 0, 1, 1, -1, 1, -1};
inline ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }

#define rall(v) v.rbegin(), v.rend()
#define all(v) v.begin(), v.end()
#define print(x) cout << x << '\n';
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    vector<int> v(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
            v[i] = i+ 1;
    }

    //debug(s);

    for (int i = 0; i < n; i++)
    {
        //cout<<"ARAFAT\n";
        int j = i + 1, l = i + 1;
        if (s[i] == '0')
        {
            int num=i+1,end=i+1;
            while(end<n && s[end]=='0') end++;
            if(end-i>1)
            {
                for(int k=end-1;k>=i;k--)
                {
                    v[k]=num;
                    num++;
                }
            }
            else
            {
                yes(0)
                return;
            }
            
            if((end-i)%2)
            {
                //cout<<"ARAFAT\n"<<end-i<<'\n';
                int cnt=end-i;
                cnt/=2;
                swap(v[i],v[i+cnt]);
            }
            i=end-1;
            //debug(end,i);
        }
    }

    yes(1) for (auto x : v) cout << x << ' ';
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        // cout<<"Case "<<i<<": ";
        solve();
    }
}