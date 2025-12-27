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
        ll n,a,b,total=0,extra,f,r,n_r;
        cin>>n>>a>>b;
        //k=min(b,n);
        //ll first=b-k;
        //cout<<first<<endl;

        if(b<=a)
        {
            cout<<n*a<<endl;
        }
        else if(b-a>=a)
        else
        {
            // k-x=a
            ll k=b-a+1;
            ll index=k;
            ll required = n-k+1;
            //cout<<k<<" "<<required<<" "<<k<<" \n";
            k=b-k;
            ll x=b*(b+1)/2,y=(a*(a+1))/2,z=a*required;
            ll total=x-y+z;
            cout<<x<<" "<<y<<" "<<z<<" "<<k<<endl;
            cout<<total<<endl;
        }   
    }
}