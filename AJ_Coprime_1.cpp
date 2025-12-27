#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin>>n;

    for(ll i =n/2;i>=1;i--)
    {
        if(__gcd(i,n-i)==1)
        {
            cout<<i<<" "<<n-i<<endl;
            return 0;
        }
    }
}