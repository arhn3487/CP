#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        ll n,s1=0,s2=0;
        cin>>n;

        for(ll i=1;i<n/2;i++) s1+=1ll<<i;
        s1+=1ll<<n;
        for(ll i=n/2;i<n;i++) s2+=1ll<<i;

        cout<<s1-s2<<endl;
    }
}