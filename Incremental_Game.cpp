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

bool f;

bool rec(int x,int y,int k,int mov)
{
    if(f) return true;
    if(x==0 || y==0)
    {
        if(mov) f=true;
        return true; 
    }
    for(int i=k;i<=x;i++)
    {
        for(int j=k;j<=y;j++)
        {
           if(!f) 
           {
                rec(x-i,y,k+1,mov^1);
                rec(x,y-j,k+1,mov^1);
           }

        }
    }
    return true;
}

void solve()
{
    int x,y,k;
    cin>>x>>y>>k;

    rec(x,y,k,1);

    if(f) cout<<"Alice\n";
    else cout<<"Bob\n";
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