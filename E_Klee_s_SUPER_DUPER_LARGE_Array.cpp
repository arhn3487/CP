#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    t=1;
    cin>>t;

    while(t--)
    {
        ll n,k;
        bool f=true;
        cin>>n>>k;

        auto sum=[&] (ll l,ll r)->ll
        {
            return (r*(r+1)/2)-(l*(l-1)/2)+k*(r-l+1);
        };

        ll start=0,end=n-1,mn=LONG_LONG_MAX;

        while(start<=end)
        {
            ll mid=(start+end)/2;
            ll x=sum(0,mid);
            ll y=sum(mid+1,n-1);

            mn=min(mn,abs(y-x));

            if(x<=y) start=mid+1;
            else end=mid-1;
        }

        cout<<mn<<endl;
        
    }
}