#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll N =998244353;

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

    //if(n==1) cout<<arr[0]%N<<endl;

    for(ll i=0;i<n-1;i++)
    {
        for(ll j=i+1;j<n;j++)
        {
            string s = to_string(arr[i])+to_string(arr[j]);
            res+=(stoll(s))%N;
        }
    }
    cout<<res<<endl;
}