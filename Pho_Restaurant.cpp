#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

void solve()
{
    int n,ok=0;
    cin>>n;
    vector<pair<ll,ll>> v(n);
    vector<int> o(n),z(n),prez(n+1,0),preo(n+1,0);  

    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        o[i]=count(all(str),'1');
        z[i]=str.length()-o[i];
        if(o[i]>0 && z[i]>0) ok=1;
    }

    if(!ok)
    {
        cout<<0<<'\n';
        return;
    }

    for(int i=0;i<n;i++)
    {
        v[i]={o[i]-z[i],z[i]};
    }

    sort(all(v));

    for(int i=1;i<=n;i++)
    {
        preo[i]=preo[i-1]+v[i-1].first+v[i-1].second;
        prez[i]=prez[i-1]+v[i-1].second;
    }

    int ans=INT_MAX;
    for(int i=1;i<n;i++)
    {
        ans=min(ans,preo[i]+prez[n]-prez[i]);
    }

    cout<<ans<<'\n';
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