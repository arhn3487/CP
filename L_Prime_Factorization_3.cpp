#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;

ll sum(ll n)
{
    ll s=0;
    while(n)
    {
        s+=n%10;
        n/=10;
    }
    return s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,cnt=0,total;
    cin>>n;
    ll tmp=n;
    total=sum(n);
    for(ll i=2;i*i<=n;i++)
    {
        while(tmp%i==0)
        {
            tmp/=i;
            cnt+=sum(i);
        }
    }
    if(tmp>1) cnt+=sum(tmp);
    //cout<<cnt<<" "<<total<<endl;
    if(cnt==total) cout<<1<<endl;
    else cout<<0<<endl;
}