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
const ll infinity = INT_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

vector<int>v;
int n,a,b,c;

int rec(int ind,int aa,int bb,int cc)
{
    if(ind==n)
    {
        if(min({aa,bb,cc})!=0)
        {
            return abs(aa-a)+abs(bb-b)+abs(cc-c)-30;
        }
        return infinity;
    }
    
    int w=rec(ind+1,aa,bb,cc);
    int x=rec(ind+1,aa+v[ind],bb,cc)+10;
    int y=rec(ind+1,aa,bb+v[ind],cc)+10;
    int z=rec(ind+1,aa,bb,cc+v[ind])+10;

    return min({w,x,y,z});
}

void solve()
{
    cin>>n>>a>>b>>c;
    v.resize(n);
    for(int i=0;i<n;i++) cin>>v[i];
 
    cout<<rec(0,0,0,0)<<'\n';
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