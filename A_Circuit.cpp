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
        int n,on=0,off=0,a,b;
        cin>>n;
        int arr[2*n];

        for(int i=0;i<2*n;i++)
        {
            cin>>arr[i];
            if(arr[i]) on++;
            else off++;
        }

        if(off==0) cout<<0<<" "<<0<<endl;
        else if(off>=on) cout<<off%2<<" "<<on<<endl;
        else cout<<on%2<<" "<<off<<endl;
    }
}