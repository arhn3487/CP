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
    
    while(cin>>n)
    {
        ll tmp=n;
        for(ll i=2;i*i<=n;i++)
        {
            ll cnt=0;

            while(tmp%i==0)
            {
                tmp/=i;
                cnt++;
            }
            if(cnt)cout<<i<<"^"<<cnt<<" ";
        }
        if(tmp>1) cout<<tmp<<"^1";
        cout<<endl;
    }
}