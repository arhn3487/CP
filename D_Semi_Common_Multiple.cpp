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
    int n,m,l=1;cin>>n>>m;
    set<int> st;

    for(int i=0;i<n;i++)
    {
        int a;cin>>a;
        a/=2;
        l=lcm(l,a);

        if(l>m || ((l/a)%2==0))
        {
            cout<<0<<'\n';
            return;
        }
        
        st.insert(a);
    }

    // if(st.size()==1)
    // {
    //     cout<<m+1<<'\n';
    //     //return;
    // } 
    // if(st.size()>2) 
    // {
    //     cout<<0<<'\n';
    //     return;
    // }

   int p=(*st.begin())/2,q=(*st.rbegin())/2;
   int a=1,cnt=0,k=(q-p)/2;
   debug(l);

   while(l*a<=m)
   {
        cnt++;
        a+=2;
   }

   //if(cnt) cnt++;

   cout<<cnt<<'\n';
}

int32_t main()
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