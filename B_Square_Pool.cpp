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

void solve()
{
    ll n,s,cnt=0;cin>>n>>s;

    for(int i=0;i<n;i++)
    {
        bool possible=false;
        ll dx,dy,x,y;cin>>dx>>dy>>x>>y;
        if((dx==1 && dy==1) || (dx==-1 && dy==-1))
        {
            if(x==y) possible=true;
        }
        else if((dx==1 && dy==-1) || (dx==-1 && dy==1))
        {
            //cout<<i<<" "<<x<<" "<<y<<" "<<x+y<<"\n";
            if((x+y)==s) possible=true;
        }

        if(possible) cnt++;
        //debug(possible);    
    }

    

    cout<<cnt<<'\n';
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