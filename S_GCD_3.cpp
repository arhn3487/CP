#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll x,y,a,b;
    cin>>a>>b>>x>>y;
    ll g =__gcd(x,y);
    x/=g,y/=g;
    ll k=min(a/x,b/y);
    //cout<<g<<endl;
    cout<<x*k<<" "<<y*k<<endl;
}