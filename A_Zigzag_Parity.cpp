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
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

const int N=5e5+7;

int arr[N],brr[N];

void solve()
{
    int n;cin>>n;
    if(n==1) cout<<1<<'\n';
    else if(n==2) cout<<"1 2 \n";
    else
    {
        if(n%2) for(int i=0;i<n;i++) cout<<arr[i]<<' ';
        else for(int i=0;i<n;i++) cout<<brr[i]<<' ';
        cout<<'\n';
        //int o=0
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int odd=1,even=2;

    for(int i=0;i<N-1;i+=4)
    {
        arr[i]=odd;
        odd+=2;
        arr[i+1]=odd;
        odd+=2;
    }
    for(int i=2;i<N-1;i+=4)
    {
        arr[i]=even;
        even+=2;
        arr[i+1]=even;
        even+=2;
    }

    even=2;

    for(int i=0;i<N;i+=4)
    {
        brr[i]=even;
        even+=2;
        brr[i+1]=even;
        even+=2;
    }

    odd=1;

    for(int i=2;i<N;i+=4)
    {
        brr[i]=odd;
        odd+=2;
        brr[i+1]=odd;
        odd+=2;
    }

    for(int i=0;i<10;i++) cerr<<brr[i]<<' ';

    //for(int i=)

    int t=1;
    cin>>t;

    for(int i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<": ";
        solve();
    }
}