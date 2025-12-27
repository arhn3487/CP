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
    vector<ll> v(n);

    for(ll i=0;i<n;i++) cin>>v[i];

    for(ll i=0;i<n;i++)
    {
        bool flag = true;

        ll num = v[i];
        ll x=sqrt(num);

        if(x*x==num)
        {
            //cout<<num<<" "<<x<<endl;
            if(num==1 || x%2==0 && x!=2)
            {
                flag = false;
                //cout<<"ara"<<endl;
            }

            for(ll j=3;j*j<=x;j+=2)
            {
                if(x%j==0)
                {
                    flag = false;
                    break;
                }
            }
            //cout<<"arafat"<<endl;
            if(flag) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else cout<<"NO"<<endl;
    }
}