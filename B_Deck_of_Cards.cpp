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
    int n,k;
    string s,ans;
    cin>>n>>k>>s;
    ans=string(n,'+');

    int front=0,bottom=n-1,confused=0;

    for(int i=0;i<k;i++)
    {
        if(s[i]=='0') front++;
        else if(s[i]=='1') bottom--;
        else confused++;
    }

    //debug(front,bottom,confused);

    for(int i=0;i<front;i++) ans[i]='-';
    for(int i=n-1;i>bottom;i--) ans[i]='-';
    int baki_ase=count(all(ans),'+');
    if(baki_ase==confused)
    {
        for(int i=0;i<n;i++) cout<<'-';
        cout<<'\n';
        return;
    }

    for(int i=front,c1=confused;i<n && c1;i++,c1--) ans[i]='?';
    for(int i=bottom,c2=confused;i>=0 && c2;i--,c2--) ans[i]='?';
    cout<<ans<<'\n';
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