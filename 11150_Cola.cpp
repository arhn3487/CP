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

    int n,cnt=0,extra=0;
    //cin>>n;
    

   while(cin>>n)
   {
    cnt=n;
   
    while(n>2)
    {
        //n+=extra;
        //extra=0;
        cnt+=n/3;
        //extra=n%3;
        n=n/3+n%3;
        //cout<<cnt<<endl;
    }

    //cout<<n<<endl;
    if(n>=2) cnt++;

    cout<<cnt<<endl;
   }
}