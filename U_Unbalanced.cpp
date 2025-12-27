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
#define yes(x) cout << ((x) ? "Yes\n" : "No\n");

void solve()
{
    string s;
    cin>>s;
    int n=s.length();

    for(int i=0;i<n-2;i++)
    {
        if(s[i]==s[i+1])
        {
            cout<<i+1<<' '<<i+2<<'\n';
            return;
        }
        if(s[i]==s[i+2])
        {
            cout<<i+1<<' '<<i+3<<'\n';
            return;
        }
    }

    if(s[n-2]==s[n-1]) cout<<n-1<<" "<<n<<'\n';
    else cout<<-1<<' '<<-1<<'\n';
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