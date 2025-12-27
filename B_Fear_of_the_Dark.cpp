#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

double dist(double x1,double y1,double x2,double y2)
{
    double x=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    double y=sqrt(x);
    return y;
}
    

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        double px,py,ax,ay,bx,by;
        cin>>px>>py>>ax>>ay>>bx>>by;

        double poss1=max(dist(0,0,ax,ay),dist(px,py,ax,ay));
        double poss2=max(dist(0,0,bx,by),dist(px,py,bx,by));
        double d1=min(poss1,poss2);

        double mid=dist(ax,ay,bx,by)/2.0;
        double ao=dist(0,0,ax,ay);
        double ap=dist(px,py,ax,ay);
        double bo=dist(0,0,bx,by);
        double bp=dist(px,py,bx,by);

        //debug(ap,ao,bp,bo);

        double x1=max(bo,ap),x2=max(bp,ao);
        double d2=max(min(x1,x2),mid);

        cout<<fixed<<setprecision(10)<<min(d1,d2)<<endl;
    }
}