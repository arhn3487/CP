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
const ll infinity = LLONG_MAX;
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1}; //Right, Down, Left, Up, Diagonals
int dy[] = {0, -1, 0, 1, 1, -1, 1, -1};
inline ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }

#define rall(v) v.rbegin(), v.rend()
#define all(v) v.begin(), v.end()
#define print(x) cout << x << '\n';
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

void solve() 
{
    int n,k;cin>>n>>k;
    vector<array<bool,26>> v(n);

    for(int i=0;i<k;i++)
    {
        string s;cin>>s;
        for(int j=0;j<n;j++)
            v[j][s[j]-'a']=true;
    }

    //debug(v);

    set<int> div;
    
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            div.insert(i);
            div.insert(n/i);
        }
    }
    debug(div);

    debug(v[0][0],v[0][1]);

    for(auto x : div)
    {
        
        string ss="";
        for(int i=0;i<x;i++)
        {
            set<int> st;
            for(int i=0;i<26;i++) st.insert(i);
            for(int j=i;j<n;j+=x)
            {
                for(int k=0;k<26;k++)
                {
                    if(!v[j][k] && st.count(k)) st.erase(k);
                }
            }
            debug(st,x);
            if(!st.empty()) ss+=char(*st.begin()+'a');
            else 
            {
                ss="";
                break;
            }
        }

        if(ss!="")
        {
            debug(ss,x);
            int nn=n/ss.length();
            for(int i=0;i<nn;i++) cout<<ss;
            cout<<'\n';
            return;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}