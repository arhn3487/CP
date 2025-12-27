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
    int n,x,cntz=0,cnto=0,cnt=0;
    string str;
    cin>>n>>x>>str;
    int arr[n]={},b[n]={},c[n]={};

    
    for(int i=0;i<n;i++)
    {
        char ch=str[i];
        ch=='0' ? cntz++ : cnto++;
        arr[i]=cntz-cnto;
        if(arr[i]==x) cnt++;
        //debug(cnt,cntz,cnto,arr[i]);
    }
    
    // for(auto x : arr) cout<<x<<' ';
    // cout<<'\n';


    int akta_par_hoile_bare=arr[n-1];
    if(akta_par_hoile_bare==0)
    {
        cout<<-1<<'\n';
        return;
    }
    int lagbe=x/akta_par_hoile_bare;


    //debug(akta_par_hoile_bare,lagbe);

    //cout<<lagbe<<'\n';

    if(arr[0]==arr[n-1])
    {
        if(x==0) cnt++;
        cout<<cnt<<'\n';
        return;a.
    }

    for(int i=0;i<n;i++)
    {
        b[i]=(lagbe-1)*akta_par_hoile_bare+arr[i];
        c[i]=lagbe*akta_par_hoile_bare+arr[i];
        if(b[i]==x) cnt++;
        if(c[i]==x) cnt++;
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