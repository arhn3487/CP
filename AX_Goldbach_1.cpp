#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    bool f=true;
    cin>>n;

    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0) f=false;
    }
    //cout<<f<<endl;
    if(f) {cout<<1<<endl;return 0;}

    n-=2;
    f=true;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0 ) f=false;
    }
    if(f || n%2==0) {cout<<2<<endl;return 0;}
    else cout<<3<<endl;
}