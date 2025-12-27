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
#define yes(x) cout << ((x) ? "S\n" : "N\n");

void solve()
{
    int n,f=0;
    cin>>n;

    if(n==2)
    {
        int a;cin>>a;
        int arr[2]={0,0};
        vector<int> v,v2;

        for(int j=0;j<a;j++)
        {
            int k;cin>>k;
            v.push_back(k);
            arr[k-1]++;
        }

        cin>>a;
        for(int j=0;j<a;j++)
        {
            int k;cin>>k;
            v2.push_back(k);
            arr[k-1]++;
        }

        //cout<<arr[0]<<" "<<arr[1]<<'\n';

        
        
            //debug(v,v2);
        if(is_sorted(all(v)) && is_sorted(rall(v2))) f=1;
        
    }

    if(n!=2)f=1;

    
    for(int i=0;i<n;i++)
    {
        int a;cin>>a;
        for(int i=0;i<a;i++)
        {
            int k;cin>>k;
        }
    }

    yes(f)
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