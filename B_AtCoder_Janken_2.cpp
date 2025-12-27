#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,a,sum=0;
    cin>>n;
    vector<string> v(n);
    
    for(ll i=0;i<n;i++)
    {
        cin>>v[i]>>a;
        sum+=a;
    }
    sort(v.begin(),v.end());
    cout<<v[sum%n]<<endl;
}