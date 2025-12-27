#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        ll n,gcd=0;
        cin>>n;
        vector<ll> v(n),x;

        for(int i=0;i<n;i++) cin>>v[i];

        for(int i=0,j=n-1;i<n/2;i++)
        {
           gcd=__gcd(gcd,abs(v[i]-v[n-i-1]));
        }
        cout<<gcd<<endl;
    }
}