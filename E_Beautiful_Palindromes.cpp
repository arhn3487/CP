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

ll ask(int type,int l,int r)
{
    cout<<type<<' '<<l<<" "<<r<<endl;
    ll a;cin>>a;
    return a;
}

void solve()
{
    int n;cin>>n;
    vector<int> v(n);

    for(auto &x : v) cin>>x;

    int lo=1,hi=n,problem=ask(2,1,n)-ask(1,1,n);

    while(lo<=hi)
    {
        ll mid=(lo+hi)/2;

        if((ask(2,1,mid)-ask(1,1,mid))==problem) hi=mid-1;
        else lo=mid+1;
    }

    cout<<"! "<<lo-problem+1<<' '<<lo<<endl;
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