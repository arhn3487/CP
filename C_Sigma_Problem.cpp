#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll N =1e8;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,res=0;
    cin>>n;
    ll arr[n];

    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(ll i=0;i<n-1;i++)
    {
        for(ll j=i+1;j<n;j++)
        {
            res+=(arr[i]+arr[j])%N;
        }
    }
    cout<<res<<"\n";
}