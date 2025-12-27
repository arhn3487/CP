#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
long long dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
long long dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long t;
    cin>>t;

    while(t--)
    {
        long long n,s,m,u,v,cnt=0;
        cin>>n>>s>>m;
        bool flag=false;

        long long start=0;

        for(long long i=0;i<n;i++)
        {
            cin>>u>>v;
            if(u-start>=s) flag=true;
            start=v;
        }
        if(m-start>=s) flag=true;

        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
    }
}