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

vector<ll> vec;
ll n;
double k;

bool check(double target)
{
    double remove=0.0,add=0.0;
    for(int i=0;i<n;i++)
    {
        if(vec[i]>target) remove+= (vec[i]-target)*(1-k/100.0);
        else if(vec[i]<target) add+= (target-vec[i]);
    }

    return remove>=add;
}

void solve()
{
    cin>>n>>k;
    vec.resize(n);

    for(auto &x : vec) cin>>x;

    double lo=0.0,hi=1000.0,ans=0.0;

    while(hi-lo>1e-6)
    {
        double mid=(lo+hi)/2.0;
        if(check(mid))
        {
            ans=max(mid,ans);
            lo=mid;
        }
        else hi=mid;
    }

    cout<<fixed<<setprecision(10)<<ans<<'\n';
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