#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const ll M=1e9+7;
const ll infinity = LLONG_MAX;
ll dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
ll dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,base1,m,base2,d1=0,d2=0,p1=1,p2=1;
    

    cin>>n>>base1;
    ll a[n];

    for(ll i=0;i<n;i++) cin>>a[i];

    for(ll i=n-1;i>=0;i--)
    {
        d1+=a[i]*p1;
        p1*=base1;
    }

    cin>>m>>base2;
    ll b[m];

    for(ll i=0;i<m;i++) cin>>b[i];

    for(ll i=m-1;i>=0;i--)
    {
        d2+=b[i]*p2;
        p2*=base2;
    }

    //cout<<d1<<d2<<endl;

    if(d1==d2) cout<<"=\n";
    else if(d1>d2) cout<<">\n";
    else cout<<"<\n";
}