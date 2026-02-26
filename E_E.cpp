#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
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
   int n,m,k,x,y=-1;cin>>n>>m>>k>>x;
   int lo=0,hi=1e9;
  

   while(lo<=hi)
   {
        int mid=(lo+hi)/2,p=mid-1;
        int nn=n*p+(p/k)*m,ww=n*mid+(mid/k)*m;
        //debug(nn,ww,mid);
        if(x>ww) lo=mid+1;
        else if(x<=nn) hi=mid-1;
        else
        {
            y=mid;
			//hi=mid-1;
            break;
        } 
   }
   //debug(y);
   yes(y%k==0 && y>0)
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
    }
}