#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;

ll sum(ll n)
{
    ll s=0;
    while(n)
    {
        s+=n%10;
        n/=10;
    }
    return s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        ll n,k;
        cin>>n;
        k=n;
        while(1)
        {
            //cout<<__
            if(__gcd(k,sum(k))>1) break;
            k++;
        }
        cout<<k<<endl;
    }
}