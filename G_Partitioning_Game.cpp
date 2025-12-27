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
const int N=10005;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define yes(x) cout << ((x) ? "Alice\n" : "Bob\n");

vector<int> grundy(N);

void sprudge_grundy(int n)
{
    grundy[1]=0;
    grundy[2]=0;

    vector<bool> vis(10005);

    for(int i=3;i<n;i++)
    {
        for(int j=1;2*j<i;j++)
        {
            vis[grundy[i]^grundy[i-j]]=true;
        }

        for(int j=0;j<=n;j++)
        {
            if(!vis[j])
            {
                grundy[i]=j;
                break;
            }
        }
    }
}

void solve()
{
    int n,ans=0;cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;cin>>a;
        ans^=grundy[a];
    }

    yes(ans)
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    cin>>t;

    sprudge_grundy(10002);

    for(int i=1;i<=t;i++)
    {
        cout<<"Case "<<i<<": ";
        solve();
    }
}