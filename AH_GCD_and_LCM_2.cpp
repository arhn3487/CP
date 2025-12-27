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
        ll n,flag=1;
        cin>>n;
        ll a[n],b[n+1];

        for(ll i=0;i<n;i++) {cin>>a[i];}
        b[0]=a[0];
        b[n]=a[n-1];

        for(int i=1;i<n;i++)
        {
            b[i]=(a[i-1]*a[i])/__gcd(a[i-1],a[i]);
        }

        for(int i=0;i<n;i++)
        {
            if(a[i]!=__gcd(b[i],b[i+1])) 
            {
                flag=0;
                break;

            }
        }

        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }
}