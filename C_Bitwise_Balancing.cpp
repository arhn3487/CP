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

    map<tuple<int,int,int>,int> mp;
    mp[{0,0,0}]=0;
    mp[{0,0,1}]=1;
    mp[{0,1,0}]=0;
    mp[{0,1,1}]=-1;
    mp[{1,0,0}]=-1;
    mp[{1,0,1}]=1;
    mp[{1,1,0}]=1;
    mp[{1,1,1}]=0;

    while(t--)
    {
        ll b,c,d,a=0;
        cin>>b>>c>>d;

        for(int i=60;i>=0;i--)
        {
            int x=b>>i&1,y=c>>i&1,z=d>>i&1;
            int p=mp[{x,y,z}];
            if(p==-1)
            {
                a=-1;
                break;
            }
            else if(p)
            {
                a|=1LL<<i;
            }
        }

        cout<<a<<endl;
    }
}