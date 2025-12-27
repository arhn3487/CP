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

vector<ll> v;

void solve()
{
    ll n,n1,n2,mx=0;cin>>n;
    string ans="";
    vector<string> vv,aa;

    for(auto x : v)
    {
        n1=n-x;
        if(n1<0) break;
        n2=x;
        string s=to_string(n1)+to_string(n2);
        aa.push_back(s);
        //debug(s,n2,ans);
        ll k=s.length();
        mx=max(k,mx);
    }

    debug(aa);
    debug(mx);

    for(auto x : aa)
    {
        if(x.length()==mx)
        {
            vv.push_back(x);
        }
    }

    sort(all(vv));

    cout<<vv.back()<<'\n';
    //print(ans)
    //cout<<n-n2<<n2<<'\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll a=1;
    v.push_back(1);

    for(int i=1;i<=17;i++)
    {
        a*=10;
        v.push_back(a);
    }

    int t=1;
    //cin>>t;

    for(int i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<": ";
        solve();
    }
}