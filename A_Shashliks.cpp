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
    ll k,a,b,x,y,cnt=0,cnt1=0,cnt2=0;cin>>k>>a>>b>>x>>y;
    if(y>x)
    {
        swap(x,y);
        swap(a,b);
    }

    ll lo=0,hi=M;

    while(lo<hi)
    {
        int mid=(lo+hi)/2;
        if(mid*y<=k-b)
        {
            cnt1=mid;
            lo=mid+1;
        }
        else hi=mid;
    }
    k-=cnt1*y;
    if(k>=b)
    {
        k-=y;
        cnt1++;
    }
    
    lo=0,hi=M;

    //cout<<k<<'\n';
    
    while(lo<hi)
    {
        ll mid=(lo+hi)/2;
        if(mid*x<=k-a)
        {
            cnt2=mid;
            lo=mid+1;
        }
        else hi=mid;    
    }
    k-=cnt2*x;

    if(k>=a)
    {
        k-=x;
        cnt2++;
    }
    //cout<<cnt1<<' '<<cnt2<<'\n';


    cout<<cnt1+cnt2<<'\n';

    // while(k>=b)
    // {
    //     cnt++;
    //     k-=y;
    // }

    // while(k>=a)
    // {
    //     cnt++;
    //     k-=x;
    // }

    // cout<<cnt<<'\n';
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