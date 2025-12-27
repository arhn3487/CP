#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        ll n;
        cin>>n;

        if(n==1) cout<<1<<'\n';
        else if(n<=4) cout<<2<<'\n';
        else
        {
           ll ager=3,cnt=2,cover=4;
           while(cover<n)
           {
                cover+=ager*2;
                ager*=2;
                cnt++;
           }
           cout<<cnt<<'\n';
        }
    }
}