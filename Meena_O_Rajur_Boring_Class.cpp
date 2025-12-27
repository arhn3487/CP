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
#define ld long double
#define pi 3.141593
vector<ld> res(40);

void solve()
{
    int n;
    cin>>n;
    cout<<fixed<<setprecision(2)<<res[n-1]<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<ld> fib(40);
    fib[0]=1;
    fib[1]=1;

    for(int i=2;i<40;i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
    }

    res[0]=(1-pi/4);

    for(int i=1;i<40;i++)
    {
        ll sq=fib[i]*fib[i];
        ld col=sq*(1-pi/4.0);
        res[i]=res[i-1]+col;
    }

    //debug(res);

    int t=1;
    cin>>t;

    for(int i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<": ";
        solve();
    }
}