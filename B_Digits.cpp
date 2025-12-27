#include<bits/stdc++.h>
//#include "D:/debug.h"
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
    ll n,d,res=1;
    cin>>n>>d;

    bool one=false,three =false,five=false,seven=false,nine=false;
    for(int i=0;i<n;i++)
    {
        if(one && three && five && seven && nine) break;
    res*=i;
    if(res%i==0) 
    }

    cout<<1<<' ';
    if(d%3==0) cout<<3<<" ";
    if(d==5) cout<<5<<" ";
    if(d%7==0) cout<<7<<" ";
    if(d%9==0) cout<<9<<" ";
    cout<<'\n';
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