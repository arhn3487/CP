#include<bits/stdc++.h>
//#include "D:/debug.h"
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
    int n,m,f=1;
    cin>>n>>m;

    vector<ll> a(n),b(m);

    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];

    sort(all(b));

    ll last =1e9+7;

    for(int i=n-1;i>=0;i--)
    {
        ll now=a[i];
        auto b_ = upper_bound(all(b),last);
        //cout<<b_-b.begin()<<'\n';
        if(b_==b.end())b_--;
        cout<<*b_<<endl;
        ll tmp=*b_-a[i];
        cout<<last<<" "<<now<<" "<<tmp<<'\n';
        if(now>last && tmp>last) 
        {
            f=0;
            cout<<"ARAFAT\n";
        }
        else if(now<=last && tmp<=last) last=max(now,tmp);
        else if(now<=last) last=now;
        else last = tmp;
        
        
        
    }

    // for(auto x : a) cout<<x <<" ";
    // cout<<'\n';

    if(f) YES
    else NO
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