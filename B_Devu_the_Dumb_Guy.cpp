#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,x,total=0;
    cin>>n>>x;
    vector<ll> v(n);

    for(ll i = 0;i<n;i++) cin>>v[i];

    sort(v.begin(),v.end());

    for(ll i=0;i<n;i++)
    {
        total+=x*v[i];
        if(x>1) x--;
    }

    cout<<total<<endl;
}