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
#define yes(x) cout << ((x) ? "Yes\n" : "No\n");

void solve()
{
    int n,x;
    string s;
    cin>>n>>x>>s;
    x--;
    int l1,l2=0,r1,r2=0,b1,b2;
    l1=x;

    for(int i=x+1;i<n;i++)
    {
        if(s[i]=='#')
        {
            l2=n-i;
            break;
        }
    }

    r1=n-x-1;

    for(int i=x-1;i>=0;i--)
    {
        if(s[i]=='#')
        {
            r2=i+1;
            break;
        }
    }
    //debug(l1,l2,r1,r2);
    cout<<max(min(l1,l2),min(r1,r2))+1<<'\n';
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