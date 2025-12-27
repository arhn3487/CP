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
        ll n,a,ans=0;
        vector<ll> v;
        cin>>n;
        //v.push_back(0);

        for(ll i=1;i<=n;i++)
        {
            cin>>a;
            if(abs(a-i)) v.push_back(abs(a-i));
        }

        ll len=v.size();

        for(ll i=0;i<len;i++)
        {
           ans=__gcd(ans,v[i]);
        }

        cout<<ans<<endl;
    }
}