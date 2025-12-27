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

int n,ax=0,bx=0;
vector<int> a,b;

int check()
{
    //debug(a,b);
    ax=0,bx=0;
    for(int i=1;i<=n;i++)
    {
        ax=ax^a[i];
        //debug(ax);
    }
    for(int i=1;i<=n;i++) 
    {
        bx=bx^b[i];

    }

    //debug(ax,bx);
    if(ax==bx)
    {
        return 0;
    }


    if(ax)
    {
        if(a[n]!=b[n])
        {
            if(n&1) return 1;
            else return 2;
        }

        int k=(n%2) ? n :n-1;

        for(int i=k;i>=1;i-=2)
        {
            if(a[i]!=b[i])
            {
                return 1;
            }

            if(a[i-1]!=b[i-1])
            {
                return 2;
            }
        }

        return 1;
    }
    else
    {
        //cerr<<"BX\n";
        int k=(n%2==0) ? n : n-1;

        if(a[n]!=b[n])
        {
            if(n%2==0) return 2;
                //cout<<"Mai\n";
            else return 1;
            //cerr<<"BAL";
            //return;
        }

        //cerr<<k<<'\n';

        for(int i=k;i>=2;i-=2)
        {
            if(a[i]!=b[i])
            {
                //cout<<"Mai\n";
                return 2;
            }

            if(a[i-1]!=b[i-1])
            {
                //cout<<"Ajisai\n";
                return 1;
            }
        }

        //cout<<"Mai\n";
        return 2;
    }
}

void solve()
{
    cin>>n;
    a.clear();
    b.clear();
    ax=0,bx=0;
    a.resize(n+1);
    b.resize(n+1);

    vector<int> va(n+1),vb(n+1);

    for(int i=1;i<=n;i++) cin>>va[i];
    for(int i=1;i<=n;i++) cin>>vb[i];

    for(int i=25;i>=0;i--)
    {
        int mask=(1<<i);

        for(int j=1;j<=n;j++)
        {
            a[j]=(va[j]>>i) & 1LL;
            b[j]=(vb[j]>>i) & 1LL;
        }

        int res=check();
        if(res==1) 
        {
            cout<<"Ajisai\n";
            return;
        }
        else if(res==2) 
        {
            cout<<"Mai\n";
            return;
        }
    }

    cout<<"Tie\n";

    
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