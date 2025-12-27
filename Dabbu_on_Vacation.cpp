#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
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
    cin>>t;

    for(int i=0;i<t;i++)
    {
        double D,d,h,r,l;
        cin>>D>>d>>h;
        l=D-d;
        r=(D/2.0)*(D/2.0)-(D/2.0-l)*(D/2.0-l);

        double v1=((1.0)/(6.0))*3.1416*D*D*D,v2=3.1416*r*h;
        //cout<<v1<<" "<<v2<<endl;
        
        cout<<"Case "<<i+1<<": ";
        //cout<<(v1==v2)<<endl;
        if(abs(v1-v2)<0.002) cout<<"Yes\n";
        else cout<<"No\n";
    }
}