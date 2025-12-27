#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;

bool is_prime(ll n)
{
    if(n%2==0) return false;
    for(ll i=3;i*i<=n;i+=2) if(n%i==0) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,tmp,cnt=0,ans=0;
    cin>>n;
    tmp=n;

    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            ll cnt=0;
            while(n%i==0)
            {
                n/=i;
                cnt++;
            }

            //cout<<cnt<<" "<<i<<endl;
            for(ll j=1;;j++)
            {
                if(cnt>=j) 
                {
                    ans++;
                    cnt-=j;
                }
                else break;
            }
        }
    }
    if(n>1)ans++;
    cout<<ans<<endl;
}