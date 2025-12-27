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

    int k,s,cnt=0;
    cin>>k>>s;

    for(int x=0;x<=k;x++)
    {
        for(int y=0;y<=k;y++)
        {
            int z=s-y-x;
            if(z>=0 && z<=k) 
            {
                //cout<<x<<" "<<y<<" "<<z<<endl;
                cnt++;
            }
        }
    }

    cout<<cnt<<endl;
}