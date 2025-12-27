#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;

ll sum(ll n)
{
    ll s=0;
    //cout<<n<<endl;
    while(n)
    {
        s+=n%10;
        n/=10;
    }
    //cout<<s<<endl;
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
        ll n,sm=0,a;
        cin>>n;

        for(ll i=0;i<n;i++)
        {
            cin>>a;
            sm+=sum(a);
        }

        //cout<<sm<<endl;
        if(sm%3==0) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}