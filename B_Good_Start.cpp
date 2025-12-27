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
    int w,h,a,b,x1,x2,y1,y2;
    cin>>w>>h>>a>>b>>x1>>y1>>x2>>y2;

    bool f=false;

    if(x1!=x2 && (x1-x2)%a==0) f=true;
    if(y1!=y2 && (y1-y2)%b==0) f=true;

    if(f) YES
    else NO

    // if(x1>x2)
    // {
    //     swap(x1,x2);
    //     swap(y1,y2);
    // }

    // x1+=a;y1+=b;

    // if(abs(y2-y1)%b==0 && abs(x2-x1)%a==0) YES
    // else NO

    // x1+=a;

    // if(x1<=x2)
    // {
    //     if((x2-x1)%a==0) YES
    //     else NO
    //     return;
    // }

    // if(y1>y2)
    // {
    //     swap(y1,y2);
    //     //swap(x1,x2);
    // }

    // if(y1<=y2)
    // {
    //     if((y2-y1)%b==0) YES
    //     else NO
    //     return;
    // }

    // YES

    int valid_h1=b-max(0,y1),valid_h2=b-max(0,y2),valid_l1=a-max(0,x1),valid_l2=a-max(0,x2);

    // if(x2>=x1+a)
    // //if(valid_h1)
    // {
    //     if(x2==x1) YES
    //     // else if(valid_l2>=valid_l1+a) YES
    //     // else NO
    //     else if(x2>=x1+2*a) YES
    //     else NO
    // }
    // else if(y2>=y1+b)
    // {
    //     if(y2==y1) YES
    //     // else if(valid_h2>=valid_h1+b) YES
    //     // else NO
    //     else if(y2>=y1+2*b) YES
    //     else NO
    // }
    // else YES

    // if(x2>=a+x1)
    // {
    //     if(x2==x1) YES
    //     else if(x2>=x1+2*a) YES
    //     else NO
    // }
    // else if(y2>=b+y1)
    // {
    //     if(y2==y1) YES
    //     else if(y2>=y1+2*b) YES
    //     else NO
    // }
    // else YES
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