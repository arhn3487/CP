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

map<ll,ll> mp;
ll k;

void primeFactorization(ll n) { 
    while (n % 2 == 0) { 
        n /= 2; 
        mp[2]++;
    } 

    for (ll i = 3; i * i <= n; i += 2) { 
        while (n % i == 0) { 
            n /= i; 
            mp[i]++;
        } 
    } 

    if (n > 2) 
        mp[n]++;
    
} 

bool possible(ll mid)
{
    ll t=(1LL<<mid),need=0;

    for(auto [x,e] : mp)
    {
        ll r=e%t;
        if(r)
        {
            need+=(t-r);
            if(need>k) return false;
        }
    }

    return true;
}

void solve()
{
    ll n;
    cin>>n>>k;
    mp.clear();

    primeFactorization(n);

    // for(auto &[x,y] : mp)
    // {
    //     if(y%2)
    //     {
    //         if(k)
    //         {
    //             y++;
    //             k--;
    //         }
    //         else
    //         {
    //             cout<<0<<'\n';
    //             return;
    //         }
    //     } 
    // }

    //debug(mp);

    ll lo=0,hi=60,t=0;

    while(lo<=hi)
    {
        ll mid=(lo+hi)/2;
        if(possible(mid))
        {
            t=mid;
            lo=mid+1;
        }
        else hi=mid-1;
    }

    // ll ans=0;
    // debug(t);
    // if(t%2) t--;
    // while(t%2==0)
    // {
    //     ans++;
    //     t/=2;
    //     lo/=2;
    // }
    cout<<t<<'\n';
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