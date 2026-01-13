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

int fact[35];
int ncr[35][35];

void solve()
{
    int n,k,ans=0;cin>>n>>k;
    int len=log2(n),nn=n;

    // while(nn)
    // {
    //     nn>>=1;
    //     len++;
    // }
    // len--;

    debug(len);

    for(int i=1;i<=len;i++)
    {
        for(int j=0;j<i;j++)
        {
            int rem=i-1;
            debug(i,j);
            int op=j*2+1+(rem-j);
            if(op>k) 
            {
                ans+=ncr[rem][j];
            }
        }
    }

    if(len+1>k) ans++;

    cout<<ans<<'\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=0;i<35;i++)
    {
        ncr[i][0]=1;
        for(int j=1;j<=i;j++) ncr[i][j]=ncr[i-1][j-1]+ncr[i-1][j];
    }

    fact[0]=1;
    fact[1]=1;
    fact[2]=2;

    for(int i=3;i<35;i++) fact[i]=fact[i-1]*i;

    int t=1;
    cin>>t;

    for(int i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<": ";
        solve();
    }
}