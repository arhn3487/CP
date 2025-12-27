#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const ll M=1e9+7;
const ll N=1e18+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,now=3,cnt=0,jog=4;
    cin>>n;
    cnt++;
    while(now+jog<n)
    {
        cnt=((cnt+now)%M+jog)%M;
        now+=jog;
        now%=N;
        jog+=2;
    }
    cout<<cnt<<endl;
}