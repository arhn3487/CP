#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1)
    {
        ll n,ans=0;
        cin>>n;

        if(n==0) break;

        for(ll i=1;i<n;i++)
        {
            for(ll j=i+1;j<=n;j++)
            {
                ans+=__gcd(i,j);
            }
        }
        cout<<ans<<endl;
    }
}