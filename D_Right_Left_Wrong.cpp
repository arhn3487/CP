#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
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
    t=1;
    cin>>t;

    while(t--)
    {
        ll n,sum=0,a;
        cin>>n;

        vector<ll> v(n+1,0);
        vector<char> v1(n+1,0);

        for(ll i=1;i<=n;i++)
        {
            cin>>a;
            v[i]=v[i-1]+a;
        }
        
        for(ll i=1;i<=n;i++) cin>>v1[i];
        ll i=1,j=n;

        while(i<j)
        {
            while(j>i && v1[j]!='R')
            {
                j--;
            }
            while(j>i && v1[i]!='L') i++;

            if(v1[i]=='L' && v1[j]=='R')
            {
                sum+=v[j]-v[i-1];
                j--;
                i++;
            }
        }
        cout<<sum<<endl;
    }
}