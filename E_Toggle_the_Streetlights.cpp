#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define debug(x...)
#endif
using namespace std;

#define ll long long
#define ld long double
#define int long long
const int M=1e9+7;
const int N=1e6+5;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

void solve()
{
    int n,k;
    string s;
    cin>>n>>k>>s;
    string first=s,second=s;

    if(k==0)
    {
        cout<<s<<'\n';
        return;
    }

    for(int i=1;i<n-1;i++)
    {
        if(s[i-1]==s[i+1] && s[i+1]=='1')
        {
            first[i]=(s[i]=='1') ?  '0' : '1';
            debug(i);
        }
    }
    for(int i=1;i<n-1;i++)
    {
        if(first[i-1]==first[i+1] && first[i+1]=='1')
        {
            second[i]=(first[i]=='1') ?  '0' : '1';
        }
    }

    debug(first,second);

    if(k&1) cout<<first<<'\n';
    else cout<<second<<'\n';
}

int32_t main()
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