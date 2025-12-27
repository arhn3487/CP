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
    vector<int> v(n);

    for(auto &x : v) cin>>x;
    ll cnt[2]={0,0};

    for(int i=0;i<2;i++)
    {
        ll total=0;
        for(int j=0;j<n;j++)
        {
            total+=v[j];
            if((i+j)%2==0)
            {
                if(total>=0)
                {
                    cnt[i]+=llabs(total+1);
                    total=-1;
                }
            }
            else
            {
                if(total<=0)
                {
                    cnt[i]+=llabs(total-1);
                    total=1;
                }
            }
        }
    }

    cout<<min(cnt[0],cnt[1])<<'\n';
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