#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const ll M=1e9+7;
const ll infinity = LLONG_MAX;
ll dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
ll dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll sum=0,tw=0,n;
    cin>>n;
     vector<vector<ll>> v(n,vector<ll>(3));

    for(ll i=0;i<n;i++)
    {
        cin>>v[i][0]>>v[i][1]>>v[i][2];//uvc
    }

    sort(v.begin(),v.end(),[&](vector<ll> a,vector<ll> b)
    {
        return b[2]*a[0]>a[2]* b[0];
    });
    for(ll i=0;i<n;i++)

    {
        sum+=v[i][1]-v[i][2]*tw;
        tw+=v[i][0];
    }

    cout<<sum<<endl;
}