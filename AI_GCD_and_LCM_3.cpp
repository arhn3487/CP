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

    for(int j=1;j<=t;j++)
    {
        ll a,b,c,l;
        cin>>a>>b>>l;
        ll d=a*b/__gcd(a,b),ans=l/d;

        cout<<"Case "<<j<<": ";

        if(l%d==0)
        {
            vector<ll> v;

            for(ll i=2;i*i<=ans;i++)
            {
                if(ans%i==0)
                {
                    v.push_back(i);
                    while(ans%i==0) ans/=i;
                }
            }
            if(ans>1) v.push_back(ans);

            ans=l/d;

            for(auto it : v)
            {
                if(l%(ans*it)==0)
                {
                    while(l%(ans*it)==0) ans*=it;
                }
            }

            cout<<ans<<endl;
        }

        else cout<<"impossible"<<endl;
    }
}