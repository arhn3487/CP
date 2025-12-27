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

mt19937 gen(time(0));

void solve()
{
    int n,p,need;cin>>n>>p;
    need=(n*p+100-1)/100;
    vector<array<int,2>> v(n);

    for(auto &[x,y] : v) cin>>x>>y;

    for(int i=0;i<1000;i++)
    {
        int it1=gen()%n,it2=gen()%n;
        while(it1==it2) it1=gen()%n,it2=gen()%n;

        ll a=v[it1][1]-v[it2][1],b=v[it2][0]-v[it1][0],c=v[it1][0]*v[it2][1]-v[it2][0]*v[it1][1];
        int cnt=0;

        for(auto [x,y] : v)
        {
            if(a*x+b*y+c==0) cnt++;
        }
        if(cnt>=need)
        {
            cout<<"Possible\n";
        }
    }

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