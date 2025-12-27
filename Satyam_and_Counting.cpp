#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int N=2*1e5+7;

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
        vector<bool> a(N,false),b(N,false);

        ll n,x,y,cnt=0,total=0,mx=0,lombo=0;
        cin>>n;
        //cin>>a;

        for(int i=0;i<n;i++)
        {
           cin>>x>>y;
           if(y==0) b[x]=true;
           else a[x]=true;
           mx=max({x,y,mx});
        }

        for(int i=0;i<mx+3;i++)
        {
            if(!a[i] &&!b[i]) continue;

            if(i)
            {
                if(b[i-1] && b[i+1] && a[i]) total++;
                if(a[i-1] && a[i+1] && b[i]) total++;
            }
            if(a[i] && b[i]) 
            {
                lombo++;
                // if(i)
                // {
                //     if(a[i-1] && a[i+1]) total++;
                //     if(b[i-1] && b[i+1]) total++;
                // }
            }

            //cout<<i<<" "<<total+lombo*(n-2)<<" "<<cnt<<endl;
        }

       // cout<<lombo<<" "<<total<<endl;

        cout<<total+lombo*(n-2)<<endl;

    }
}