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
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

string s;
int n;

int rec(int i)
{
    debug(i);
    if(i==n) return 0;
    if(i>n) return 0;
    ll ans=0;
    if(i<n-2 && s[i]=='a' && s[i+1]=='b' && s[i+2]=='a') ans+=1+rec(i+3);
    if(i<n-1 && s[i]=='a' && s[i+1]=='b') ans+=1+rec(i+2);
    if(i<n && s[i]=='a') ans+=1+rec(i+1);
    if(i!=n-1)ans+=rec(i+1);

    return ans;
}

void solve()
{
    cin>>s;
    n=s.length();
    
    cout<<rec(0)<<'\n';
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