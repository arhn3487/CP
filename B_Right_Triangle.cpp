#include<bits/stdc++.h>
#include "D:/debug.h"
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x1,x2,x3,y1,y2,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;

    int a=((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    int b=((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
    int c=((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
    if(a+b==c || b+c==a || c+a==b) cout<<"Yes\n";
    else cout<<"No\n";
}