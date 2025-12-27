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
        ll n,sum=0,a,extra=0,flag=1;
        cin>>n;
        vector<ll> v(n),x(n,0),y;
        for(ll i=0;i<n;i++)
        {
            cin>>v[i];
            //sum+=v[i];
        }
        for(ll i=0;i<n;i++)
        {
            extra+=v[i];
            x[i]=i;
            extra-=i;
            if(extra<0)
            {
                flag=0;
                break;
            }
            //extra+=v[i]-i;
        }
        if(!flag) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
        
    }
}