#include<bits/stdc++.h>
//#include "D:/debug.h"
using namespace std;

#define ll long long
const int M=1e9+7;
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};//Right,Down,Left,Up,Right-Up,Right-Down,Left-Up,Left-Down
int dy[]={0,-1,0,1,1,-1,1,-1};
inline ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

#define rall(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define print(x) cout<<x<<'\n';
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

void solve()
{
    long double x1,x2,x3,y1,y2,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;

    long long m1=(y2-y1)/(x2-x1),m2=(y3-y2)/(x3-x2);
    //cout<<(y3-y2)<<" "<<(x3-x2)<<'\n';
    //cout<<((y2-y1)/(x2-x1))<<endl;
   /// cout<<((y3-y2)/(x3-x2))<<endl;
    //long double 
    //cout<<m1<<" "<<m2<<endl;
    long long p = (y2-y1)*(x3-x2)-(x2-x1)*(y3-y2);
    if(p==0) print("TOUCH")
    else if(p<0)print("LEFT")
    else print("RIGHT")
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    cin>>t;

    for(int i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<": ";
        solve();
    }
}