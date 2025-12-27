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
    int n;cin>>n;
    if(n<4) yes(0)
    else
    {
        yes(1)
        if(n%2)
        {
            cout<<"3 * 5 = 15\n4 * 2 = 8\n15 + 8 = 23\n23 + 1 = 24\n";
            int res=24;
            int l=6,r=n;

            while(l<n)
            {
                cout<<l+1<<" - "<<l<<" = 1\n";
                cout<<"1 * 24 = 24\n";
                l+=2;
            }
        }
        else
        {
            cout<<"4 * 3 = 12\n12 * 2 = 24\n24 * 1 = 24\n";
            int res=24;
            int l=5;
            while(l<n)
            {
                cout<<l+1<<" - "<<l<<" = 1\n";
                cout<<"1 * 24 = 24\n";
                l+=2;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    //cin>>t;

    for(int i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<": ";
        solve();
    }
}