#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const ll M=1e9+7;
const ll infinity = LLONG_MAX;
ll dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
ll dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin>>t;

    while(t--)
    {
        ll n,k,a,sum=0;
        cin>>n;
        vector<ll> v;

        for(ll i=0;i<n;i++)
        {
            cin>>a;
            v.push_back(a);
            sum+=a;
        }

        if(n<3) cout<<-1<<endl;
        else
        {
            sort(v.begin(),v.end());
            k=n/2+1;
            ll x=2*n*v[k-1]-sum+1;
            cout<<max(0LL,x)<<endl;
        }
    }
}