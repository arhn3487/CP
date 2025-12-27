#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

void solve()
{
    ll m,a,b,c;
    cin>>m>>a>>b>>c;
    ll ans=min(a,m);
    //cout<<ans<<" 1st\n";
    ll extra=m-ans;
    //cout<<extra<<"\n";
    ll p=ans;
    ans+=(min(b,m));
    ll q=m-(min(b,m));
    //cout<<ans<<" 2nd\n";

    //extra+=(ans-p);
   // cout<<extra<<" extra\n";
    cout<<min(extra+q,c)+ans<<'\n';
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