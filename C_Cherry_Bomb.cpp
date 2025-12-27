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
    int n,k,f_x=-1;
    bool f=false;
    cin>>n>>k;
    int left=INT_MIN,right=INT_MAX;
    vector<int> a(n),b(n);
    set<int> st;

    for(auto &x : a) cin>>x;
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
        int x=b[i];
        if(x!=-1) 
        {
            f=true;
            st.insert(a[i]+b[i]);
            f_x=a[i]+b[i];
            
        }
        
        if(x==-1)
        {
            left=max(a[i],left);
            right=min(right,k+a[i]);
        }
    }
    //cout<<f_x<<'\n';
    for(int i=0;i<n;i++)
    {
        if(f_x==-1) break;
        if(f_x-a[i]<0 || f_x-a[i]>k) 
        {
            // cout<<f_x-a[i]<<'\n';
            // cout<<"aaaaaaaaaaa\n";
            cout<<0<<'\n';
            return;
        }
    }
    //cout<<left<<" "<<right<<'\n';
    if(st.size()>1) cout<<0<<'\n';
    else if(f) cout<<1<<'\n';
    else if(left>right) cout<<0<<'\n';
    else cout<<right-left+1<<'\n';

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