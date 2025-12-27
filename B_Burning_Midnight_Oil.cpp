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

ll n,k;

ll find(ll v)
{
    ll m=n,l=k,write=0;
    while(v)
    {
        write+=v;
        v/=k;
    }

    return write;
}


void solve()
{
    cin>>n>>k;
    ll lo=0,hi=n,ans=LLONG_MAX;

    while(lo<=hi)
    {
        ll mid=(lo+hi)/2;
        ll sum=find(mid);

        if(sum>=n)
        {
            hi=mid-1;
            ans=min(ans,mid);
        }
        else
        {
            lo=mid+1;
        }
    }
    print(ans)
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
