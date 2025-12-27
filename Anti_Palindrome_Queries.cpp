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
    int n,q;
    cin>>n>>q;
    vector<int> one(n,0),two(n,0),three(n,0);

    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        if(a==1) one[i]++;
        else if(a==2) two[i]++;
        else three[i]++;
    }

    for(int i=1;i<n;i++) one[i]+=one[i-1];
    for(int i=1;i<n;i++) two[i]+=two[i-1];
    for(int i=1;i<n;i++) three[i]+=three[i-1];

    while(q--)
    {
        int l,r;
        cin>>l>>r;
        l--,r--;

        if((r-l+1)%2)
        {
            NO
            continue;
        }

        int arr[3];
        arr[0]=(l==0) ? one[r] : one[r]-one[l-1];
        arr[1]=(l==0) ? two[r] : two[r]-two[l-1];
        arr[2]=(l==0) ? three[r] : three[r]-three[l-1];

        sort(arr,arr+3);

        // for(auto x : arr) cout<<x<<' ';
        // cout<<'\n';

        if(arr[2]==(r-l+1)/2) YES
        else NO
    }
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