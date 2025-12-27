#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    t=1;
    cin>>t;

    while(t--)
    {
        ll x,y,k,p,q;
        cin>>x>>y>>k;
        p=y,q=y;

        if(k%2)
        {
            cout<<x<<" "<<y<<endl;
            k--;
        }

        for(int i=0;i<k;i+=2)
        {
            cout<<x<<" "<<++p<<endl;
            cout<<x<<" "<<--q<<endl;
        }
    }
}