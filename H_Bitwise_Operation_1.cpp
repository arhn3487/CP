#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    int arr[n];
    ll ans=infinity;

    for(int i=0;i<n;i++) cin>>arr[i];

    for(ll i=0;i<(1ll<<n);i++)
    {
        ll tmp=i;
        ll s1=0,s2=0;

        for(int j=0;j<n;j++)
        {
            int rem=tmp%2;
            tmp/=2;
            if(rem) s1+=arr[j];
            else s2+=arr[j];
        }

        ans=min(ans,abs(s1-s2));
    }

    cout<<ans<<endl;
}