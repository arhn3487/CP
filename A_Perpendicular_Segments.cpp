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
        int x,y,k;
        cin>>x>>y>>k;

        //cout<<0<<" "<<y<<" "<<x<<" "<<y<<endl<<x<<" "<<0<<" "<<x<<" "<<y<<endl;
        cout<<"0 0 "<<min(x,y)<<" "<<min(x,y)<<endl;
        cout<<min(x,y)<<" "<<0<<" "<<0<<" "<<min(x,y)<<endl;
    }
}

/*
0 x
0 y
x 
*/