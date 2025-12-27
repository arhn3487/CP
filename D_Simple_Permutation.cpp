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

const int N=1e5+3;
vector<bool> is_prime(N,true);

void solve()
{
    int n;cin>>n;
    if(n<5)
    {
        for(int i=1;i<=n;i++) cout<<i<<' ';
        cout<<'\n';
        return;
    }
    vector<int> v;

    int start=n/2;
    int x=n/2;

    while(x!=1 && !is_prime[x]) x--;

    for(int i=1;i<=x;i++)
    {
      //  cout<<i<<'\n';
        v.push_back(2*x-i);
        if(i!=2*x-i)v.push_back(i);
    }

    for(int i=2*x;i<=n;i++) v.push_back(i);

    for(auto x : v) cout<<x<<' ';
    cout<<'\n';
    

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    is_prime[0]=is_prime[1]=false;

    for(int i=2;i*i<N;i++)
        if(is_prime[i])
            for(int j=i*i;j<N;j+=i)
                is_prime[j]=false;

    int t=1;
    cin>>t;

    for(int i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<": ";
        solve();
    }
}