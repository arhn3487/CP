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
    int n,m,b,f=1;
    cin>>n>>m;
    vector<int> a(n);

    for(int i=0;i<n;i++) cin>>a[i];
    cin>>b;

    if(b-a[n-1]>a[n-1]) a[n-1]=b-a[n-1];
    int last=a[n-1];


    for(int i=n-2;i>=0;i--)
    {
        int now=a[i];
        int tmp=b-a[i];
        //cout<<last<<" "<<now<<" "<<tmp<<'\n';
        if(now>last && tmp>last) 
        {
            f=0;
            //cout<<"ARAFAT\n";
        }
        else if(now<=last && tmp<=last) last=max(now,tmp);
        else if(now<=last) last=now;
        else last = tmp;
        
        
        
    }

    if(f) YES
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