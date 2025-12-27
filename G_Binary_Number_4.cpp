#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const ll M=1e16+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

//vector<ll> v(M);

ll f(ll x)
{
    if(x==0) return 0;
    ll p=0;
    if(x%2==0)
    {
        ll tmp=x,sum=0;
        while(tmp)
        {
            sum+=tmp%2;
            tmp/=2;
        }
        p= f(x-1)+sum;
    }
    else
    {
        p=2*f(x/2)+(x+1)/2;
    }

    //cout<<x<<" "<<p<<endl;

    return p;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll a,b;
    cin>>a>>b;

    //cout<<f(b)<<endl;

    cout<<f(b)-f(a-1);
}
