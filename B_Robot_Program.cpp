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
    ll n,x,k,ak_bar_asse=0,t=0,t2=1;
    string str;
    cin>>n>>x>>k>>str;

    for(int i=0;i<k && x!=0 ;i++)
    {
        if(str[i%n]=='L') x--;
        else x++;
        t++;
    }

    if(t==k)
    {
        if(x==0) print(1)
        else print(0)
        return;
    }

    debug(x,t);

    if(str[0]=='L') x--;
    else x++;
    t++;
    debug(x,t);
    for(int i=1;i+t<k && x!=0 ;i++)
    {
        if(str[i%n]=='L') x--;
        else x++;
        t2++;
        debug(x,t2);
    }

    ll notun=max(k-t2-t-1,0LL);
    cout<<notun+1<<'\n';
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