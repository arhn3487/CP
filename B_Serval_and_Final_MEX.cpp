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
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

void solve()
{
    int n,c=0,k=1;
    cin>>n;
    vector<int> v(n);
    vector<array<int,2>> ans;
    for(auto &i : v) {
        cin>>i;
        if(i==0) c++;
    }

    if(c==0)
    {
        cout<<1<<'\n'<<1<<" "<<n<<'\n';
        return;
    }
    if(c==n)
    {
        cout<<3<<'\n'<<1<<" "<<2<<'\n'<<2<<' '<<n-1<<'\n'<<1<<' '<<2<<'\n';
        return;
    }

    for(int i=0;i<n;i++)
    {
        if(v[i]==0)
        {
            if(i==n-1)
            {
                ans.push_back({k-1,k});
                break;
            }
            else
            {
                ans.push_back({k,k+1});
            }
            i++;
        }
    
        k++;
    }
    ans.push_back({1,k-1});

    cout<<ans.size()<<'\n';

    for(auto [a,b] : ans) cout<<a<<" "<<b<<'\n';
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