#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:/debug.h"
#else
#define debug(x...)
#endif
using namespace std;

#define ll long long
#define ld long double
#define int long long
const int M=1e9+7;
const int N=1e6+5;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define yes(x) cout << ((x) ? "YES\n" : "NO\n");

array<int,2> primeFactorization(int n) { 
    int e=0,o=0;
    debug(n);
    while (n % 2 == 0) { 
        e+=2;
        n /= 2; 
    } 
 
    for (int i = 3; i * i <= n; i += 2) {  
        while (n % i == 0) { 
            o+=i;
            n /= i; 
        } 
    } 
 
    if (n > 2) 
        o+=n;

    return {e,o};
}

//e1+e2+e3+e4+o5+o6+o7<e1+e2+o3+o4+o5+o6+o7
//e3+e4<o3+o4
//e3-o3<o4-e4

bool comp(array<int,2> a,array<int,2>b)
{
    return (a[0]-a[1])<(b[1]-b[0]);
}

void solve()
{
    ll n,a,b,ans=infinity;cin>>n>>a>>b;
    vector<array<int,2>> v(n);

    for(int i=0;i<n;i++)
    {
        ll e=infinity,o=infinity,num;
        cin>>num;
        array<int,2> tmp=primeFactorization(num);
        v[i]=tmp;
    }
    
    sort(all(v),comp);
    debug(v);
    for(int i=1;i<n;i++)
        v[i][0]+=v[i-1][0];

    for(int i=n-2;i>=0;i--)
        v[i][1]+=v[i+1][1];
    
    for(int i=0;i<n-1;i++)
    {
        int o=i+1,e=n-o;
        if(e<a || o<b) continue;
        ans=min(ans,v[i][0]+v[i+1][1]);
    }


    cout<<ans<<'\n';

    debug(v);
}

int32_t main()
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