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
        ll x,y,k,total;
        cin>>x>>y>>k;

        ///total=2*max((x+k-1)/k,(y+k-1)/k);
        ll x_n=(x+k-1)/k,y_n=(y+k-1)/k;
        if(x_n>y_n) total=2*max(x_n,y_n)-1;
        else total=2*max(x_n,y_n);

        cout<<total<<endl;
    }
}