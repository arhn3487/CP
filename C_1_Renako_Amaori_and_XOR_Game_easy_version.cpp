#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define debug(x...)
#endif
using namespace std;

#define ll long long
#define ld long double
#define int long long
const int M=1e9+7;
const int N=1e6+5;
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
    int n,ax=0,bx=0;cin>>n;
    vector<int> a(n+1),b(n+1);

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];ax=ax^a[i];
        //debug(ax);
    }
    for(int i=1;i<=n;i++) 
    {
        cin>>b[i];bx=bx^b[i];

    }

    //debug(ax,bx);
    if(ax==bx)
    {
        cout<<"Tie\n";
        return;
    }


    if(ax)
    {
        if(a[n]!=b[n])
        {
            if(n&1)
            cout<<"Ajisai\n";//odd
            else cout<<"Mai\n";
            return;
        }

        int k=(n%2) ? n :n-1;

        for(int i=k;i>=1;i-=2)
        {
            if(a[i]!=b[i])
            {
                cout<<"Ajisai\n";
                return;
            }

            if(a[i-1]!=b[i-1])
            {
                cout<<"Mai\n";
                return;
            }
        }

        cout<<"Ajisai\n";
        return;
    }
    else
    {
        //cerr<<"BX\n";
        int k=(n%2==0) ? n : n-1;

        if(a[n]!=b[n])
        {
            if(n%2==0)
                cout<<"Mai\n";
            else cout<<"Ajisai\n";
            //cerr<<"BAL";
            return;
        }

        //cerr<<k<<'\n';

        for(int i=k;i>=2;i-=2)
        {
            if(a[i]!=b[i])
            {
                cout<<"Mai\n";
                return;
            }

            if(a[i-1]!=b[i-1])
            {
                cout<<"Ajisai\n";
                return;
            }
        }

        cout<<"Mai\n";
        return;
    }
}

int32_t main()
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
        //cout<<'\n';
    }
}