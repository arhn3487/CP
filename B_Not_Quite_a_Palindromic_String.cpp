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
    int n,k,zvalid=0,ovalid=0,exz=0,exo=0;
    string str;
    cin>>n>>k>>str;

    for(int i=0;i<n/2;i++)
    {
        if(str[i]==str[n-i-1] && str[i]=='0') zvalid++;
        else if(str[i]==str[n-i-1] && str[i]=='1') ovalid++;
        else exz++ , exo++;
        //debug(exz,exo);
    }

    

    int ext=zvalid+ovalid-k,komano_possible=2*min(zvalid,ovalid),barano_possible=2*min(exz,exo);;

    //debug(exz,exo,zvalid,ovalid,komano_possible,ext);

    if(k==zvalid+ovalid) YES
    else if(ext>0 && ext%2==0 && ext<=komano_possible) YES
    else if(barano_possible+ovalid+zvalid>=k && k>ovalid+zvalid && (ext%2==0)) YES
    else NO
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