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
    int n,k=0;cin>>n;
    ll sum=0;
    vector<int> v(n),o(30,0),z(30,0);

    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        for(int j=0;j<30;j++)
        {
            if((1<<j)&v[i]) o[j]++;
            else z[j]++;
        }

        for(int i=0;i<5;i++) cerr<<o[i]<<' ';
        cerr<<'\n';
    }

    for(int i=0;i<30;i++)
    {
        ll one=0,zero=0;

        for(int j=k;j<n;j++)
        {
            if(v[j]&(1<<i)) one++;
            else zero++;
        }
        debug(zero,one,i);
        sum+=(one*zero*i);
        k++;
    }
    cout<<sum<<'\n';
    debug(sum);
    debug(v);

    for(int i=0;i<30;i++)
    {
        sum+=o[i]*z[i]*i;
    }

    for(int i=0;i<5;i++) cerr<<o[i]<<' ';
    cerr<<'\n';
    for(int i=0;i<5;i++) cerr<<z[i]<<' ';
    cout<<sum<<'\n';
    
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