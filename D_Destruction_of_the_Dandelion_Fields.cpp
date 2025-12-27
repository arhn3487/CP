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
    ll sum=0;
    vector<int> even,odd;

    for(int i=0;i<n;i++)
    {
        int a;cin>>a;
        if(a%2) odd.push_back(a);
        else 
        {
            even.push_back(a);
            sum+=a;
        }
    }

    if(odd.empty())
    {
        cout<<0<<'\n';
        return;
    }

    sort(rall(odd));

    if(odd.size()%2) for(int i=0;i<=odd.size()/2;i++) sum+=odd[i];
    else for(int i=0;i<odd.size()/2;i++) sum+=odd[i];

    //for(int i=2;i<odd.size();i+=2) sum+=odd[i];

    cout<<sum<<'\n';
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