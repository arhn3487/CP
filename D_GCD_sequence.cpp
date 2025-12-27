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
        ll n,prev=0,flag=0;
        cin>>n;
        vector<ll> v(n),gcd(n-1);

        for(ll i=0;i<n;i++) cin>>v[i];

        for(ll i=0;i<v.size();i++)
        {
            ll a=__gcd(v[i],v[i+1]);
            cout<<a<<" "<<prev<<" "<<flag<<" "<<v[i]<<" "<<i<<" "<<i<<endl;
            if(a<prev)
            {
                if(flag==1) 
                {
                    flag=2;
                    break;
                }
                v.erase(v.begin()+i-1);
                i=-1;
                flag++;
                prev=0;
                break;
            }
            prev=a;
        }
        //else prev=a;

        if(flag==2) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}