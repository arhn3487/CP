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

void solve()
{
    int n,m,p,s,cnt=0;
    cin>>n>>m>>p>>s;
    vector<array<int,2>> v(m);

    for(auto &[a,b] : v) 
    {
        cin>>a>>b;
        a--,b--;
    }

    for(int i=0;i<(1<<n);i++)
    {
        int br=0,sg=0;
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j))
            if(j<p) br++;
            else if(j<p+s) sg++;
        }

        if(br!=1 || sg!=1) continue;
        int valid=1;

        for(auto [a,b] : v)
        {
            if(((1<<a)&i) && ((1<<b)&i)) valid=0;
        }
        
        cnt+=valid;
    }

    cout<<cnt<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    //cin>>t;

    for(int i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<": ";
        solve();
    }
}