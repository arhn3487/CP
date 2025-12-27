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
        ll n,cnt=0;
        cin>>n;

        for(ll i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                while(n%i==0) n/=i;
                cnt++;
            }
        }
        if(n>1) cnt++;

        if(cnt>1) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}