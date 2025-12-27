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
    int n,m,cnt=0;
    cin>>n>>m;
    vector<pair<int,int>> v(n+2);
    v[0]={0,0};

    for(int i=1;i<=n;i++) cin>>v[i].first>>v[i].second;
    //v.push_back(n,)

    //debug(v);
    
    for(int i=1;i<=n;i++)
    {
        int p=v[i].first-v[i-1].first,q=(v[i].second==v[i-1].second) ? 1 : 0;

        if(q)
        {
            
            //cout<<p<<" ar "<<i<<" "<<'\n';
            if(p%2) p--;
            //cout<<p<<' '<<i<<" 1"<<'\n';
            cnt+=p;
        } 
        else 
        {
            
            if(p%2==0) p--;
            //cout<<p<<' '<<i<<'\n';
            cnt+=p;
        }

        //debug(cnt,p,q);
    }

    cnt+=m-v[n].first;

    print(cnt)
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