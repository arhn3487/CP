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
    int n;cin>>n;
    vector<int> v(n+1);

    for(int i=1;i<=n;i++) cin>>v[i];

    // int x=(((n-1)*-v[2])-((n-2)*-v[1]))/((n-2)-2*(n-1));
    // int y=((2*-v[1])-v[2])/((n-2)-2*(n-1));

    int y=(2*v[1]-v[2])/ (n+1),x=y-v[1]+v[2];
    //int y=(2*v[1]-v[2])/(n+1),x=y + (v[2]-v[1]);  // Corrected x

    //debug(x,y);

    if(x<0 || y<0)
    {
        NO
        return;
    }

    for(int i=1;i<=n;i++)
    {
        v[i]-=x*i+y*(n-i+1);
        if(v[i]!=0)
        {
            NO
           return;
        }
    }

    //debug(v);

    YES

    // set<int> y_lagbe;
    // int f=0;

    // for(int i=1;i<=n;i++)
    // {
    //     y_lagbe.insert((v[i]-v[0])/(n-i+1));
    //     if((v[i]-x)%(n-i+1)) f=1;
    // }

    // if(!f && y_lagbe.size()==0) 
    // {
    //     YES;
    //     return;
    // }

    // y_lagbe.clear();

    // for(int i=1;i<=n;i++)
    // {
    //     y_lagbe.insert((v[i]-x)/(n-i+1));
    //     if((v[i]-x)%(n-i+1)) f=1;
    // }
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