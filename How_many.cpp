#include<bits/stdc++.h>
//#include "D:/debug.h"
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

    int s,t,cnt=0;
    cin>>s>>t;

    for(int a=0;a<=s;a++)
    {
        for(int b=0;b<=s-a;b++)
        {
            for(int c=0;c<=s-a-b;c++)
            {
                if(a*b*c<=t) cnt++;
            }
        }
    }

    cout<<cnt<<endl;
}