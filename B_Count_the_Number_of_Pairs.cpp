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
    int n,k,cnt=0;
    string str;
    cin>>n>>k>>str;
    int upper[26]={},lower[26]={};

    for(auto ch : str)
    {
        if(ch<='z' && ch>='a') lower[ch-'a']++;
        else upper[ch-'A']++;
    }

    for(int i=0;i<26;i++)
    {
        int a=min(lower[i],upper[i]);
        if(lower[i]>0 && upper[i]>0) cnt+=a;
        lower[i]-=a;
        upper[i]-=a;
    }

    for(int i=0;i<26 && k;i++)
    {
        if(lower[i]>1 && k)
        {
            int a=min(lower[i]/2,k);
            cnt+=a;
            k-=a;
        }
        if(upper[i]>1 && k)
        {
            int a=min(upper[i]/2,k);
            cnt+=a;
            k-=a;
        }
    }

    cout<<cnt<<'\n';
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
