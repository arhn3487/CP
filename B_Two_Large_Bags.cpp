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
#define YES cout<<"Yes\n";
#define NO cout<<"No\n";

void solve()
{
    int n;
    cin>>n;
    unordered_map<int,int> freq;
    set<int> el;
    
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        freq[a]++;
        el.insert(a);
    }

    while(!el.empty())
    {
        int a=*el.begin();
        if(freq[a]==1)
        {
            NO
            return;
        }
        freq[a+1]+=freq[a]-2;
        el.erase(a);
        if(freq[a+1])el.insert(a+1);
        freq[a]=0;
    }
    YES
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