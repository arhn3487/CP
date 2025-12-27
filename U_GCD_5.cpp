#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,mx=-1;
    cin>>n;

    ll arr[n],left[n+1],right[n+1];
    
    for(ll i =0;i<n;i++) cin>>arr[i];

    left[0]=0,right[n]=0;

    for(int i=0;i<n;i++)
    {
        left[i+1]=__gcd(left[i],arr[i]);
    }
    for(int i=n;i>0;i--)
    {
        right[i-1]=__gcd(right[i],arr[i-1]);
    }

    for(int i=0;i<n;i++)
    {
        mx=max(__gcd(left[i],right[i+1]),mx);
    }

    /*for(int i=0;i<=n;i++) cout<<left[i]<<" ";
    cout<<endl;
    for(int i=0;i<=n;i++) cout<<right[i]<<" ";
    cout<<endl;*/

    cout<<mx<<endl;

}