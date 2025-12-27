#include<bits/stdc++.h>
#include "D:/debug.h"
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
        int n,x,cnt=0;
        cin>>n>>x;

        for(int a=1;a<n;a++)
        {
            for(int b=1;a*b<n && a+b<x ;b++)
            {
                cnt+=min(((n-a*b)/(a+b)),x-a-b);
            }
        }

        cout<<cnt<<endl;
    }
}