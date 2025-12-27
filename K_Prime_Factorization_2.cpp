#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,res=0;
    cin>>n;
    for(ll j=1;j<=n;j++)
    {
        ll tmp=j,t=j,x=0;
        for(ll i=2;i*i<=t;i++)
        {
            ll cnt=0;

            while(tmp%i==0)
            {
                tmp/=i;
                cnt++;
            }
            if(cnt)x++;
        }
        if(tmp>1) x++;
        if(x==2) res++;
    }
    cout<<res<<endl;
}