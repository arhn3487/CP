#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;

//ll lcm(ll x,ll y) return __gcd(x,y)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll a,b,cnt=0;
    cin>>a>>b;

    ll product=a*b;

    for(ll i=1;i*i<=product;i++)
    {
        if(product%i==0)
        {
            if(__gcd(i,product/i)==a ) cnt++;
        }
    }    

    cout<<2*cnt<<endl;
}