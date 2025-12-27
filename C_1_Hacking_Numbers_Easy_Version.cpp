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

void digit()
{
    cout<<"digit"<<endl;
    int a;cin>>a;
}

bool div(int y)
{
    cout<<"div "<<y<<endl;
    int a;cin>>a;
    return a;
}

int add(int y)
{
    cout<<"add "<<y<<endl;
    int a;cin>>a;
    return a;
}

void solve()
{
    int n;cin>>n;
    digit();//0-81--79
    digit();//0-16
    add(-8);
    add(-4);
    add(-2);
    add(-1);
    add(n-1);
    cout<<"!"<<endl;
    cin>>n;
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