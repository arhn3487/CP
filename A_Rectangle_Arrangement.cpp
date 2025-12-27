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
        int n,mx=0,res=0;
        cin>>n;

        int w[n+1],h[n+1];
        h[0]=0,w[0]=0;


        for(int i=1;i<=n;i++) 
        {
            cin>>w[i]>>h[i];
        }

        sort(h,h+n+1);
        sort(w,w+n+1);

        res+=h[n]+w[n];

        for(int i=n;i>0;i--)
        {
            //cout<<w[i]<<" "<<h[i]<<endl;
            res+=w[i]-w[i-1];
            res+=h[i]-h[i-1];

            //cout<<res<<endl;
        }

        cout<<res<<endl;
    }
}