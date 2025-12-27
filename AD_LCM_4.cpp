#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll x;
    cin>>x;

    ll a=1,b=x;

    for(ll i=1;i*i<=x;i++)
    {
        if(x%i==0)
        {
            ll j=x/i;

            if(max(a,b)>max(i,j) && (((i*j)/__gcd(i,j))==x))
            {
                a=i,b=j;
            }
        }
    }
    cout<<a<<" "<<b<<endl;
}