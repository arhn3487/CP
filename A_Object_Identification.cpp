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

int ask(int i,int j)
{
    cout<<"? "<<i<<' '<<j<<endl;
    int a;cin>>a;
    return a;
}

void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    map<int,int> present;

    for(int i=0;i<n;i++) 
    {
        cin>>v[i]; 
        present[v[i]]=i+1;
    }

    for(int i=1;i<=n;i++)
    {
        if(!present[i])
        {
            int res=ask(i,(i==1) ? 2 : 1);
            if(res==0) cout<<"! A"<<endl;
            else cout<<"! B"<<endl;
            return;
        }
    }

    int res=ask(present[1],present[n]);
    int res2=ask(present[n],present[1]);
    if(res>n-1) cout<<"! B"<<endl;
    else if(res==n-1)
    {
        if(res2==n-1) cout<<"! B "<<endl;
        else cout<<"! A"<<endl;
    }
    else cout<<"! A"<<endl;
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