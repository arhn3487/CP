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

int ask(vector<int> &v)
{
    cout<<"? "<<v.size()<<' ';
    for(auto x : v) cout<<x<<' ';
    cout<<endl;
    int a;cin>>a;
    return a;
}

void solve()
{
    int n;
    cin>>n;
    vector<int> ans(2*n+1,-1),v1,v2;

    v1.push_back(1);

    for(int i=2;i<=2*n;i++)
    {
        v1.push_back(i);
        int a=ask(v1);
        if(a)
        {
            v2.push_back(i);
            v1.pop_back();
            ans[i]=a;
        }
    }

    for(int i=2*n;i>=1;i--)
    {
        if(ans[i]==-1)
        {
            v2.push_back(i);
            int a=ask(v2);
            v2.pop_back();
            ans[i]=a;
        }
    }

    cout<<"! ";
    for(int i=1;i<=2*n;i++) cout<<ans[i]<<' ';
    cout<<endl;
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