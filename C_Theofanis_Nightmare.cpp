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

    ll t;
    cin>>t;

    while(t--)
    {
        ll n;
        cin>>n;
        ll arr[n],pre[n+1]={0};

        for(ll i=0;i<n;i++) cin>>arr[i];

        for(ll i=n-1;i>=0;i--)
            pre[i]=pre[i+1]+arr[i];

        ll sum=pre[0];

        for(ll i=1;i<n;i++)
            if(pre[i]>0)sum+=pre[i];

        cout<<sum<<endl;
    }
}
