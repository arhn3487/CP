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

ll fac[N];

ll bin_exp (ll a, ll b, ll c=M) { 
    ll res = 1; 
    while (b > 0) { 
        if (b % 2 == 1) { 
            res = (res * a) % c; // If b is odd, multiply res by a 
        } 
        a = (a * a) % c; // Square a 
        b /= 2; // Divide b by 2 
    } 
    return res; 
}

ll ncr(ll n,ll r)
{
    ll den=fac[r]*fac[n-r]%M;
    den=bin_exp(den,M-2);
    return fac[n]*den%M;
}

void solve()
{
    int n;
    string s;cin>>n>>s;
    int cnt=0,r=0;

    for(auto x : s)
    {
        if(x=='(') cnt++;
        else r++;

        if(cnt<r)
        {
            cout<<0<<'\n';
            return;
        }
    }

    if(cnt>n/2 || r>n/2 || n&1LL)
    {
        cout<<0;
        return;
    }


    //if

    debug(cnt,r);

   ll rem=n-s.length(),rem_r=n/2-r;
   ll lp=n/2-cnt,rp=n/2-r;
   debug(rem,lp,rp);
   ll a=ncr(rem,lp),b=ncr(rem,lp-1);
   debug(a,b);
   cout<<(a-b+M)%M<<'\n';
}


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    //cin>>t;

    fac[0]=1;
    fac[1]=1;

    for(int i=2;i<N;i++) fac[i]=fac[i-1]*i%M;

    for(int i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<": ";
        solve();
    }
}